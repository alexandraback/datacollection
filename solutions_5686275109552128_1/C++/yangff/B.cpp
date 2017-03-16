#include <cstdio>
#include <algorithm>

using namespace std;

int p[1111];
int d;

bool check(int mt){
	for (int i = 0; i < mt; i++){
		int nt = mt - i; int left = i;
		for (int j = 0; j < d; j++){
			if (p[j] > nt){
				int cost = (p[j] / nt) + ((p[j] % nt) != 0) - 1;
				left -= cost;
			}
			if (left < 0)
				break;
		}
		if (left < 0) continue;
		return true;
	}
	return false;
}

void work(){
	scanf("%d", &d);
	for (int i = 0; i < d; i++)
		scanf("%d", p + i);
	int mx = 0;
	for (int i = 0; i < d; i++)
		mx = max(mx, p[i]);

	int l = 0, r = mx;

	for (int mid = (l + r) >> 1; l < r; check(mid) ? (r = mid) : (l = mid + 1)) {
		mid = (l + r) >> 1;
	};

	printf("%d\n", l);
}

int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		work();
	}
}
