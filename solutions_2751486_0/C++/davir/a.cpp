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

#define NMAX 1024
int A[NMAX];
int count(char *s, int b, int e, int n)
{
	int acc=0;
	for(int i=b;i<=e;i++)
	{
		if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
			acc++;
		else
			acc=0;
		if(acc>=n)
			return 1;
	}
	if(acc>=n)
		return 1;
	return 0;
}
void solve_problem()
{	
	int n, i, j, k;
	char s[1024];
	scanf("%s %d",s,&n);	
	int ans=0;
	for(i=0;s[i];i++)
		for(j=i;s[j];j++)
			ans+=count(s,i,j,n);
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
