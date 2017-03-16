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

	int N, S, p, t, p3;

	Rep(iT, T) {
		printf("Case #%d: ", iT+1);

		int good = 0, bad = 0;

		scanf("%d%d%d", &N, &S, &p);
		p3 = p * 3;

		if (p == 0) {
			Rep(iN, N) scanf("%d", &t);
			good = N;
		} else if (p == 1) {
			Rep(iN, N) {
				scanf("%d", &t);
				if (t > 0) good++;
			}
		} else {
			Rep(iN, N) {
				scanf("%d", &t);
				if (t >= p3 - 2) {
					good++;
					continue;
				} else if (t <= p3 - 5) {
					continue;
				} else {
					bad++;
					continue;
				}
			}
		}
		printf("%d\n", good + min(bad, S));
	}
	return 0;
}
