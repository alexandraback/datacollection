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
int e,r,n,ma;
int v[100]; 
int dp[11][11];
int func(int x,int y,int z)
{
                   if(x==n)
                   {
                             ma=max(ma,z);
                             return 0;          
                   }
                      
                   for(int i=0;i<=y;i++)
                   {
                                         if((y-i+r)<=e)
                                         func(x+1,(y-i)+r,z+v[x]*i);        
                                         else
                                         func(x+1,e,z+v[x]*i);
                   }
                   
                   return 0;
}
int main()
{
	int t,i,j,m,f;
	#ifndef ONLINE_JUDGE
    freopen("example.txt","r",stdin);
    freopen("mc.txt","w",stdout);
    #endif
	S(t);
	for(m=1;m<=t;m++)
	{
		
		cout<<"Case #"<<m<<':'<<" ";
		 cin>>e>>r>>n;
                    
                            for(int i=0;i<n;i++)
                            cin>>v[i];
                            ma=0;
                            func(0,e,0); 
                            cout<<ma<<endl;
	}
	return 0;
}
