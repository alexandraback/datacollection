#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define For(i, a, b) for (int i = (a); i != b; i++)
#define Rep(i,n) For(i,0,n)
#define debug(x) cout<<#x<<": "<<x<<endl
#define Pb push_back
#define Mp make_pair

template<class T>void show(T a,int n) {Rep(i,n)cout<<a[i]<<' ';cout<<endl;}
template<class T>void show(T a,int n,int m) {Rep(i,n){Rep(j,m)cout<<a[i][j]<<' ';cout<<endl;}}


int main() {
	int T;
	scanf("%d\n", &T);

	int n, x;
	vector<int> s;
	vector<double> m;

	Rep(iT, T) {

		scanf("%d", &n);

		s.resize(n);
		m.resize(n);
		x = 0;

		Rep(i,n) {
			scanf("%d", &s[i]);
			x += s[i];
			m[i] = 0;
		}
		double h = 2.0*x, l = 0.0, mid;
		while (fabs(h-l) > 0.000000010) {
			mid = (h+l)/2.0;
			double sum = 0;
			Rep(i,n) {
				sum += max(mid, s[i]*1.0);
			}
			if (sum < 2 * x) {
				l = mid;
			} else {
				h = mid;
			}
		}
		mid = (h+l) / 2.0;
		Rep(i,n) {
			if (s[i] >= mid) {
				m[i] = 0;
			} else {
				m[i] = (mid-s[i])*100.0/x;
			}
		}

		printf("Case #%d:", iT+1);
		Rep(i,n) {
			printf(" %lf", m[i]);
		}
		printf("\n");
	}
	return 0;
}
