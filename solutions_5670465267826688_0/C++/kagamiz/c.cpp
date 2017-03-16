#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int adj[4][4] = {{1,  2,  3,  4},
 				 {2, -1,  4, -3},
 				 {3, -4, -1,  2},
 				 {4,  3, -2, -1}};

int mul[10001];

inline int abs(int x)
{
	return (max(x, -x));
}

inline int calc(int i, int j)
{
	int rev = i ? -mul[i - 1] : 1;
	bool sgn = (rev < 0) ^ (mul[j] < 0);
	int tmp = abs(rev), tmp2 = abs(mul[j]);
	return ((1 - 2 * sgn) * adj[tmp - 1][tmp2 - 1]);
}

bool solve()
{
	int L, X;
	char t[10001];
	string s;

	scanf("%d %d", &L, &X);
	scanf("%s", t);

	for (int i = 0; i < X; i++) s += string(t);

	if (s.size() <= 2) return (false);

	for (int i = 0; i < s.size(); i++){
		mul[i] = s[i] - 'i' + 2;
		if (i){
			bool sgn = mul[i - 1] < 0;
			int tmp = abs(mul[i - 1]);
			mul[i] = (1 - 2 * sgn) * adj[tmp - 1][mul[i] - 1]; 
		}
	}

	for (int i = 0; i < s.size() - 1; i++){
		for (int j = i + 1; j < s.size() - 1; j++){
			if (calc(0    , i) == 2 &&
				calc(i + 1, j) == 3 &&
				calc(j + 1, s.size() - 1) == 4){
					return (true);
			}
		}
	}

	return (false);

}

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		printf("Case #%d: %s\n", i + 1, solve() ? "YES" : "NO");
	}

	return (0);
}