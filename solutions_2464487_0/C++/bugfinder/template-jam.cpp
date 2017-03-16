#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include<string>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define LL long long int
#define ULL unsigned long long int
#define S(n)                    scanf("%d",&n)
#define Sl(n)                     scanf("%lld",&n)
#define Sf(n)                     scanf("%lf",&n)
#define Ss(n)                     scanf("%s",n)
#define mod 1000000007
using namespace std;
/* template <class T>
inline void r_f(T &p)
{
         char c;
         while (((c=getchar_unlocked()) < 48)|(c > 57));
         p=c-48;
         while ((c=getchar_unlocked()) >= 48 && c <= 57) p=p*10+c-48;
} */
int main()
{
	int t,n,i,j,m,r,f;
	#ifndef ONLINE_JUDGE
    freopen("example.txt","r",stdin);
     freopen("mc.txt","w",stdout);
    #endif
	S(t);
	for(m=1;m<=t;m++)
	{
		int ct,sum;
		ct=0;
		sum=0;
		cout<<"Case #"<<m<<':'<<" ";
		S(r);
		S(f);
		for(i=r;i<=1000;i+=2)
		{
			j=i+1;
			int y;
			y=j*j - i*i;
			sum+=y;
			if(sum>f)
			break;
			ct++;
		}
		cout<<ct<<endl;
	}
	return 0;
}
