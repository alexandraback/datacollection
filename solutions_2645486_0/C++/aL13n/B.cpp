/*
ID: akshitp1
PROG:
LANG: C++
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<bitset>
#include<fstream>
#include<set>
#include<map>

#include<algorithm>
#include<cmath>
using namespace std;


// Definitions

#define LL long long int
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<LL>
#define VII vector< vector<int> >
#define VLL vector< vector<LL> >
#define VP vector< PII >
#define S(a) scanf("%lld",&a)
#define St string
#define X first
#define Y second
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define GI ({int t;scanf("%d",&t); t;})
#define gcd(a,b) __gcd(a,b)

void Print (int *arr, int sz)
{
	int i = 0;
	while (i < sz)
	{
		printf("%d ",arr[i++]);
	}
	printf("\n");
}

// Main Code


void init()
{
   }


int solve()
{
   return 0;
   }

int main()
{
       init();
       LL t;
       S(t);
       for(int z = 1 ; z<= t ; z++ )
       {
                 int n , e , r ; 
                 e = GI ; 
                 r = GI ; 
                 n = GI ; 
                 
                 VII dp(n+2, VI(e+r+1,0)) ;
                 
                 for(int i = 0 ; i < n ; i++ )
                 { 
                   int x = GI ; 
                   
                   for(int j = 0 ; j <= e ; j++ )
                   { //dp[i+1][j] = max( dp[i+1][j] , dp[i][j] ) ; 
                     for(int k = 0 ; k <= j ; k++ )
                     { 
                       if( j - k + r <= e ) 
                       dp[i+1][j-k+r] = max( dp[i][j] + k*x , dp[i+1][j-k+r] ) ; 
                       else
                       dp[i+1][e] = max( dp[i][j] + k*x , dp[i+1][e] ) ; 
                     }
                   }
                 }
                 
                 int res = 0 ; 
                 for(int i = 0 ; i <= e ; i++ )
                 res = max( res , dp[n][i] ) ;
                 
                 printf("Case #%d: %d\n",z,res) ;   
       }
   return 0;
}
