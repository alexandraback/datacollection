#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<bitset>
#include<time.h>
#define ll long long
#define inf 0x7FFFFFFF
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int k;
int s;
int l;
int number;
char get[100];
char c[100];
char chaos[100];
int num[1<<20];
void deal()
{
	int ans=0;
	for(int i=0;i+l<=s;i++)
	{
		int f=1;
		for(int j=i;j<i+l;j++)
        {
            if(c[j] != get[j-i])
            {
                f=0;
            }
        }
		ans+=f;
	}
	num[number++]=ans;
}
void solve(int x)
{
	if(x==s)
	{
	    c[s]=0;
		deal();
		return;
	}
	for(int i=0;i<k;i++)
	{
		c[x]=chaos[i];
		solve(x+1);
	}
}
int main()
{
	int i,j;
    int n,m,t;
    //srand((unsigned)time(NULL));//int data=rand()%10000+1;
    freopen("B-small-attempt1.in","r",stdin);freopen("B-output.txt","w",stdout);
	scanf("%d",&t);for(int tcase=1;tcase<=t;tcase++)
	{
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s%s",chaos,get);
		number=0;
		memset(num,0,sizeof(num));
		solve(0);
		int mmax=0;
		ll ans=0;
		for(i=0; i<number; i++)
		{
			ans+=num[i];
			mmax=max(mmax,num[i]);
		}
		double res=0.0;
		if(number)
        {
            res=mmax-(double)ans/number;
        }
		printf("Case #%d: %lf\n",tcase,res);
	}
}
