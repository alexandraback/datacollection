#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int n;
vector < pair < double, int> > v, ans;
long double sum, good;
long double fine;
map < int , double > mp;
long double get_ans(int T)
{
	long double temp = good - v[T].first;
	return 100.0 * temp / sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);        
	int test_count;
	cin >> test_count;
	for (int test = 1 ; test <= test_count; test++)
	{
		cin >> n;
		v.clear();
		ans.clear();
		mp.clear();
		sum = 0;	
		for (int i = 0 ; i < n; i++)
		{
			double temp;
			cin >> temp;
			v.push_back(make_pair(temp, i + 1));
			sum+= temp;
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		good = sum * 2 / v.size();
		bool check = true;
		double bad_sum = sum;
		long double good_count = 0;
		for (int i = 0 ; i < v.size(); i++)
		{
			if (get_ans(i) < 0)
			{
				mp[v[i].second] = 0.0;
				bad_sum -= v[i].first;
				good_count += 1;
				good = (sum + bad_sum)/ (v.size() - good_count );
			}
			else
				mp[v[i].second] = get_ans(i);
		}

		cout << "Case #" << test << ':' << ' ';
		for (int i = 0 ; i  <v.size(); i++)
		{
			printf("%.9lf ", mp[i + 1]);
		}
		cout << '\n';
	}

    return 0;
}