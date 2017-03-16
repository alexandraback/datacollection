#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int a[2*50-1][50];
int b[10000];
vector<vector<int> > vv;

int main() {
	int tt;
	scanf("%d", &tt);
	for (int t = 1; t <= tt; t++) {
		int n;
		scanf("%d", &n);
		memset(b, 0, sizeof b);
		for (int i = 0; i < 2*n-1; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				b[x]++;
			}
		}
		vector<int> v;
		for (int i = 0; i < 3000; i++) {
			if (b[i] % 2) {
				v.push_back(i);
			}
		}
		printf("Case #%d:", t);
		for (int i = 0; i < v.size(); i++) {
			printf(" %d", v[i]);
		}
		printf("\n");
	}
}