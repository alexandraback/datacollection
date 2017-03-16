#include <cstdio>
using namespace std;
int main() {
	int T, r, c, w;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d", &T);

	for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: %d\n", cas, c/w+(c%w != 0)+w-1);
	}
	return 0;
}


