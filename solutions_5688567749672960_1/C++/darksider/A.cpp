#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define clear(a) memset((a),0,sizeof(a))
#define pb push_back
#define SIZE(v) v.size()
#define ull unsigned long long int
#define lli long long int
#define li long int
#define ii int
#define mod 1000000007
/* Created by : Rahul Johari
				Thapar University */
				
#define lim 1111111    

lli a[lim];
 
inline lli pal ( lli x )
{
  	lli y = 0;
   	while ( x>0 )
   	{
   		y = y*10 + (x%10);
   		x /= 10;
   	}
   	return y;
}
 
queue<lli>Q;

int main()
{
  	freopen("A-large.in","r",stdin);
	freopen("1-L.txt","w",stdout);

   	a[1] = 1;
   	Q.push(1);

   	while ( !Q.empty() )
   	{
   		lli x = Q.front();
   		Q.pop();
		
   		if ( x+1<lim and a[x+1] == 0 )
   		{
   			a[x+1] = a[x] + 1;
   			Q.push(x+1);
   		}
   		if ( pal(x)<lim and a[pal(x)] == 0 )
   		{
   			a[pal(x)] = a[x] + 1;
   			Q.push(pal(x));
   		}
   	}
   	
   	lli t,N,cse;
	scanf("%lld",&t);
   	
	for ( cse=1;cse<=t;cse++ )
   	{
   		scanf("%lld",&N);
   		printf("Case #%lld: %lld\n",cse,a[N]);
 	}
	return 0;
}
