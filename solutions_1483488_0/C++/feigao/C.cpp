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

int shift(int n, int ten) {
	return (n/10) + (n%10) * ten;
}

int main() {
	int T;
	scanf("%d\n", &T);

	Rep(iT, T) {
		printf("Case #%d: ", iT+1);

		int A, B, res = 0, len, ten;
		scanf("%d%d", &A, &B);

		set<pair<int,int> > spi;
		spi.clear();
		len = 1, ten = 10;
		while(ten <= A) {
			len++;
			ten *= 10;
		}
		ten /= 10;
		for (int n = A; n <= B; n++) {
			for (int i = 0, m = n; i < len; i++) {
				m = (m/10) + (m%10)*ten;
				if (A <= n && n < m && m <= B) {
					spi.insert(make_pair(n,m));
				}
			}
		}

		res = spi.size();
		printf("%d\n", res);
	}
	return 0;
}
