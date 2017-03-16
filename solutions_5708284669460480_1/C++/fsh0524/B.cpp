#include <cstdio>
#include <cstring>
typedef long long LL;
main()
{
	int t, k, l, s, x = 0, slcs, q, chan[26];
	double p;
	char kb[101], rq[101];
	bool flag;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0 ; i < 26 ; ++i) chan[i] = 0;
		scanf("%d%d%d%s%s", &k, &l, &s, kb, rq);
		for (int i = 0 ; i < k ; ++i) ++chan[kb[i] - 'A'];
		flag = 0;
		for (int i = 0 ; i < l ; ++i)
			if (chan[rq[i] - 'A'] == 0) {
				printf("Case #%d: 0.0\n", ++x);
				flag = 1;
				break;
			}
		if (flag) continue;
		slcs = 0;
		for (int i = 1 ; i < l ; ++i) {
			flag = 1;
			for (int j = 0 ; j < l - i ; ++j)
				if (rq[j + i] != rq[j]) {
					flag = 0;
					break;
				}
			if (flag) {
				slcs = i;
				break;
			}
		}
		if (slcs == 0) q = s / l;
		else q = (s - (l - slcs)) / slcs;
		p = s - l + 1;
		for (int i = 0 ; i < l ; ++i) p = (p * chan[rq[i] - 'A']) / k;
		p = q - p;
		printf("Case #%d: %f\n", ++x, p);
	}
}