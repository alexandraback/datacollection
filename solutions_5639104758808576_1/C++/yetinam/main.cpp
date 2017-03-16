#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int r=1;r<=t;r++) {
		int smax;
		int needed=0;
		int sum=0;
		char trash;
		scanf("%d",&smax);
		scanf("%c",&trash);
		for (int i=0;i<=smax;i++) {
			int akt;
			char tmp;
			scanf("%c",&tmp);
			akt=tmp-48;
			//printf("%d\n",akt);
			if (sum+needed<i) {
				needed=i-sum;
			}
			sum+=akt;
			//printf("%d\n",needed);
		}
		printf("Case #%d: %d\n",r,needed);
	}
	return 0;
}
