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

int main()
{
	int t;
	sd(t);
	int in;
	rep(in,1,t+1)
	{
		char ans[500];
		int x,y;
		sd(x);
		sd(y);
		bool changed = false;
		if(y==0) { int temp = x;x=y;y=temp;changed = true; }
		int curr=1;
		int i=0;
		int cx=0;
		while(true)
		{
			if(curr==abs(y))
			{
				if(y>0) ans[i++]='N';
				else ans[i++]='S';
				curr++;
				break;
			}
			if(x>0)
			{
				if(curr%2==0) { cx+=curr;ans[i++]='E'; }
				else { cx-=curr;ans[i++]='W'; }
			}
			else
			{
				if(curr%2==0) { cx-=curr; ans[i++]='W'; }
				else {cx+=curr;ans[i++]='E'; }
			}
			curr++;
		}
		if(cx<x)
		{
			int j=0;
			while(true)
			{
				if(j%2==0)
				{
					cx-=curr;
					curr++;
					ans[i++]='W';
					if(cx==x) break;
				}
				else
				{
					cx+=curr;
					curr++;
					ans[i++]='E';
					if(cx==x) break;
				}
				j++;
			}
		}
		else if(cx>x)
		{
			int j=0;
			while(true)
			{
				if(j%2==0)
				{
					cx+=curr;
					curr++;
					ans[i++]='E';
					if(cx==x) break;
				}
				else
				{
					cx-=curr;
					curr++;
					ans[i++]='W';
					if(cx==x) break;
				}
				j++;
			}
		}
		ans[i]='\0';
		if(changed)
		{
			int j;
			rep(j,0,i)
			{
				if(ans[j]=='W') ans[j]='S';
				else if(ans[j]=='E') ans[j]='N';
				else if(ans[j]=='N') ans[j]='E';
				else if(ans[j]=='S') ans[j]='W';
			}
		}
		printf("Case #%d: %s\n",in,ans);
	}
	return 0;
}