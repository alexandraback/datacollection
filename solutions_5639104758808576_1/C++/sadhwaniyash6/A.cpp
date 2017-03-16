/*
***************************************************************************************************************

							Author : Yash Sadhwani

					//credits to shalin shah...............copied his solution,made some changes and submitted
					//exam tomorrow so dint have much time

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


int main()
{
	int t,i,j,k;
	si(t);
	for(j=1;j<=t;j++)
	{
		int n;
		si(n);
		string s;
		cin>>s;
		int ans=0,currentAudience=0;
		if(s[0]=='0')
		{
			ans++;
			currentAudience++;
		}
		else
			currentAudience+=(s[0]-'0');
		for(i=1;i<=n;i++)
		{
			if(currentAudience>=i)
			{
				currentAudience+=(s[i]-'0');
			}
			else
			{
				ans+=(i-currentAudience);
				currentAudience+=(i-currentAudience+s[i]-'0');	
			}
		}
		cout<<"Case #"<<j<<": "<<ans<<endl;
	}
	return 0;
}
