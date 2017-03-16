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
       for(int z = 1 ; z <= t ; z++ )
       {
         vector< pair< int , pair < int , PII > > > v ; 
         int n ; 
         n = GI ; 
         
         VI wall(1001, 0) ; 
         
         for(int i = 0 ; i < n ; i++ )
         { 
                 int in[8] ;
                 for(int j = 0 ; j < 8 ; j++ )
                 cin >> in[j] ; 
                 
                 for(int j = 0 ; j < in[1] ; j++ )
                 { 
                         v.PB( MP( in[0] + j*in[5] , MP( in[4] + j*in[7] , MP( in[2] + j*in[6] , in[3] + j*in[6] )  ) ) ) ; 
                 }
                 
         }
         
         sort(v.begin() , v.end() ) ; 
         int res = 0 ; 
         int x = 0 ; 
         for(int i = 0 ; i < v.size() ; i++ )
         { 
          //cout << v[i].X << " " << v[i].Y.X << " " << v[i].Y.Y.X << " " << v[i].Y.Y.Y << " " << res << endl ; 
          
                 for(int j = v[i].Y.Y.X ; j < v[i].Y.Y.Y ; j++ )
                 if( wall[ j + 300 ] < v[i].Y.X) 
                 {res++ ; break ; }
                 
                 //Update
                 if( i != v.size()-1 &&  v[i].X != v[i+1].X )
                 {
                     for(int k = x ; k <= i ; k++ )
                     for(int j = v[k].Y.Y.X ; j < v[k].Y.Y.Y ; j++ )
                     wall[j+300] = max( wall[j+300] , v[k].Y.X ) ; 
                     
                     x = i ; 
                 }
                 //cout << res << endl ; 
                 //system("pause");
         }
         printf("Case #%d: ", z ) ;
         cout << res << endl  ;
         
       }
   return 0;
}

