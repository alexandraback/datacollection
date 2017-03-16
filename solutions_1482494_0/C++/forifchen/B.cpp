#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <numeric>
#include <queue>
#define f(i,x,y) for(int i = x;i<y; i++)
#define fd(i,x,y) for(int i=x;i>=y;i--)
#define FOR(it,A) for (typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(),(v).end()
#define rall(V) (v).rbegin(),(v).rend()
#define oo (1<<30)
#define eps (1e-9)
#define pb push_back
#define clr(A,x) memset(A,x,sizeof(A))
#define ones(x) __builtin_popcount (x)
#define cua(x) (x)*(x)
#define vint vector<int>
#define pii pair<int,int>
#define fst first
#define snd second
#define MAX 2005
typedef long long ll;
using namespace std;

int T, n;
int a[MAX], b[MAX];
int r[MAX];
bool orden (int i, int j){
	if (b[i] != b[j]) return b[i] < b[j];
	return a[i] > a[j];
}
int vis[MAX];

int main(){
	cin >> T;
	int caso = 1;
	while (T--){
		cin >> n;
		f(i,0,n) cin >> a[i] >> b[i];
		f(i,0,n) r[i] = i;
		f(i,0,n) vis[i] = 2;
		sort (r, r+n, orden);
		int tengo = 0; int res = 0;
		bool ok = 1;
		f(i,0,n){
			while (i<n && tengo>=b[r[i]]) i++, res++, tengo += vis[i-1];
			if (i==n) continue;
			int j = n-1;
			for (; j>=i; j--){
				if (vis[j]==1) continue;
				if (tengo >= a[r[j]]) break;
			}
			if (j==i-1) {
				ok = 0;
				break;
			}
			vis[j] = 1; res++; tengo++;
			i--;
		}
		printf ("Case #%d: ", caso++);
		if (ok==0) puts ("Too Bad");
		else cout << res << endl;
	}
}



