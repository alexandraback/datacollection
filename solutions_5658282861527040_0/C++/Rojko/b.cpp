#include<cstdio>
#include<vector>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for (int t = 0; t<T; ++t) {
		int a,b,k;
		scanf("%d %d %d", &a, &b, &k);
		ll poc = 0;
		for (int i = 0; i<a; ++i) {
			for (int j = 0; j<b; ++j) {
				int vys = i&j;
				if (vys<k) poc++;
			}
		}
		printf("Case #%d: %lld\n",t+1,poc);
	}
	return 0;
}
