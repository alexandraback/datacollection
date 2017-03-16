#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <complex>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const double EPS = 0.0000000001;
const long long int INF = 1000000000;

const int MAX_L = 10000;

int L, X;
char seq[MAX_L + 1];

int qua_to_int(char ch)
{
	switch (ch) {
		case 'i': return 1;
		case 'j': return 2;
		case 'k': return 3;
		default:  return 0;
	}
}

// 0 ->  1, 1 ->  i, 2 ->  j, 3 ->  k
// 4 -> -1, 5 -> -i, 6 -> -j, 7 -> -k
int mul[8][8] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4}
};

void make_mul()
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (i == 0 && j == 0) continue;
			int t = (i + j) % 2;
			for (int k = 0; k < 4; ++k) {
				for (int l = 0; l < 4; ++l) {
					mul[4*i + k][4*j + l] = (mul[k][l] + 4 * t) % 8;
				}
			}
		}
	}
}

void solve()
{
	if (L * X <= 10000) {
		int s[MAX_L];
		for (int i = 0; i < L; ++i) {
			s[i] = qua_to_int(seq[i]);
		}
		for (int i = 1; i < X; ++i) {
			for (int j = 0; j < L; ++j) {
				s[i * L + j] = s[j];
			}
		}

		int N = L * X;
		// l = [0, sep1), [sep1, sep2), r = [sep2, N)
		int sep1 = 1, sep2 = N - 1, l = s[0], r = s[sep2];
		for (; sep1 < N && l != 1; ++sep1) {
			l = mul[l][s[sep1]];
			//fprintf(stderr, "sep1: %d %d\n", sep1, l);
		}
		for (; sep2 > 0 && r != 3; --sep2) {
			r = mul[s[sep2 - 1]][r];
			//fprintf(stderr, "sep2: %d %d\n", sep2, r);
		}

		//fprintf(stderr, "sep1: %d, sep2: %d\n", sep1, sep2);

		if (sep1 >= sep2) {
			printf("NO\n");
			return;
		}

		int m = 0;
		for (int pos = sep1; pos < sep2; ++pos) {
			m = mul[m][s[pos]];
		}

		printf("%s\n", m == 2 ? "YES" : "NO");
		return;
	}

	printf("AAA\n");
}

int main()
{
	int T;
	make_mul();
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		scanf("%d%d", &L, &X);
		scanf("%s", seq);
		printf("Case #%d: ", t + 1);
		solve();
	}

	return 0;
}

