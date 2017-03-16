/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 5e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int main(){
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	ios::sync_with_stdio(false);

	int n, t;
	cin >> t;
	FOR(cs,1,t){
		cin >> n;
		cout << "Case #" << cs << ": ";
		if (n == 0)
			cout << "INSOMNIA" << endl;
		else{
			int a[10] = {0};
			int res = 0, cnt = 0, m = 0;
			while (cnt < 10){
				m = res += n;
				while (m){
					if (!a[m%10]) cnt++;
					a[m%10] = 1;
					m /= 10;
				}
			}
			cout << res << endl;
		}
	}

	return 0;
}