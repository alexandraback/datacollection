// This file was compiled using clang-503.0.40
// clang++ -o run.bin -std=c++11 task.cxx
// ./run.bin < data.in > data.out

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>

# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <queue>
# include <deque>
# include <stack>
# include <bitset>

# include <cstdio>
# include <cstdlib>
# include <ctime>
# include <climits>
# include <limits>
# include <cstring>
# include <cmath>

using namespace std;

bool valid_train2(vector<string> &vars, vector<int>& perm)
{
	bool is_valid = true;
	map<char, bool> used;
	
	char last = '0';
	for(int i=0; i<perm.size() && is_valid; ++i)
	{
		string &next = vars[perm[i]];
		for(int k=0; k<next.size() && is_valid; ++k)
		{
			if (last == next[k]) {
				// Do nothing
			}
			else 
			{
				if (used[next[k]] == true)
				{
					is_valid = false;
				}
				else {
					used[next[k]] = true;
					last = next[k];
				}
			}
		}
	}
	
	return is_valid;
}

bool valid_train(vector<string> &vars, vector<int>& perm)
{
	string str; str.reserve(100*20);
	for(int i=0; i<perm.size(); ++i)
	{
		str += vars[perm[i]];
	}
	
	string clean; clean.reserve(100*20);
	
	clean += str[0];
	for(int i=1; i<str.size(); ++i)
	{
		if (clean.back() != str[i]) {
			clean += str[i];
		}
	}
	
	set<char> uniq;
	for(int i=0; i<clean.size(); ++i) uniq.insert(clean[i]);
	
	//cout << endl << " !!! " << (uniq.size() == clean.size()) << endl;
	return (uniq.size() == clean.size());
}

int main()
{
	int T_inp; cin >> T_inp;
	for(int T=1; T<=T_inp; ++T)
	{
		int N; cin >> N;
		
		vector<string> vars(N);
		for(int i=0; i<vars.size(); ++i) {
			cin >> vars[i];
		}
		
		// Fast speed hack
		set<char> big;
		for(int i=0; i<vars.size(); ++i)
		{
			for(int k=0; k<vars[i].size(); ++k)
			{
				big.insert(vars[i][k]);
			}
		}
		if (vars.size() == 10 && big.size() == 1) {
			printf("Case #%d: %d\n", T, (int)3628800);
			continue;
		}
		// End
		
		vector<int> perm(N);
		for(int i=0; i<perm.size(); ++i) perm[i] = i;
		vector<int> orig(perm);
		
		int count = 0;
		do {
			next_permutation(perm.begin(), perm.end());
			count += (int) valid_train2(vars, perm);
			//break;
		} while (perm != orig);
		
		printf("Case #%d: %d\n", T, count);
	}
	return 0;
}