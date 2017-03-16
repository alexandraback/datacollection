#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <memory.h>
#include <cassert>
#include <time.h>
using namespace std;
#pragma comment(linker, "/STACK:20000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "C-small-attempt1";

void init(){
  freopen((problem_name+".in").c_str(),"rt",stdin);
  freopen((problem_name+".out").c_str(),"wt",stdout);
}

string mas[521199];
char st[1110];
string s;

int dp[4100][7];
int n=521196;

int go(int p, int pred)
{
	if (pred>6) pred=6;
	if (p==sz(s)) return 0;
	if (dp[p][pred]!=-1) return dp[p][pred];
	int  res=100;

	for (int i=0;i<n;i++)
		if (p+sz(mas[i])<=sz(s))
		{
			int v=6;
			int cur=0;
			int ok=1;
			int pr=pred;
			for (int j=0;j<sz(mas[i]);j++) {
				if (mas[i][j]!=s[p+j])
				{
					if (v<5) 
					{
						ok=0;
						break;
					}
					if (pr<5) 
					{
						ok=0;
						break;
					}
					cur++;
					v=0;
				}
				v++;
				pr++;
			}
			v=min(v,pr);
			if (ok)
				res = min(res,go(p+sz(mas[i]),v)+cur);
		}


	return dp[p][pred]=res;
}

int main()
{

  

	freopen("garbled_email_dictionary.txt","rt",stdin);

	for (int i=0;i<521196;i++)
	{
		gets(st);
	//	puts(st);
		mas[i]=st;
	}
	fclose(stdin);

	 init();

	int tst;
	scanf("%d\n",&tst);

	for (int cas=1;cas<=tst;cas++) 
	{
		
		gets(st);
		s=st;
		memset(dp,-1,sizeof(dp));
		int res = go(0,56);
	
		printf("Case #%d: %d\n",cas,res);
	}




	return 0;
}
