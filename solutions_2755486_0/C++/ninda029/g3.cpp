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

struct data
{
	int d;
	int n;
	int w;
	int e;
	int s;
	int dd;
	int dp;
	int ds;
};

int main()
{
	int t;
	sd(t);
	int in;
	rep(in,1,t+1)
	{
		int arr[3000];
		int arr2[3000];
		int n;
		sd(n);
		data d[n];
		int i,j;
		rep(i,0,3000) { arr[i]=0;arr2[i]=0; }
		rep(i,0,n)
		{
			sd(d[i].d);
			sd(d[i].n);
			sd(d[i].w);
			sd(d[i].e);
			sd(d[i].s);
			sd(d[i].dd);
			sd(d[i].dp);
			sd(d[i].ds);
		}
		int cd=0;
		int coun=0;
		while(true)
		{
			rep(i,0,n) if(d[i].n!=0) break;
			if(i==n) break;
			rep(i,0,n)
			{
				if(d[i].d==cd && d[i].n!=0)
				{
					int t1;
					int sc=0;
					rep(t1,d[i].w,d[i].e+1) 
					{ 
						if(arr[t1+1000]<d[i].s){sc=1;}
						if(t1!=d[i].e)
						{
							if(arr2[t1+1000]<d[i].s){ sc=1; }
						}
					}
					if(sc==1) { coun++;}
				}
			}
			rep(i,0,n)
			{
				if(d[i].d==cd && d[i].n!=0)
				{
					int t1;
					int sc=0;
					rep(t1,d[i].w,d[i].e+1) 
					{ 
						if(arr[t1+1000]<d[i].s){sc=1;arr[t1+1000]=d[i].s; }
						if(t1!=d[i].e)
						{
							if(arr2[t1+1000]<d[i].s){ sc=1;arr2[t1+1000]=d[i].s; }
						}
					}
					d[i].d+=d[i].dd;
					d[i].w+=d[i].dp;
					d[i].e+=d[i].dp;
					d[i].s+=d[i].ds;
					d[i].n--;
				}
			}
			cd++;
		}
		printf("Case #%d: %d\n",in,coun);
	}
	return 0;
}