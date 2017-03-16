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

string problem_name = "A-large(2)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}

long long rev(long long val)
{
	long long res = 0;

	while (val)
	{
		res = res*10 + val%10;
		val/=10;
	}
	return res;
}

int dp[1000100];
int oo = 1ll<<29;

int main()
{
   init();


	for (int i=2;i<=1000000;i++)
		dp[i] = oo;
	dp[1]  = 1;

	for (int i=2;i<=1000000;i++)
	{
		dp[i] = dp[i-1] + 1;
		if (i%10) {
		long long val = rev(i);
		dp[i] = min(dp[i],dp[val]+1);	
		}
	}

	
   int tst;
   //scanf("%d",&tst);
   cin >> tst;

   for (int cas = 1; cas<=tst;cas++)
   {
	      
	   long long n;
	   cin >> n;
	   long long res = 0;

	   long long p = 1;
	   long long t = n;
	   while (t)
	   {
			p*=10;
			t/=10;
	   }
	   p/=10;

	   while (n>1000000)
	   {
			long long val = (n/p)*10 + n%10;
			res+=dp[val]-10;
			res+=n%p + 1;
			res-=n%10;
			n = p-1;
			p/=10;	   
	   }  
   
	   res+=dp[n];

	   printf("Case #%d: %lld\n",cas,res);	
   }
	





	
  return 0;
}

