#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

vector<int> v[N];
int f[N], q[N];

int rec(int x) {
	if (f[x]) return 0;
	f[x] = 1;
	for (int i = 0; i < v[x].size(); i++) if (q[v[x][i]] == -1 || rec(q[v[x][i]])) {
		q[v[x][i]] = x;
		return 1;
	}
	return 0;
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		map<string, int> A, B;
		int n;
		cin >> n;
		for (int i = 0; i <= 3000; i++) v[i].clear();
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			if (A.find(a) == A.end()) {
				int t = A.size();
				A[a] = t;
			}
			if (B.find(b) == B.end()) {
				int t = B.size();
				B[b] = t;
			}
//			cout << "! " << A[a] << " " << B[b] << endl;
			v[A[a]].pb(B[b]);
		}
		int ret = 0;
		for (int i = 0; i < B.size(); i++) q[i] = -1;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A.size(); j++) f[j] = 0;
			ret += rec(i);
		}
		int need = ret + (A.size() + B.size() - ret * 2);
		
		cout << "Case #" << tt << ": ";
		cout << n - need << endl;

	}
	return 0;
}