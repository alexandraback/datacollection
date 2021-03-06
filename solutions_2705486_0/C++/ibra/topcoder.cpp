#include <stdio.h>
#include<vector>
#include<iostream>
#include <math.h>
#include <algorithm>
#include<cstring>
#include<ctime>
#include<set>
#include <queue>
#include<map>
#include<string>
using namespace std;
const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull; 
int nextint(){int a;scanf("%d",&a);return a;}
ll nextll(){ll a;scanf("%lld",&a);return a;}
double nextdouble(){double a;scanf("%lf",&a);return a;}

class String
{
public:

	int read()
	{
		memset(str, 0, sizeof str);
		int ret = scanf("%s", str);
		sz = strlen(str);
		return ret;
	}

	int size()
	{
		return sz;
	}

	char str[64];
	int sz;
} tmp;
vector<String> words;
int dp[64][128];

bool isOk(int i, int j, int ii, int &changes, int &nj)
{
	int last = -1000;
	changes = 0;
	nj = j;
	for(int p = 0; p < words[ii].size(); p++)
	{
		if(words[ii].str[p] != tmp.str[i-words[ii].size()+1+p])
		{
			changes++;
			if(i-words[ii].size()+1+p-last < 5)
				return false;
			last = i-words[ii].size()+1+p;
			if(nj == j) nj = last;
		}
	}
	return j-last >= 5;
}

int solve(int i, int j)
{
	if(dp[i][j] == -1)
	{
		dp[i][j] = 1<<20;
		int changes, nj;
		for(int ii = 0; ii < words.size(); ii++)
			if(words[ii].size() <= i+1 && isOk(i, j, ii, changes, nj))
				dp[i][j] = min(dp[i][j], changes+solve(i-words[ii].size(), nj));
	}
	return dp[i][j];
}

int main()
{
	freopen("words.txt", "r", stdin);
	int cc = 0;
	for(int i = 0; i < 521196; i++)
	{
		tmp.read();
		words.push_back(tmp);
	}

	freopen("C-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		memset(dp, -1, sizeof dp);

		tmp.read();
		
		printf("Case #%d: %d\n", test, solve(tmp.size()-1, 120));
		cerr << ".";
	}

	return 0;
}