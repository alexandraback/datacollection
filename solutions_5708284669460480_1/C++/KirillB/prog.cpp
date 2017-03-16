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

string problem_name = "B-large(2)";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}

double dp[111][111];
int dpm[111][111];

int oo = 1<<29;
int w;
string keys;
string s;
int n;

int p[10001];
char st[211];
void kmp()
{
	p[0]=0;
	for (int i=1;i<=210;i++)
	{ 
		int len=p[i-1];
		while (len && st[len]!=st[i]) 
			len=p[len-1];
		if (st[len]==st[i]) len++;
		p[i]=len;
	}
}

string L;

double go(int v, int c)
{
	if (v>=n) return 0;
	if (dp[v][c]>-0.1) return dp[v][c];
	double res = 0;

	int pos = sz(L) + c + 1;
	char tmp = st[pos];

	for (int i=0;i<sz(keys);i++)
	{		
		st[pos] = keys[i];	

		int len=p[pos-1];
		while (len && st[len]!=st[pos]) 
			len=p[len-1];
		if (st[len]==st[pos]) len++;
		
		st[pos] = tmp;
		if (sz(L)==len)
		{			
			res+= 1.0/sz(keys)*(1+go(v+1,len));
			dpm[v][c] = max(dpm[v][c], 1 + dpm[v+1][len]);
		} else {
			res+= 1.0/sz(keys)*(go(v+1,len));
			dpm[v][c] = max(dpm[v][c], dpm[v+1][len]);
		}
		
	}


	return dp[v][c] = res;
}



int main()
{
   init();


	
	
   int tst;
   //scanf("%d",&tst);
   scanf("%d\n",&tst);

   for (int cas = 1; cas<=tst;cas++)
   {
	      
	   int k,l,s_;
	   scanf("%d%d%d\n",&k,&l,&s_);
	   gets(st);
	   keys = st;

	   gets(st);
	   s = st;
	   L = s;
	   st[sz(s)]='#';

	   n=s_;

	   for (int i=0;i<sz(s);i++)
		   st[sz(s)+i+1] = s[i];

	   kmp();

	   for (int i =0;i<111;i++)
		   for (int j =0;j<111;j++)
			   dp[i][j] = -1;

	   memset(dpm,0,sizeof(dpm));

	   double res =go(0,0);
   
	   printf("Case #%d: %.9lf\n",cas,dpm[0][0] - res);	
   }
	





	
  return 0;
}

