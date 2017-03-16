#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define sd(i) scanf("%d",&i)
#define sll(i) scanf("%lld",&i)
#define sull(i) scanf("%llu",&i)
#define sc(i) scanf("%c",&ch)
#define sstr(i) scanf("%s",i)
#define pd(i) printf("%d",i)
#define pll(i) printf("%lld",i)
#define pull(i) printf("%llu",i)
#define pc(i) printf("%c",i)
#define pstr(i) printf("%s",i)
#define newline printf("\n")
#define itoa(i,j) sprintf(i,"%d",j)
#define rep(i,j,n) for(i=j;i<n;i++)
#define ull unsigned long long
#define ll long long


void readline(char *str)
{
	char ch;
	sc(ch);
	int i=0;
	while(ch != '\n') {str[i++]=ch;sc(ch);}
	str[i]='\0';
}

int solve(int i,int *arr,int coun,int curr,int n)
{
	while(i<n)
	{
		if(arr[i]<curr) curr+=arr[i];
		else
		{
			if(curr+curr-1>arr[i])
			{
				coun++;
				curr+=curr-1+arr[i];
			}
			else 
			{
				int c1 = coun+n-i;
				while(arr[i]>=curr)
				{
					curr+=curr-1;
					coun++;
				}
				curr+=arr[i];
				if(coun<c1)
				{
					coun = solve(i+1,arr,coun,curr,n);
				}
				return min(c1,coun);
			}
		}
		i++;
	}
	return coun;
}

int main()
{
	int t;
	sd(t);
	int in;
	rep(in,1,t+1)
	{
		int curr;
		sd(curr);
		int n;
		sd(n);
		int arr[n];
		int i;
		rep(i,0,n) sd(arr[i]);
		sort(arr,arr+n);
		if(curr==1) printf("Case #%d: %d\n",in,n);
		else printf("Case #%d: %d\n",in,solve(0,arr,0,curr,n));
	}
	return 0;
}