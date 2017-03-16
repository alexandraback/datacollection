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

#define NMAX 1000024
int A[NMAX];
int a, n;
int solve(int p, int pre)
{
	if(p==n) return pre;
	int ub = MIN(pre+n-p,n);
	int ret = pre;
	while(a<=A[p])
	{
		a+=a-1;
		ret++;
		if(ret>=ub) return ub;
	}
	a+=A[p];
	return solve(p+1, ret);
}
void solve_problem()
{	
	int i, j, k;
	char c;
	int ans;
	scanf("%d%d",&a,&n);	
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	sort(A,A+i);
	ans=solve(0,0);
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
