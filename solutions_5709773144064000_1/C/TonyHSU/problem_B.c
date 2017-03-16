#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main () {
    //freopen ("B-small-attempt0.out", "w", stdout);
    //freopen ("B-small-attempt0.in", "r", stdin);
	int T, nm= 1;
	int i, j, k;
	scanf("%d", &T);
    while (T--) {
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);
        double save= x/2.0, last= 0;
        int round= 0;
        while (1) {
            double tmp= last;
			if (round!=0) tmp+=  c/(round*f + 2.0);
			last= tmp;
			tmp+= x/(round*f+2.0);
            if (tmp>save) break;
            else save= tmp;
            round++;
        }

        printf("Case #%d: %.7lf\n", nm++, save);
    }
    return 0;
}
