#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<int> pnt;
typedef pair<int, int> pii;

#define FOR(i,a,b) for(i=a;i<b;i++) 
#define RA(x) (x).begin(), (x).end()
#define REV(x) reverse(RA(x))
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
#define X first
#define Y second
#define MOD 1000000007
int arr[111][111], n, m;
int solve(int x){
	int i, j, f, k;
	FOR(i, 0, n){
		f = 1, k = 0;
		FOR(j, 0, m) 
		if(arr[i][j] != x && arr[i][j] != 1<<30)
			f = 0;
		else if(arr[i][j] == x) k++;
		if(f && k){
			FOR(j, 0, m) arr[i][j] = 1<<30;
			return true;
		}
	}
	FOR(j, 0, m){
		f = 1, k = 0;
		FOR(i, 0, n) 
		if(arr[i][j] != x && arr[i][j] != 1<<30)
			f = 0;
		else if(arr[i][j] == x) k++;
		if(f && k){
			FOR(i, 0, n) arr[i][j] = 1<<30;
			return true;
		}
	}
	return false;
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int t=1, test, mn, f, i, j, k;
	string ans;
	cin >> t;
	FOR(test, 0, t){
		f = 0;
		cin >> n >> m;
		FOR(i, 0, n) FOR(j, 0, m) cin >> arr[i][j];
		while(1)
		{
			mn = 1<<30;
			FOR(i, 0, n) FOR(j, 0, m) mn = min(mn, arr[i][j]);
			if(mn == 1<<30){
				f = 1; break;
			}
			if(!solve(mn)) {
				f = 0; break;
			}
		}
		if(f) ans = "YES";
		else ans = "NO";
		printf("Case #%d: %s\n", test+1, ans.c_str());
	}
}

