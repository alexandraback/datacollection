//Template

// By Anudeep :)
//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//M lazy ;)
typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vs;
typedef pair< int ,int > pii;
typedef vector <ll> vll;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)

int r,n,ans,E;
int a[132];
int dp[20][10];
int solve(int i, int e) {
	if(i==n) return 0;
	if(dp[i][e]!=-1) return dp[i][e];
	dp[i][e] = 0;
	for(int j=0; j<=e; j++) {
		dp[i][e] = max( dp[i][e], a[i]*j + solve(i+1, min(E, e-j+r)));
	}
	return dp[i][e];
}

int main() {
	int e,i;
	int test=0;
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&e,&r,&n);
		rep(i,n) scanf("%d",a+i);
		E = e;
		memset(dp,-1,sizeof(dp));
		ans = 0;
		ans = solve(0,e);
		printf("Case #%d: %d\n",++test,ans);
	}
}