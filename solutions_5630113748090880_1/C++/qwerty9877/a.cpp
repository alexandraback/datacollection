#include "bits/stdc++.h"
using namespace std;
#define LIM
#define MOD
#define gc                       getchar_unlocked
#define ll                       long long
#define pb                       push_back
#define fi                       first
#define se                       second
#define mp                       make_pair
#define TA(a,n)                  for(int i=0;i<n;i++)  cout<<a[i]<<" "; cout<<endl;
#define TM(a,n,m)                for(int i=0;i<n;i++) { for(int j=0;j<m;j++)  cout<<a[i][j]<<" "; cout<<endl; }
#define TP(a,n)                  for(int i=0;i<n;i++)  cout<<a[i].first<<" "<<a[i].second<<endl;
#define all(v)                   v.begin(),v.end()
#define uniq(v)                  sort(all(v));  v.erase(unique(all(v)),v.end())
#define FOR(i,n,m)               for(int i=0;i<n;i+=m)
#define For(i,n,m)               for(int i=1;i<=n;i+=m)
#define CB(value)                __builtin_popcount(value)
#define TB0(value)               __builtin_ctz(value)
#define LB0(value)               __builtin_clz(value)
#define clr(x,val)               memset(x,val,sizeof(x))
#define __                       int t; scanf("%d",&t); while(t--)
const double pi=acos(-1.0);
template<typename T> T gcd(T a, T b) {if(!b) return a;return gcd(b, a % b);}
template<typename T> T lcm(T a, T b) {return a * b / gcd(a, b);}
int arr[3001];
int main(){
  //ios_base::sync_with_stdio(false); cin.tie(NULL);
  #ifdef DEBUG
    freopen("E:\CodeStack\input.txt", "w", stdout);
    assert(freopen("E:\CodeStack\output.txt", "r", stdin));
  #endif
   int t1=1;
  __{
        int n;
		clr(arr,0);
		cin>>n;
		FOR(i,2*n-1,1)
		{
			FOR(j,n,1)
			{
			    int temp;
				cin>>temp;
				arr[temp]++;
			}
		}
		cout<<"Case #"<<t1++<<": ";
		FOR(i,3000,1)
		{
			if(arr[i]%2==1)
			{
				cout<<i<<" ";
			}

		}
		cout<<endl;
  }

return 0;
}
