/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807


//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
	ll y=((((tp*)a)->w)-(((tp*)b)->w));
	if(y>0)return 1;
	else if(y==0)return 0;
	else return -1;
}*/



int a[1010];

int main()
{	
	int t,i,j,k;
	si(t);
	for(k=1;k<=t;k++)
	{
		int d;
		si(d);
		for(i=0;i<d;i++)
			si(a[i]);
		int ans,ans1;
		for(i=1;i<=1000;i++)
		{
			ans=i;
			for(j=0;j<d;j++)
			{
				if(a[j]>i)
				{
					if(a[j]%i==0)
						ans+=(a[j]/i-1);
					else
						ans+=(a[j]/i);
				}
			}
			if(i==1)
				ans1=ans;
			else
				ans1=min(ans1,ans);
		}
		cout<<"Case #"<<k<<": "<<ans1<<endl;
	}
	return 0;
}
