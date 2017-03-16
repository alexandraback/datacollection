#include <cstdio>
#include <queue>
#include <set>
#include <functional>

using namespace std;

int main() {
	int T, n;
	static int arr[1024];
	scanf("%d", &T);
	for (int c=1;c<=T;c++) {
		scanf("%d", &n);
		int l=1, r=0, m;
		for (int i=0;i<n;i++) {
			scanf("%d", arr+i);
			r=max(r, arr[i]);
		}
		int ans=0x7fffffff;
		for (int i=l;i<=r;i++) {
			int off=0;
			for (int j=0;j<n;j++) {
				int x=arr[j]%i, y=arr[j]/i;
				if (!x) y--;
				off+=y;
			}
			ans=min(ans, off+i);
		}
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}

