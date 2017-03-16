#include<cstring>
#include<iostream>
#include<bitset>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>
#include<iomanip>
#define BUFF ios::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define imprime(v) for(int X=0;X<v.size();X++) cout<<v[X]<<" "; cout<<endl;
#define grid(v) for(int X=0;X<v.size();X++){for(int Y=0;Y<v[X].size();Y++) cout<<v[X][Y]<<" "; cout<<endl;}
#define endl "\n"
using namespace std;
const int INF= 0x3f3f3f3f;
const long double pi= acos(-1);
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vector< int > > vvi;
const int MOD=1e9+7;
void solve(int t){
  cout<<"Case #"<<t<<": ";
  int n;
  cin>>n;
  vvi v(2*n-1,vi(n,0));
  vi ocor(2510,0);
  for(int i=0;i<2*n-1;i++){
    for(int j=0;j<n;j++){
      cin>>v[i][j];
      ocor[v[i][j]]++;
    }
  }
  vi r;
  for(int i=0;i<2510;i++) if(ocor[i]%2) r.pb(i);
  imprime(r);
}
int main()
{
  BUFF;
  int t;
  cin>>t;
  for(int i=1;i<=t;i++) solve(i);
  return 0;
}
