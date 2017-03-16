#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ep(...) fprintf(stderr, __VA_ARGS__); fflush(NULL)
struct level { int req[2]; int best; };
int main(int argc, char **argv) {
	int cases = 0;
	scanf("%d\n", &cases);
	ep("%d cases.\n", cases);
	
	for(int cas = 0; cas < cases; ++cas) {
		int levels;
		scanf("%d", &levels);
		struct level *ld = malloc(sizeof(struct level) * levels);
		memset(ld, 0, sizeof(struct level) * levels);
		for(int i = 0; i < levels; ++i) {
			scanf("%d %d", &ld[i].req[0], &ld[i].req[1]);
		}
		bool finished = false;
		bool failed = false;
		int starsSoFar = 0;
		int levelsCompleted = 0;
		int twoStarredLevels = 0;
		while(!finished && !failed) {
			failed = true;
			for(int i = 0; i < levels; ++i) {
				if(ld[i].best == 0 && ld[i].req[1] <= starsSoFar) {
					ld[i].best = 2;
					failed = false;
					levelsCompleted++;
					starsSoFar += 2;
					++twoStarredLevels;
					break;
				}
			}
			if(failed) {
				int highestDiffL = -1;
				int L = -1;
				int t = 0;
				for(int i = 0; i < levels; ++i) {
					if(ld[i].best == 1 && ld[i].req[1] <= starsSoFar) {
						ld[i].best = 2;
						failed = false;
						levelsCompleted++;
						starsSoFar += 1;
						++twoStarredLevels;
						highestDiffL = -1;
						ep("solving %d to 2 from 1\n", i);
						break;
					}
					else if(ld[i].best == 0 && ld[i].req[0] <= starsSoFar) {
						int d = ld[i].req[1] - ld[i].req[0];
						if(d > highestDiffL) {
							highestDiffL = d;
							L = i;
							t = 1;
							continue;
						}
						else if(d == highestDiffL && t == 2) {
							highestDiffL = d;
							L = i;
							t = 1;
							continue;
						}
					}
				}
				if(highestDiffL != -1) {
					failed = false;
					if(ld[L].best == 1) {
						ep("solving %d to 2 from 1\n", L);
						ld[L].best = 2;
						levelsCompleted++;
						starsSoFar += 1;
						++twoStarredLevels;
					}
					else {
						ep("solving %d to 1 from 0\n", L);
						ld[L].best = 1;
						failed = false;
						levelsCompleted++;
						starsSoFar += 1;
					}
				}
			}
			
			if(twoStarredLevels == levels) {
				failed = false;
				finished = true;
			}
			
			ep("twostar: %d, levelsCompleted: %d\n", twoStarredLevels, levelsCompleted);
		}
		free(ld);

		if(finished) {
			printf("Case #%d: %d\n", cas + 1, levelsCompleted);
		}
		else {
			printf("Case #%d: Too Bad\n", cas + 1);
		}
		fflush(NULL);
	}

	exit(0);
}