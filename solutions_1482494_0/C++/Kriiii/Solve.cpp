#include <stdio.h>
#include <algorithm>
using namespace std;

struct stage{
	int a,b;
}S[1111];
bool cmp(const stage& a, const stage& b){return a.b == b.b ? a.a < b.a : a.b < b.b;}

int N,C[1111],ANS,STAR;

int main()
{
	int T,Case=0;
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int i;

	scanf ("%d",&T); while (T--){
		scanf ("%d",&N); ANS = STAR = 0;
		for (i=0;i<N;i++) scanf ("%d %d",&S[i].a,&S[i].b), C[i] = 0;
		sort(S,S+N,cmp);

		while (1){
			for (i=0;i<N;i++) if (C[i] < 2){
				if (S[i].b <= STAR){
					STAR += 2 - C[i];
					C[i] = 2;
					ANS++;
				}
				else break;
			}

			for (i=N-1;i>=0;i--) if (C[i] < 1){
				if (S[i].a <= STAR){
					STAR++;
					C[i] = 1;
					ANS++;
					break;
				}
			}

			if (i < 0) break;
		}

		printf ("Case #%d: ",++Case);
		if (STAR == 2 * N) printf ("%d\n",ANS);
		else printf ("Too Bad\n");
	}
}