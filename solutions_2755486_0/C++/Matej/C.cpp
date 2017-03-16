#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;			// number of tribes
int d[1009];	// day of first attack
int n[1009];	// number of attacks
int w[1009];	// western point of first attack
int e[1009];	// eastern point of first attack
int s[1009];	// strength of first attack
int dd[1009];	// attack periodicity
int dp[1009];	// attack movement
int ds[1009];	// change of strength, result stays positive

int height[1209];
int getHeight(int x) {
	return height[x + 600];
}
void setHeight(int x, int h) {
	height[x + 600] = h;
}

struct attack {
	int day;
	int w, e;
	int strength;
};
vector<attack> A;

bool operator < (attack x, attack y)
{
  return x.day < y.day;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; Ti++)
	{
		// init
		for (int i = -500; i <= 500; ++i)
			setHeight(i, 0);
		A.clear();

		// input
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d %d %d %d %d %d %d %d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
		
		// calculate attacks
		for (int i = 0; i < N; ++i)
			for (int j = 1; j <= n[i]; ++j) {
				attack a;
				a.day = d[i] + (j - 1) * dd[i];
				a.w = w[i] + (j - 1) * dp[i];
				a.e = e[i] + (j - 1) * dp[i];
				a.strength = s[i] + (j - 1) * ds[i];
				A.push_back(a);
			}

		// sort attacks
		sort(A.begin(), A.end());

		//simulate attacks
		int successful = 0;
		unsigned int i = 0;
		while (i < A.size()) {
			unsigned int j = i;
			while (j < A.size() && A[j].day == A[i].day) j++;

			// deal with days [i..j)
			for (unsigned int k = i; k < j; ++k) {
				//printf("day of attack %d = %d\n", k, A[k].day);

				bool success = false;
				for (int p = A[k].w * 2; p <= A[k].e * 2; ++p)
					if (getHeight(p) < A[k].strength)
						success = true;
				if (success) successful++;
				//if (success) printf("SUCCESS\n");
			}
			for (unsigned int k = i; k < j; ++k)
				for (int p = A[k].w * 2; p <= A[k].e * 2; ++p)
					if (getHeight(p) < A[k].strength)
						setHeight(p, A[k].strength);

			i = j;
		}

		// output
		printf("Case #%d: %d\n", Ti, successful);
	}
	return 0;
}
