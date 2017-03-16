#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
 
using namespace std;
 
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
 
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int INF = 1e9;

double EPS = 1e-10;



int main(){
	int mCase;
	scanf("%d", &mCase);
	int n;
	for(int Case = 1; Case <= mCase; Case++){
		scanf("%d", &n);
		vector<vi> v(2*n-1, vi(n, 0));
		map<int, int> mp;
		rep(i, 2*n-1){
			rep(j, n){
				scanf("%d", &v[i][j]);
				mp[v[i][j]]++;
			}
		}
		vi ans;
		for(auto p : mp){
			if(p.se%2==1) ans.pb(p.fi);
		}
		printf("Case #%d:", Case);
		for(int i = 0; i < ans.size(); i++){
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
}