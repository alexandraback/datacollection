#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>

using namespace std;

#define sz(a) int((a).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;

const double eps=1E-9;
const double Exp=2.718281828459045;
const double Pi=3.1415926535897932;

const int NMAX=40 + 5;
const int MMAX=20;
const int INF=1000000000;
const ll INFLL=1000000000000000000ll;
const int BS=1000000007;

template <typename T> inline T abs(const T a){
    if (a<0) return -a;
    return a;
}
template <typename T> inline T sqr(const T& a){
    return a*a;
}

int main(){
    ios::sync_with_stdio(false);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		cout << "Case #" << T << ": ";
		int b;
		ll m;
		cin >> b >> m;
		int a[60][60] = {0};

		ll pw = 1;
		for (int i=3;i<=b;i++) {
			pw *= 2;
		}
		if (pw < m) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}


		ll sum[60] = {0};
		sum[b-1] = 1;
		for (int cur = b-1; cur >=0; cur--) {
			for (int i = cur + 1; i < b; i++) {
				if (sum[cur] + sum[i] <= m) {
					sum[cur] += sum[i];
					a[cur][i] = 1;
				}
			}
		}
		if (sum[0] != m) {
			cout << sum[0] << endl;
			cout << "FAIL" << endl;
			continue;
		}

		cout << "POSSIBLE" << endl;

		for (int i=0;i<b;i++){
			for (int j=0;j<b;j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
	}

    return 0;
}