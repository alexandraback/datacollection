#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TestCases, TCCount;
int Armin, Motes;
int N[1000];
int Max, i, x;
int Oper[1000];
int Ans[1000];
int Min;

int QuickSort(int *A, int *B){
	if (*A>*B) return 1;
	if (*A<*B) return -1;
	return 0;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	scanf("%d", &TestCases);
	for (TCCount=1; TCCount<=TestCases; TCCount++){
		printf("Case #%d: ", TCCount);
		memset(Oper, 0, sizeof(Oper));
		memset(Ans, 0, sizeof(Ans));
		
		scanf("%d%d", &Armin, &Motes);
		for (i=1; i<=Motes; i++) scanf("%d", &N[i]);
		
		if (Armin==1){
			printf("%d\n", Motes);
			continue;
		}
		N[0] = 0;
		qsort(N, Motes+1, sizeof(N[0]), QuickSort);
		
		Max = Armin;
		for (i=1; i<=Motes; i++){
			if (Max>N[Motes]){
				for (x=i; x<=Motes; x++) Oper[x] = Oper[i-1];
				break;
			}
			
			if (N[i]<Max){
				Max += N[i];
				Oper[i] = Oper[i-1];
				
				continue;
			}
			Oper[i] = Oper[i-1];
			
			if (Max<=N[i]){
				Max--;
				while(Max<N[i]){
					Max*=2;
					Oper[i]++;
				}
				Max = Max+N[i]+1;
			}
		}
		
		for (i=1; i<=Motes+1; i++){
			Ans[i] = Oper[i-1]+Motes+1-i;
			
		}
		Min = Oper[Motes];
		for (i=1; i<=Motes; i++) if (Min>Ans[i]) Min = Ans[i];
		
		printf("%d\n", Min);
	}
	
	
	return 0;
}

