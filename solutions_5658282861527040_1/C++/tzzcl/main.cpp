#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
const int inf=1e9+7;
const long long linf=1e18;
const double pi=acos(-1.0);
typedef long double lf;
typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
template <class T> T sqr(T x){return x*x;}
const double eps = 1e-10;//µÈÓÚ0
int a,b,k;
ll dp[55][2][2][2];
ll gao(int cnt,int l,int r,int L){
  if (cnt<0) 
	  if (l==0&&r==0&&L==0) return 1;
	  else return 0;
  if (dp[cnt][l][r][L]!=-1) return dp[cnt][l][r][L];
  dp[cnt][l][r][L]=0;
  int s,e;
  if (l) if (a&(1LL<<cnt)) s=1;else s=0;
  else s=1;
  if (r) if (b&(1LL<<cnt)) e=1;else e=0;
  else e=1;
  for (int i=0;i<=s;i++)
	  for (int j=0;j<=e;j++){
		  if ((k&(1LL<<cnt))==0&&i&&j&&L) continue;
		  int temp=0;
		  if (k&(1<<cnt)){
			  if (i&&j) temp=1;
		  }
		  else temp=1;
		  dp[cnt][l][r][L]+=gao(cnt-1,l&&i==s,r&&j==e,L&&temp);
	  }
  return dp[cnt][l][r][L];
}
int main(){
	ios::sync_with_stdio(false);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;cin>>t;
	for (int tt=1;tt<=t;tt++){
		cin>>a>>b>>k;
		mmset(dp);
		cout<<"Case #"<<tt<<": "<<gao(31,1,1,1)<<endl;
		
	}
	//system("pause");
	return 0;
}