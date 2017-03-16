#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

long double array[15];
long double speed[15];

long double a,b,c,d,e,f;
int main() {
	freopen("hike.in","r",stdin);
	freopen("hike.out","w",stdout);
	int t;
	int ans;
	scanf("%d\n",&t);
	for (int _=0;_<t;_++) {
		int n;
		printf("Case #%d: ",_+1);
		printf("%d\n",rand()%10);
		continue;
		scanf("%d\n",&n);
		if (n == 1) {
			scanf("%Lf %Lf %Lf\n",&a,&b,&c);
			if (b==1) {
				puts("0");
				continue;
			}
			long double ti = (long double)((c+1)*(360-a)/(360));
			a+=ti*(360/c);
			// printf("%Lf is a\n",a);
			if (a >= 720) ans = 1;
			else ans = 0;
			printf("%d\n",ans);
			continue;
		} else {
			scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&a,&b,&c,&d,&e,&f);
			if (c==f){ puts("0");
			continue;
			}
			if (c < f) {
				swap(a,d);swap(b,e);swap(c,f);
			}
			long double ti = (long double)(c*(360-a)/(360));
			d+=ti*(360/f);
			ans = 0;
			// printf("%Lf %Lf\n",d,360/f);
			if (d >= 720) {
				ans = 1;
			}
			printf("%d\n",ans);
		}
	}
}