#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <stack>

#pragma comment(linker, "/STACK:64777216")
using namespace std;


typedef long long ll;
typedef unsigned long long ull;

template<typename T> int size(T & a) { return (int) a.size(); }
template<typename T> T sqr(T a) {return a * a; }

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii > 
#define _(a, b) memset((a), (b), sizeof(a))
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define all(a) a.begin(),a.end()


void solve(int tn) {
	
	int n;
	cin >> n;
	vector<int> a(n);
	int sum=0;
	REP(i, 0, n) {
		cin >> a[i];
		sum += a[i];
	}
	vector<double> ans(n);
	REP(it, 0, n) {
		double l=0, r=100;
		REP(iterat,0,100){
			double m=(l + r) / 2;
			bool ok=true;
			vector<double> cur (n);
			cur[it] = a[it] + sum * m/100.0 ;
			double mx = 0;
			double other = 100 - m;
			double sum_need= 0;
			REP(j, 0, n) if (j != it) {
				if (a[j] >= cur[it]) continue;
				double need = (cur[it] - a[j]) / sum;
				sum_need += need*100.0;
			}
			if (sum_need + 1e-8 < other)
				l=m;
			else
				r=m;
		}
		ans[it] = (l + r) / 2;
	}
	



	printf("Case #%d: ", tn);
	REP(i, 0, n) printf("%.10lf%c", ans[i], " \n"[i+1==n]);
}
int main() {            
#ifdef air
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	char buf[1024];
	gets(buf);
	int tc;
	sscanf(buf, "%d", &tc);
	REP(t, 1, tc + 1) {
		solve(t);
	}

}