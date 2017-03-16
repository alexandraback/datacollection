#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <string.h>
#include "windows.h"
using namespace std;
#pragma comment(linker, "/STACK:20000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "B-large(1)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}

long long dp[55][2][2][2];

string a,b,k;

long long go(int p, int ea, int eb, int ek)
{
	if (p==sz(a)) return ea+eb+ek==0;
	if (dp[p][ea][eb][ek]!=-1) return  dp[p][ea][eb][ek];

	long long res = 0;

	int m1 = 1;
	if (ea) m1 = a[p]-'0';

	int m2 = 1;
	if (eb) m2 = b[p]-'0';

	for (int i=0;i<=m1;i++)
	for (int j=0;j<=m2;j++)
	{
		int v = i&j;
		if (!ek)
			res+=go(p+1,ea&&(i==a[p]-'0'),
			eb&&(j==b[p]-'0'),0); else
		{
			if (v==1 && k[p]=='0') continue;
			res+=go(p+1,ea&&(i==a[p]-'0'),
				eb&&(j==b[p]-'0'),(v==k[p]-'0'));
		}
	
	}



	return dp[p][ea][eb][ek] = res;
}

string conv(long long n)
{
	string res = "";
	for (int i=0;i<40;i++)
	{
		if ((1ll<<i)&n) res=string(1,'1')+res; else
			res=string(1,'0')+res;
	}

	return res;
}

int main()
{
   init();


	int tst;
	scanf("%d",&tst);
	
	for (int cas = 1; cas<=tst;cas++)
	{
		long long res = 0;

		memset(dp,-1,sizeof(dp));
	
		int A,B,K;
		scanf("%d%d%d",&A,&B,&K);
		a = conv(A);
		b = conv(B);
		k = conv(K);

		res = go(0,1,1,1);

					
		printf("Case #%d: %lld\n",cas, res);	
	}


	


	
  return 0;
}

