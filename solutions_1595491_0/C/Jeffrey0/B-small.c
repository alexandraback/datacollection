#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ep(...) fprintf(stderr, __VA_ARGS__)
#define JUDGES 3
int main(int argc, char **argv) {
	int cases = 0;
	scanf("%d\n", &cases);
	ep("%d cases.\n", cases);
	
	for(int cas = 0; cas < cases; ++cas) {
		int people = 0, surprising = 0, p = 0;
		int dancers = 0;
		scanf("%d %d %d", &people, &surprising, &p);
		ep("pep=%d sur=%d p=%d\n", people, surprising, p);
		for(int i = 0; i < people; ++i) {
			int score;
			int mod3;
			int div3;
			scanf("%d", &score);
			mod3 = score % JUDGES;
			div3 = score / JUDGES;
			ep("Person %d: score=%d,mod3=%d,div3=%d ", i, score, mod3, div3);
			// For a non-surprising case:
			// 18: div3=6,mod3=0, trip=[6, 6, 6]
			// 19: div3=6,mod3=1, trip=[6, 6, 7]
			// 20: div3=6,mod3=2, trip=[6, 7, 7]
			// 21: div3=7,mod3=0, trip=[7, 7, 7]

			// For a surprising case:
			// 18: div3=6,mod3=0, trip=[5, 6, 7]
			// 19: div3=6,mod3=1, trip=[5, 7, 7]
			// 20: div3=6,mod3=2, trip=[6, 6, 8]
			// 21: div3=7,mod3=0, trip=[6, 7, 8]
			// straight case: avg score > p, 10 9 10 case
			if(score == 0) {
				if(p != 0) {
					ep("look at me I am a zero.\n");
				}
				else {
					// In these special olympics, everyone gets a medal.
					++dancers;
					ep("look at me I am a zero, GREAT RACE.\n");
				}
				continue;
			}
			if(mod3 == 0) {
				if(div3 >= p) {
					ep("straight scores dancer\n");
					++dancers;
				}
				else if(surprising) {
					// we can [5, 6, 7] our 18, if that's enough we're surprising
					if(div3 + 1 >= p) {
						--surprising;
						++dancers;
						ep("surprising ok\n");
					}
					else {
						// just assume we're not surprising
						ep("not surprising, but could've been\n");
					}
				}
				else {
					ep("if only we were surprising...\n");
				}
			}
			else if(mod3 == 1) {
				// mod1 cases don't benefit from being surprising but get one point extra for free
				// 19 ns: div3=6,mod3=1, trip=[6, 6, 7], max = 7
				// 19 su: div3=6,mod3=1, trip=[5, 7, 7], max = 7
				// they are div3 + 1 either way
				if((div3 + 1) >= p) {
					ep("mod1 ok\n");
					++dancers;
				}
				else {
					ep("mod1 too low\n");
				}
			}
			else if(mod3 == 2) {
				// mod2 cases do benefit from being surprising and get one point extra for free
				// 20: div3=6,mod3=2, trip=[6, 7, 7], max = 7
				// 20: div3=6,mod3=2, trip=[6, 6, 8], max = 8
				if((div3 + 1) >= p) {
					ep("mod2 ok, no need for surprising\n");
					++dancers;
				}
				else if(surprising) {
					// we can [5, 6, 7] our 18, if that's enough we're surprising
					if(div3 + 2 >= p) {
						--surprising;
						++dancers;
						ep("mod2 surprising\n");
					}
					else {
						// just assume we're not surprising
						ep("mod2 not surprising\n");
					}
				}
				else {
					ep("if only we were surprising...\n");
				}
			}
		}
		if(surprising < 0) {
			ep("WARNING: %d surprising cases left.\n", surprising);
		}
		printf("Case #%d: %d\n", cas + 1, dancers);
	}

	exit(0);
}