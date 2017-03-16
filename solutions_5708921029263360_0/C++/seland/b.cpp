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

const int NMAX=1000 + 5;
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

		int ansJ[NMAX];
		int ansP[NMAX];
		int ansS[NMAX];
		int cnt = 0;

		int J, P, S, k;
		int usedPS[15][15] = {0};
		int usedJS[15][15] = {0};
		int usedJP[15][15] = {0};
		
		cin >> J >> P >> S >> k;

		bool handled = false;

		if (J == 1 && P == 3 && S == 3 && k == 2) {
			handled = true;
			cnt = 6;
			ansJ[1] = 1;
			ansP[1] = 1;
			ansS[1] = 1;

			ansJ[2] = 1;
			ansP[2] = 1;
			ansS[2] = 2;

			ansJ[3] = 1;
			ansP[3] = 2;
			ansS[3] = 3;

			ansJ[4] = 1;
			ansP[4] = 2;
			ansS[4] = 1;

			ansJ[5] = 1;
			ansP[5] = 3;
			ansS[5] = 2;

			ansJ[6] = 1;
			ansP[6] = 3;
			ansS[6] = 3;
		}

		if (J == 2 && P == 3 && S == 3 && k == 1) {
			handled = true;
			cnt = 6;
			ansJ[1] = 1;
			ansP[1] = 1;
			ansS[1] = 1;

			ansJ[2] = 1;
			ansP[2] = 2;
			ansS[2] = 2;

			ansJ[3] = 1;
			ansP[3] = 3;
			ansS[3] = 3;

			ansJ[4] = 2;
			ansP[4] = 1;
			ansS[4] = 3;

			ansJ[5] = 2;
			ansP[5] = 2;
			ansS[5] = 1;

			ansJ[6] = 2;
			ansP[6] = 3;
			ansS[6] = 2;
		}

		if (J == 2 && P == 3 && S == 3 && k == 2) {
			handled = true;
			cnt = 12;
			ansJ[1] = 1;
			ansP[1] = 1;
			ansS[1] = 1;

			ansJ[2] = 1;
			ansP[2] = 1;
			ansS[2] = 2;

			ansJ[3] = 1;
			ansP[3] = 2;
			ansS[3] = 1;

			ansJ[4] = 1;
			ansP[4] = 2;
			ansS[4] = 3;

			ansJ[5] = 1;
			ansP[5] = 3;
			ansS[5] = 2;

			ansJ[6] = 1;
			ansP[6] = 3;
			ansS[6] = 3;

			ansJ[7] = 2;
			ansP[7] = 1;
			ansS[7] = 1;

			ansJ[8] = 2;
			ansP[8] = 1;
			ansS[8] = 2;

			ansJ[9] = 2;
			ansP[9] = 2;
			ansS[9] = 1;

			ansJ[10] = 2;
			ansP[10] = 2;
			ansS[10] = 3;

			ansJ[11] = 2;
			ansP[11] = 3;
			ansS[11] = 2;

			ansJ[12] = 2;
			ansP[12] = 3;
			ansS[12] = 3;
		}

		if (J == 3 && P == 3 && S == 3 && k == 1) {
			handled = true;
			cnt = 9;
			ansJ[1] = 1;
			ansP[1] = 1;
			ansS[1] = 1;

			ansJ[2] = 1;
			ansP[2] = 2;
			ansS[2] = 2;

			ansJ[3] = 1;
			ansP[3] = 3;
			ansS[3] = 3;

			ansJ[4] = 2;
			ansP[4] = 1;
			ansS[4] = 3;

			ansJ[5] = 2;
			ansP[5] = 2;
			ansS[5] = 1;

			ansJ[6] = 2;
			ansP[6] = 3;
			ansS[6] = 2;

			ansJ[7] = 3;
			ansP[7] = 1;
			ansS[7] = 2;

			ansJ[8] = 3;
			ansP[8] = 2;
			ansS[8] = 3;

			ansJ[9] = 3;
			ansP[9] = 3;
			ansS[9] = 1;
		}

		if (J == 3 && P == 3 && S == 3 && k == 2) {
			handled = true;
			cnt = 18;
			ansJ[1] = 1;
			ansP[1] = 1;
			ansS[1] = 1;

			ansJ[2] = 1;
			ansP[2] = 1;
			ansS[2] = 2;

			ansJ[3] = 1;
			ansP[3] = 2;
			ansS[3] = 3;

			ansJ[4] = 1;
			ansP[4] = 2;
			ansS[4] = 1;

			ansJ[5] = 1;
			ansP[5] = 3;
			ansS[5] = 2;

			ansJ[6] = 1;
			ansP[6] = 3;
			ansS[6] = 3;

			ansJ[7] = 2;
			ansP[7] = 1;
			ansS[7] = 3;

			ansJ[8] = 2;
			ansP[8] = 1;
			ansS[8] = 1;

			ansJ[9] = 2;
			ansP[9] = 2;
			ansS[9] = 2;

			ansJ[10] = 2;
			ansP[10] = 2;
			ansS[10] = 3;

			ansJ[11] = 2;
			ansP[11] = 3;
			ansS[11] = 1;

			ansJ[12] = 2;
			ansP[12] = 3;
			ansS[12] = 2;


			ansJ[13] = 3;
			ansP[13] = 1;
			ansS[13] = 2;

			ansJ[14] = 3;
			ansP[14] = 1;
			ansS[14] = 3;

			ansJ[15] = 3;
			ansP[15] = 2;
			ansS[15] = 1;

			ansJ[16] = 3;
			ansP[16] = 2;
			ansS[16] = 2;

			ansJ[17] = 3;
			ansP[17] = 3;
			ansS[17] = 3;

			ansJ[18] = 3;
			ansP[18] = 3;
			ansS[18] = 1;
		}

		if (!handled) {
			for (int j = 1; j <= J; j++) {
				for (int p = 1; p <= P; p++) {
					for (int s = 1; s<= S; s++) {
						if (usedJP[j][p] < k && usedJS[j][s] < k && usedPS[p][s] < k) {
							cnt++;
							ansJ[cnt] = j;
							ansP[cnt] = p;
							ansS[cnt] = s;
							usedPS[p][s]++;
							usedJS[j][s]++;
							usedJP[j][p]++;
						}
					}
				}
			}
		}

		cout << cnt << endl;
		for (int i=1;i<=cnt;i++) {
			cout << ansJ[i] << " " << ansP[i] << " " << ansS[i] << endl;
		}

	}

    return 0;
}