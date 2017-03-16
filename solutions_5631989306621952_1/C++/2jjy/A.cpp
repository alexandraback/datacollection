#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
char input[1002];
void task()
{
	scanf("%s",&input[1]);
	int n=strlen(&input[1]);
	string res;
	rep(i,n)
	{
		if(input[i]+res>res+input[i])
		{
			res=input[i]+res;
		}
		else
		{
			res+=input[i];
		}
	}
	cout<<res<<endl;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d: ",i);
		task();
	}
}
	
