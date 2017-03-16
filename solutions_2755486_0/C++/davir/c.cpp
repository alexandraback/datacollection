#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define ABS(a) (a>=0?a:-(a))
#define MIN(a,b) (a<=b?a:b)
#define MAX(a,b) (a>=b?a:b)
#define rep(a,b) for(a=0;a<b;a++)
#define rep1(a,b) for(a=1;a<=b;a++)
#define rep2(a,b,c) for(a=b;a<c;a++)
#define drep(a,b) for(a=b-1;a>=0;a--)
#define drep1(a,b) for(a=b;a>=1;a--)
#define drep2(a,b,c) for(a=b;a>=c;a--)
#define foreach(vec,it) for(vector<int>::iterator it = vec.begin();it!=vec.end();it++)
#define foreach2(co,ty,it,name) for(co< ty >::iterator it = name.begin();it!=name.end();it++)
#define pii pair<int,int>

#define NMAX 1024
int A[NMAX];
struct tribe
{
	int d,n,w,e,s,dd,dp,ds;
} T[1024];
int W[100024];
pii atk[1024];
bool cmp(pii p1, pii p2)
{
	return p1.first < p2.first;
}
void solve_problem()
{	
	int n, i, j, k;
	char c;
	int ans;
	for(i=0;i<100024;i++)
		W[i]=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d%d%d%d",&T[i].d,&T[i].n,&T[i].w,&T[i].e,&T[i].s,&T[i].dd,&T[i].dp,&T[i].ds);		
		T[i].w+=1024;
		T[i].e+=1024;
		atk[i].first = T[i].d;
		atk[i].second = i;
	}
	while(true)
	{
		sort(atk, atk+n, cmp);
		if(atk[0].first == INT_MAX) break;
		i = atk[0].second;		
		if(T[i].n<=0) 
		{
			atk[0].first=INT_MAX;
			continue;
		}
		bool flag = true;
		for(j=T[i].w;j<T[i].e;j++)
			if(W[j] < T[i].s)
			{
				W[j] = T[i].s;
				if(flag)
				{
					flag = false;
					ans++;
				}
			}
		T[i].n--;
		atk[0].first += T[i].dd;
		T[i].w+=T[i].dp;
		T[i].e+=T[i].dp;
		T[i].s += T[i].ds;
	}
	cout<<ans<<endl;
}

int main(void)
{
	int ct, tc;
	scanf("%d",&tc);	
	for(ct=1;ct<=tc;ct++)			
	{
//		cerr<<ct<<endl;
		printf("Case #%d: ", ct);	
		solve_problem();
	}
}
