#include <bits/stdc++.h>

using namespace std;
#define MAX 300

int t,k,l,s;
string keybo,str;
int idx;
int vidx;
double dp[MAX][MAX];
double dp2[MAX][MAX];
int mark[MAX][MAX];
int mark2[MAX][MAX];
double prob[MAX];
int F[MAX];

// Pay attention! 
// the prefix under index i in the table above is 
// is the string from pattern[0] to pattern[i - 1] 
// inclusive, so the last character of the string under 
// index i is pattern[i - 1]   

void build_failure_function(string pattern)
{
  // let m be the length of the pattern 
	int m = pattern.size();
  F[0] = F[1] = 0; // always true
  
  for(int i = 2; i <= m; i++) {
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under  
    // index i - 1
    int j = F[i - 1];
    for( ; ; ) {
      // check to see if the last character of string i - 
      // - pattern[i - 1] "expands" the current "candidate"
      // best partial match - the prefix under index j
      if(pattern[j] == pattern[i - 1]) { 
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) { F[i] = 0; break; }
      // else go to the next best "candidate" partial match
      j = F[j];
    }
  }   
}

double solve2(int currs, int currstr)
{

	if (currs == s)
	{
		return 0;
	}

	double & ret = dp2[currs][currstr];
	if (mark2[currs][currstr] != -1)
	{
		return ret;
	}

	mark2[currs][currstr] = 0;
	ret = 0;
	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (i == str[currstr])
		{
			if (currstr + 1 == str.size())
			{
				ret = max(ret, solve2(currs + 1, 0) + 1);
			}
			else
			{
				ret = max(ret, solve2(currs + 1, currstr + 1));
			}
		}
		else
		{
			ret = max(ret, solve2(currs + 1, F[i]));
		}
	}


	return ret;
}
double solve(int currs, int currstr)
{

	if (currs == s)
	{
		return solve2(0,0);
	}

	double & ret = dp[currs][currstr];
	if (mark[currs][currstr] != -1)
	{
		return ret;
	}

	mark[currs][currstr] = 0;
	ret = 0;
	for (int i = 'A'; i <= 'Z'; ++i)
	{
		if (i == str[currstr])
		{
			if (currstr + 1 == str.size())
			{
				ret += (solve(currs + 1, 0) - 1) * prob[i];
			}
			else
			{
				ret += solve(currs + 1, currstr + 1) * prob[i];
			}
		}
		else
		{
			ret += solve(currs + 1, F[i]) * prob[i];
		}
	}

	return ret;
}

int main(void)
{
	cin >> t;
	int cases = 0;
	while (t--)
	{
		cases++;
		memset(mark, -1, sizeof mark);
		memset(mark2, -1, sizeof mark2);
		cin >> k >> l >> s;
		cin >> keybo;
		cin >> str;
		idx = 0;
		vidx = 1;

		build_failure_function(str);
		
		for (int i = 'A'; i <= 'Z'; ++i)
		{
			prob[i] = 0;
		}

		for (int i = 0; i < keybo.size(); ++i)
		{
			prob[keybo[i]] += (double)1.0/(double)k;
		}

		cout << "Case #" << cases << ": " << fixed << setprecision(7) << solve(0,0) << "\n";
	}
	return 0;
}