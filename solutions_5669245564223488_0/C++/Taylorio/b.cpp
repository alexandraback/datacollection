#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

void print_args(){}

template <typename T, typename... Args>
void print_args(const T & val, Args... args)
{
	cout << val << " ";
	print_args(args...);
}

template <typename... Args>
void print_case(int test_case, Args... args)
{
	cout << "Case #" << test_case << ": ";
	print_args(args...);
	cout << endl;
}

typedef long long int lli;
const lli MOD = 1e9 + 7;

bool ok(const string & car, int car_num, const vector<set<char>> & letters)
{
	if( car.size() > 2 )
	{
		// check same car
		for(size_t n = 0; n < car.size(); n++)
		{
			for(size_t m = n+1; m < car.size(); m++)
				if( car[n] == car[m] )
					return false;
		}
		// check other cars
		for(size_t n = 1; n < car.size()-1; n++)
		{
			for(size_t m = 0; m < letters.size(); m++)
			{
				if( m == car_num )
					continue;
				else if( letters[m].count(car[n]) > 0 )
					return false;
			}
		}
	}
	return true;
}

void merge_singletons(list<pair<char,char>> & car_ends, map<char,lli> & num_merged )
{
	for(auto it = car_ends.begin(); it != car_ends.end(); ++it)
	{
		if( it->first != it->second )
			continue;
		auto sit = it;
		sit++;
		for(; sit != car_ends.end();)
		{
			if( sit->first == sit->second && sit->first == it->first )
			{
				if( num_merged.find(sit->first) == num_merged.end() )
					num_merged[sit->first] = 2;
				else
					num_merged[sit->first]++;
				sit = car_ends.erase(sit);
			}
			else
				++sit;
		}
	}
}

void merge_singletons_mixed(list<pair<char,char>> & car_ends)
{
	for(auto it = car_ends.begin(); it != car_ends.end(); ++it)
	{
		if( it->first == it->second )
			continue;
		for(auto sit = car_ends.begin(); sit != car_ends.end();)
		{
			if( (sit->first == sit->second) && (sit->first == it->first || sit->first == it->second) )
				sit = car_ends.erase(sit);
			else
				++sit;
		}
	}
}

bool mixed_ok(const list<pair<char,char>> & car_ends)
{
	map<char,int> start_count;
	map<char,int> end_count;
	for(auto it = car_ends.begin(); it != car_ends.end(); ++it)
	{
		if( it->first != it->second )
		{
			start_count[it->first]++;
			end_count[it->second]++;
		}
	}
	for(auto p : start_count)
	{
		int ec = end_count[p.first];
		if( (ec > 1 || p.second > 1) || (ec + p.second > 2) )
			return false;
	}
	// check reversed pairs
	for(auto it = car_ends.begin(); it != car_ends.end(); ++it)
	{
		auto sit = it;
		sit++;
		for(; sit != car_ends.end(); ++sit)
			if( it->first == sit->second && it->second == sit->first )
				return false;
	}
	return true;
}

bool merge_mixed(list<pair<char,char>> & car_ends)
{
	for(auto it = car_ends.begin(); it != car_ends.end();)
	{
		if( it->first == it->second )
		{
			it++;
			continue;
		}
		bool found = false;
		for(auto sit = car_ends.begin(); sit != car_ends.end(); ++sit)
		{
			if( sit->first == sit->second )
			{
				continue;
			}
			if( it->first == sit->second )
			{
				if( it->second == sit->first )
					return false;
				found = true;
				sit->second = it->second;
				it = car_ends.erase(it);
				break;
			}
			else if( it->second == sit->first )
			{
				sit->first = it->first;
				it = car_ends.erase(it);
				found = true;
			}
		}
		if( !found )
			it++;
	}
	return true;
}

lli fac_mod(lli num)
{
	lli ret = 1;
	for(lli n = 2; n <= num; n++)
		ret = (ret * n) % MOD;
	return ret;
}

int main()
{
	int num_cases;
	cin >> num_cases;
	for(int c = 0; c < num_cases; c++)
	{
		int num_cars;
		cin >> num_cars;
		list<string> cars;
		vector<set<char>> letters(num_cars);
		for(int n = 0; n < num_cars; n++)
		{
			string tmp;
			cin >> tmp;
			cars.push_back(tmp);
			for(char c : tmp)
				letters[n].insert(c);
		}
		// initial check
		int car_num = 0;
		bool possible = true;
		lli acc = 1;
		for(string & car : cars)
		{
			string tmp = "";
			char last = '.';

			// remove adjacent duplicates
			for(size_t n = 0; n < car.size(); n++)
			{
				if( last != car[n] )
					tmp += car[n];
				last = car[n];
			}

			car = tmp;

			if( !ok(car, car_num, letters) )
			{
				print_case(c+1, 0);
				possible = false;
				break;
			}

			car_num++;
		}
		/*cout << "after removed adjacent " << endl;
		for(auto car : cars)
			cout << car << endl;
		cout << "=========" <<endl;*/

		list<pair<char,char>> car_ends;
		for(const auto & car : cars)
			car_ends.push_back( make_pair(car.front(), car.back()) );

		/*cout << "car ends" << endl;
		for(auto p : car_ends)
			cout << p.first << " " << p.second << endl;
		cout << "=========" <<endl;*/

		map<char,lli> num_merged;
		if( possible )
		{
			merge_singletons(car_ends, num_merged);
			//cout << "ACC " << acc << endl;

			/*cout << "after merge singletons" << endl;
			for(auto p : car_ends)
				cout << p.first << " " << p.second << endl;
			cout << "=========" <<endl;*/

			merge_singletons_mixed(car_ends);

			/*cout << "after merge singletons, mixed" << endl;
			for(auto p : car_ends)
				cout << p.first << " " << p.second << endl;
			cout << "=========" <<endl;*/

			if( !mixed_ok(car_ends) )
			{
				print_case(c+1, 0);
				possible = false;
			}
			if( possible && !merge_mixed(car_ends) )
			{
				print_case(c+1, 0);
				possible = false;
			}

			/*cout << "after merge mixed" << endl;
			for(auto p : car_ends)
				cout << p.first << " " << p.second << endl;
			cout << "=========" <<endl;*/

			if( possible && !mixed_ok(car_ends) )
			{
				print_case(c+1, 0);
				possible = false;
			}
		}
		if( possible )
		{
			lli ans = fac_mod(car_ends.size());
			for(auto p : num_merged)
				ans = (ans * fac_mod(p.second)) % MOD;
			print_case(c+1, ans);
		}
	}
	return 0;
}
