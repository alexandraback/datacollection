#include <stdio.h>
#include <stdlib.h>	//qsort()

int choose(int star1[], int star2[], int stage[], int* nStar, int N){
	int i, starGet, choice=-1, choiceGet=0, diff=0;
	for(i=0; i<N; i++){
		starGet = 0;
		if(stage[i] == 2) continue;
		if(stage[i] == 1 && *nStar >= star2[i]) starGet = 1;
		if(stage[i] == 0 && *nStar >= star1[i]) starGet = 1;
		if(stage[i] == 0 && *nStar >= star2[i]) starGet = 2;
		if(starGet > choiceGet) {
			choice = i;
			choiceGet = starGet;
		}
		if(starGet == choiceGet && starGet != 0){
			if(stage[i] == 1) {
				choice = i;
				choiceGet = starGet;
				diff = 10000;
			}
			else if(star2[i]-star1[i] > diff) {
				choice = i;
				choiceGet = starGet;
				diff = star2[i] - star1[i];
			}
		
		}
		
	}
	//update nStar and stage
	*nStar += choiceGet;
	stage[choice] += choiceGet;
	return choice;
}

void solvecase(){
	int N, star1[1000], star2[1000], stage[1000];
	int i,a,b,choice,round,remain,nStar,fail=0;
	scanf("%d",&N);
	for(i = 0; i<N ; i++){
		scanf("%d %d",&(star1[i]), &(star2[i]));
		if(star2[i] > 2*N) fail = 1;
		stage[i] = 0;
	}
	if(fail){
		printf("Too Bad");
		return;
	}

	nStar = 0;
	remain = N;
	round = 0;
	while(1){
		choice = choose(star1, star2, stage, &nStar, N);
		round++;
		if(choice == -1){
			printf("Too Bad");
			break;
		}
		if(stage[choice] == 2) remain--;
		if(remain == 0){
			printf("%d",round);
			break;
		}
	}
}

void main(){
	int T, i;
	//freopen("test.txt", "rt", stdin);
	freopen("B-small-attempt3.in", "rt", stdin);
	freopen("B-small-attempt3.out", "wt", stdout);
	scanf("%d",&T);
	for(i=0 ; i<T ; i++){
		printf("Case #%d: ",i+1);
		solvecase();
		printf("\n");
	}

}