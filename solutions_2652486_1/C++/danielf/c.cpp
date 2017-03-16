#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <random>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define _FOR(it, b, e) for (decltype(b) it = (b); it != (e); ++it)
#define foreach(x...) _FOR(x)
#define fu(i, a) foreach(i, 0, a)
#define forall(i, v) foreach(i, all(v))

#define MSET(c, v) memset(c, v, sizeof(c))

#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int	n[4];
void process(int x) {
	int t = 0;
	for (int i : {2,3,5,7}) {
		int c = 0;
		while (x % i == 0) {
			x /= i;
			c++;
		}
		n[t] = max(n[t], c);
		t++;
	}
}
typedef long long ll;
double C[20][20];
int main() {
	int _;

	C[0][0] = 1.;
	fu(i, 20) fu(j, i+1) {
		if (j == 0 || j == i) C[i][j] = 1;
		else C[i][j] = C[i-1][j] + C[i-1][j-1];
	}

	scanf("%d", &_);
	mt19937 RNG;
	RNG.seed(12345);
	uniform_real_distribution<double> rand(0., 1.);
	double bp = pow(.5, 12);
	fu(__,_) {
		printf("Case #%d:\n", __+1);
		int R,N,M,K;
		scanf("%d %d %d %d", &R, &N, &M, &K);
		fu(i, R) {
			vi temp2(K, 0);
			fu(i, K) scanf("%d", &temp2[i]);
			n[0] = 0; n[1] = 0; n[2] = 0; n[3] = 0;
			fu(i, K) process(temp2[i]);
			int n23 = 12 - n[2] - n[3];

			vi ans(12, 2);
			double M = 0.;
			fu(_, 1500) {
				vi temp;

				fu(i, n[1]) {
					if (n[0] == 0 || rand(RNG) < .8) temp.pb(3);
					else {
						temp.pb(6);
						n[0]--;
					}
				}
				while (n[0]) {
					double p = rand(RNG);
					if (n[0] >= 3) {
						if (p < .25) {
							n[0] -= 3;
							temp.pb(8);
						} else if (p < .5) {
							n[0] -= 2;
							temp.pb(4);
						} else {
							n[0]--;
							temp.pb(2);
						}
					} else if (n[0] >= 2) {
						if (p < .5) {
							n[0] -= 2;
							temp.pb(4);
						} else {
							n[0]--;
							temp.pb(2);
						}
					} else {
						n[0]--;
						temp.pb(2);
					}
				}
				fu(i, n[2]) temp.pb(5);
				fu(i, n[3]) temp.pb(7);
				while (temp.size() < 12) temp.pb(rand(RNG) * 7 + 2);
				if (temp.size() > 12) continue;
				vector<double> prob2(3*12+1), prob3(12+1), prob5(12+1), prob7(12+1);
				int c21=0, c22=0,c23=0, c31=0, c51=0, c71=0;
				
				fu(i, 12) {
					int x = temp[i];
					int t = 0;
					while (x % 2 == 0) {
						x/=2; t++;
					}
					if (t == 1) c21++;
					if (t == 2) c22++;
					if (t == 3) c23++;
					t = 0;
					while (x % 3 == 0) {
						x/=3; t++;
					}
					if (t) c31++;
					t = 0;
					while (x % 5 == 0) {
						x/=5; t++;
					}
					if (t) c51++;
					t = 0;
					while (x % 7 == 0) {
						x/=7; t++;
					}
					if (t) c71++;
				}
				
//				prob2[0] = bp * pow(2, 12 - c21 - c22 - c23);
				fu(i, c21+1) fu(j, c22+1) fu(k, c23+1) prob2[i + 2*j + 3*k] += bp * C[c21][i] * C[c22][j] * C[c23][k] * pow(2, 12 - c21 - c22 - c23);
//				prob3[0] = bp * pow(2, 12 - c31);
				fu(i, c31+1) prob3[i] = bp * C[c31][i] * pow(2, 12 - c31);
//				prob5[0] = bp * pow(2, 12 - c51);
				fu(i, c51+1) prob5[i] = bp * C[c51][i] * pow(2, 12 - c51);
//				prob7[0] = bp * pow(2, 12 - c71);
				fu(i, c71+1) prob7[i] = bp * C[c71][i] * pow(2, 12 - c71);
				
				double p = 1.;
				for (int i : temp2) {
					int c = 0;
					while (i % 2 == 0) {
						c++; i /= 2;
					}
					p *= prob2[c];
					c = 0;
					while (i % 3 == 0) {
						c++; i /= 3;
					}
					p *= prob3[c];
					c = 0;
					while (i % 5 == 0) {
						c++; i /= 5;
					}
					p *= prob5[c];
					c = 0;
					while (i % 7 == 0) {
						c++; i /= 7;
					}
					p *= prob7[c];
				}
				if (p > M) {
					M = p;
					ans = temp;
				}
			}

			for(int i : ans) printf("%d", i);
			printf("\n");
		}
	}
	return 0;
}
