#include <memory.h>
#include <cstdio>
#include <cstdlib>

int main(int argc, char **argv) {

	int nbTest;
	int level;
	int stars[1000][2];
	bool done[1000][2];
	int current;
	int res;

	scanf("%d", &nbTest);
	for(int _n=1; _n<=nbTest; ++_n) {
		scanf("%d", &level);
		for(int i=0; i<level; ++i) {
			scanf("%d%d", &stars[i][0], &stars[i][1]);
		}
		memset(done, 0, sizeof(done));
		res = current = 0;
		int m, max, min, max1;
		bool full, sec;
		while(1) {
			m = -1;
			max1 = -1;
			max = -1;
			min = 5000;
			full = false;
			sec = false;

			for(int i=0; i<level; ++i) {
				if(!done[i][1] && stars[i][1] <= current && stars[i][1] > max) {
					m = i;
					max = stars[i][1];
					full = !done[i][0];
					sec = true;
				}
				else if(!sec && !done[i][0] && stars[i][0] <= current && stars[i][0] <= min && stars[i][1] > max1) {
					m = i;
					min = stars[i][0];
					max1 = stars[i][1];
				}
				/*	if(stars[i][1] <= current && stars[i][1] > max) {
						m = i;
						max = stars[i][1];
						full = true;
						break;
					}
					if(stars[i][0] <= min) {
						m = i;
						min = stars[i][0];
					}
				}*/
			}
			if(m == -1) break;

			res++;
			current++;
			if(full) {
				current++;
				done[m][0] = done[m][1] = true; 
			}
			else if(done[m][0]) done[m][1] = true;
			else done[m][0] = true;
		}

		bool ok = true;
		for(int i=0; i<level; ++i) ok &= done[i][1];
		if(ok) printf("Case #%d: %d\n", _n, res);
		else printf("Case #%d: Too Bad\n", _n);
	}

	return 0;
}

