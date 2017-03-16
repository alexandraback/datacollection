#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int T, N, N1, ti;
	double s[250];
	double sum, sum2, avg, avg1;
	double ans[250];
	int i, j, k;

	//freopen("D:\\VC2005\\GoogleCodeJam\\2012\\R1B_1\\in.txt","r",stdin);
	//freopen("D:\\VC2005\\GoogleCodeJam\\2012\\R1B_1\\A-small-attempt1.in","r",stdin);
	//freopen("D:\\VC2005\\GoogleCodeJam\\2012\\R1B_1\\A-large.in","r",stdin);
	//freopen("D:\\VC2005\\GoogleCodeJam\\2012\\R1B_1\\out.txt","w",stdout);

	scanf("%d\n", &T);
	for (ti = 1; ti <= T; ++ti) {
		sum = 0;
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i) {
			scanf("%lf\n", &s[i]);
			sum += s[i];
		}
		sum2 = sum*2;
		avg = sum*2/N;

		N1 = 0;
		for (i = 0; i < N; ++i) {
			if (s[i] >= avg) {
				sum2 = sum2 - s[i];
				ans[i] = 0.0;
			}
			else {
				ans[i] = 100;
				N1++;
			}
		}
		
		if (N1 > 1) {
			avg1 = sum2/N1;
			for (i = 0; i < N; ++i) {
				if (s[i] < avg) ans[i] = (avg1-s[i])*100/sum;
			}
		}

		printf("Case #%d:", ti);
		for (i = 0; i < N; ++i)
		    printf(" %0.6lf", ans[i]);
		printf("\n");
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

