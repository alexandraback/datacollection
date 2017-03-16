#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <limits>

using namespace std;

#define FOR(I,A,B) for(int I= (A); I<(B); ++I)
#define REP(I,N) FOR(I,0,N)
#define LL long long
#define S(N) scanf("%d", &N)
#define SL(N) scanf("%lld", &N)
#define PB push_back
#define MP make_pair
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define cell pair<int,int>
#define edge pair<int, cell>
#define clear(x) memset(x,0,sizeof(x))
#define CHECK_BIT(var,pos) ((var) & (1<<(pos))
#define sp system("pause")
typedef vector<int> vi;
typedef vector<LL> vii;
cell dir[4]={cell(0,1), cell(1,0), cell(0,-1), cell(-1,0) };

int arr[100001], k[1000001];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output3.txt","w",stdout);
    int t; S(t);
    int idx = 0;
    while(t--)
    {
              int i, sz, n;
              S(sz); S(n);
              REP(i, n) S(arr[i]);
              sort( arr, arr+n);
              if(sz == 1)
              {
                   cout<<"Case #"<<++idx<<": "<<n<<endl;
                   continue;
              }
		      int count=0, ans=n;
		      for(i=0; i<n; i++)
              {
                      while(arr[i] >= sz)
			          {
                                    count++;
				                    sz=2*sz-1;
                       }
			           k[i] = count + n-i-1;
			           if(k[i] < ans) ans=k[i];
           	           sz = sz + arr[i];
              }
              cout<<"Case #"<<++idx<<": "<<ans<<endl;
    }
    return 0;
} 
    
