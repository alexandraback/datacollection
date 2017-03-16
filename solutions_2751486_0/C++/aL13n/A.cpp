/*
ID: akshitpoddar
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
#define MOD 1000000007
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
       for(int z  =1 ; z <= t ; z++ ) 
       {
                 St s ; 
                 
                 cin >> s; 
                 int  n; 
                 n = GI ; 
                 VI arr( s.length() + 1, 0 ) ; 
                 
                 for(int i = 1 ; i <= s.length() ; i++ )
                 {       
                         if(  !(s[i-1] == 'a' || s[i-1] == 'e' || s[i-1] == 'i' || s[i-1] == 'o' || s[i-1] == 'u' ) )
                         arr[i] = arr[i-1] + 1;
                         //cout << arr[i] << endl ; 
                 }
                 int res = 0 ; int mn = 0 ; 
                 for(int i = 1 ; i <= s.length() ; i++ )
                 { 
                         if( arr[i] >= n ) 
                         mn = i ; 
                         if( mn >= n ) 
                         res += (mn - n + 1) ;
                 }
                 printf("Case #%d: ", z ) ; 
                 cout << res << endl ; 
                         
       }
   return 0;
}

