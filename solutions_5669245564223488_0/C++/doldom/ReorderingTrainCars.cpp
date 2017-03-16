#include<cstdio>
#include<cstring>
using namespace std;

const int MOD = 1000000007;
int T, CN, n;
int permutation[10], strlength[10];
char cars[10][101], connectedStr[1001];

int valid() {
	int charset[26] = {0};
	if (!connectedStr[0]) return 1;
	charset[connectedStr[0]-'a'] = 1;
	for (int i=1; connectedStr[i]; ++i) {
		if (connectedStr[i] != connectedStr[i-1]) {
			if (charset[connectedStr[i]-'a'])
				return 0;
			else
				charset[connectedStr[i]-'a'] = 1;
		}
	}
	return 1;
}

int gogo(int t, int end) {
	if (t == n-1) return valid();
	if (!valid()) return 0;
	int res = 0;
	for (int i=0; i<n; ++i) {
		if (!permutation[i]) {
			permutation[i] = 1;
			strcpy(connectedStr+end, cars[i]);
			res += gogo(t+1, end+strlength[i]);
			connectedStr[end] = 0;
			permutation[i] = 0;
		}
	}
	//printf("%s %d\n", connectedStr, valid());
	return res;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	scanf("%d", &T);
	for (CN=1; CN<=T; ++CN) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%s", cars+i);
		printf("Case #%d: ", CN);
		for (int i=0; i<n; ++i)
			strlength[i] = strlen(cars[i]);
		memset(permutation, 0, sizeof permutation);
		memset(connectedStr, 0, sizeof connectedStr);
		printf("%d\n", gogo(-1, 0)%MOD);
	}
	return 0;
}