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
       int t;
       S(t);
       for(int z = 1 ; z<= t ; z++ )
       {
                 LL r , t ; 
                 S(r) ; S(t) ;
                 LL res = -1 ; 
                 LL s = 0 ; 
                 
                 //r++ ;
                 
                 while( s <= t ) 
                 { 
                   res++ ;
                   s += (r+1)*(r+1) - r*r ; 
                   r+=2 ;
                   //cout << s << " " << res << endl ;
                 }
                 
                 printf("Case #%d: %lld\n",z,res) ;
       }
   return 0;
}
