#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <functional>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <unordered_set>
using namespace std;
#define MODULUS 1000000007

int factorial(int a)
{
	int ret_val = 1;
	for(int b = 1; b <= a; b++)
	{
		ret_val *= b;
	}
	return ret_val;
}
bool test_valid(string str)
{
	unordered_set<char> list_all;
	char last_char = '-';
	for(auto it : str)
	{
		if (!list_all.count(it))
		{
			list_all.insert(it);
		}
		else
		{
			if (last_char != it)
			{
				return false;
			}
		}
		last_char = it;
	}
	return true;
}
struct train
{
	train(string T)
	{
		start = T.front();
		terminal = T.back();
		int loc = 0 ;

		while (T[loc ] == start)
		{
			loc++;
		}
		int loc_end = T.size() - 1;
		while(T[loc_end] == terminal && loc_end >= loc)
		{
			loc_end--;
		}
		for(int a = loc; a <= loc_end ; ++a)
			inners.insert(T[a]);
	}
	char start, terminal;
	unordered_set<char> inners;
};

int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	ofstream fout("output.txt");
	
	if(!fin.good())
	{
		cout << "opps" << endl;
	}

	string str;
	getline(fin, str);
	
	//	Number of test cases.
	const int T = atoi(str.c_str());

	//	Loop across each file.
	for( int aaa = 0; aaa < T ; aaa++)
	{
		getline(fin, str);
		istringstream iss(str);

		//	getline(fin, str);		iss.clear(); iss.str(str);
		//	 Data
		int N;
		iss >> N;
		getline(fin, str);
		iss.clear(); iss.str(str);
		vector<string> str_list;
		vector < int> order;
		vector< train> train_list;
		//	Load them to a string.
		for( int bbb = 0 ; bbb < N ; bbb++)
		{
			string tmp;
			iss >> tmp;
			str_list.push_back(tmp);

			train temp_train(tmp);
			train_list.push_back(temp_train);
		}

		//	Test to see if any middles overlap:
		bool able(true);
		for(int a = 0; a < train_list.size(); ++a)
		{
			for(int b = 0; b < train_list.size(); ++b)
			{
				if (a != b )
				{
					if (train_list[a].inners.count(train_list[b].start) || (train_list[a].inners.count(train_list[b].start) ))
					{
						able = false;
					}

				}
			}

		}
		//if (!able)
		//{
			//fout << "Case #" << aaa+1 << ": " << "0"<< endl;
		//}

		int total = 0;


		//	Find all the "free points";
		vector<bool> freedom(N, false);
		for(int a = 0 ; a < N ; ++a)
		{
			if (train_list[a].start == train_list[a].terminal)
			{
				freedom[a] = true;
			}
		}


		//	If valid path exists:
		for(int a = 0; a < N; ++a)
		{
			if(!freedom[a])
			{
				int count_links = 0;
				for(int b = 0; b < N; ++b)
				{
					if(a != b && !freedom[b] && train_list[a].terminal == train_list[b].start)
					{
						count_links++;
					}
				}
				if (count_links > 1)
				{
					break;
					able = false;
				}
			}
		}

		vector<int> groups(N,-1);
		int group_count = 0;
		for(int a = 0; a < N; ++a)
		{
			if(groups[a] == -1)
			{
				groups[a] = group_count;
				for(int b = 0 ; b < N; ++b)
				{
					if (a!=b )
					{
						if(
							train_list[a].terminal == train_list[b].start ||
							train_list[a].start == train_list[b].terminal)
						{
							if(groups[b] == -1)
							{
								groups[b] = groups[a];
							}
						}

					}
				}

				bool updates (true);
				while(updates)
				{
					updates = false;
					for(int b = 0; b < N ;++b)
					{
						for (int c = 0 ; c < N ; ++c)
						{
							if (b !=c)
							{
								if(groups[c] != groups[a])
								{
									if(train_list[b].terminal == train_list[c].start ||
										train_list[c].terminal == train_list[b].start )
									{
										groups[c] = groups[a];
										updates = true;
									}
								}
							}
						}
					}
				}
				group_count++;
			}
		}
		for(int a = 0; a < group_count; ++a)
		{
			//	check for loops in groups:
			int step_count = 0;
			int b = 0;
			while (b < N)
			{

				if(groups[b] == a)
				{
					while(step_count < N)
					{
						step_count++;
						int next = -1;
						for(int c =0 ; c < N; ++c)
						{
							if(train_list[b].terminal == train_list[c].start)
							{
								next = c;
								break;
							}
						}
						if(next == -1)
						{
							break;
						}
					}
				}
				b++;
			}
			if (b >= N)
				able = false;

		}
		cout << "print groups";
		for(auto it : groups)
			cout << it << " ";
		cout << endl;

		vector<int> links(N);
		//	We can use the non-free points to join things:
		if(able){
			for ( int a = 0; a < N ; ++a)
			{
				if (!freedom[a])
				{
					//	Find point it must link to.
					for(int b =0 ; b < N ; ++b)
					{
						if(a != b && 
								!freedom[b] && 
								train_list[a].terminal == train_list[b].start)
						{
							links[a] = b;
						}
					}
				}
			}
		}
		for(auto it : links)
			cout << it << " ";
		cout << endl;
		for (auto it: freedom)
			cout << it << " ";
		cout << endl;
		

		cout << group_count << endl;
		int sol = factorial(group_count) % MODULUS;
		cout << "sol: " << sol << endl;;
		for(int a = 0; a < group_count; a++)
		{
			int count_freedom = 0;
			for(int b = 0  ; b < N; b++)
			{
				if(groups[b] == a && freedom[b] )
				{
					count_freedom++;
				}
			}
			cout << count_freedom <<" " << sol << endl;
			sol *= factorial(count_freedom);
			sol %= MODULUS;
		}
		//unsigned long long int total(0);
		//do 	{
			////cout << perm++ << endl;;
			////	Test if valid.
			////	Create master string:
			//string main_str;
			//for(auto it: order)
				//main_str.append(str_list[it]);


			////	Test if valid.
			//if(test_valid(main_str))
				//total++;

		//}
		//while(next_permutation(order.begin(), order.end()));
		//cout << perm << endl;;


		int fin_ans(sol);
		if(able)
			fout << "Case #" << aaa+1 << ": " << fin_ans % 1000000007 << endl;
		else
			fout << "Case #" << aaa+1 << ": " << "0" << endl;
		//fout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<double>(prob)<< setprecision(10) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
