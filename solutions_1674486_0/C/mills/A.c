#include <stdio.h>

#define DEBUG	0
#define CLMAX	1000+1

int	T,N,M,i,j,k,l,R,S,step,E,stepmade;

int	map[CLMAX][CLMAX];
int	stage[CLMAX],
	place[CLMAX],
	rplace[CLMAX];

int check() {
	for(j=1;j<=N;++j) {
	    memset((void*)stage,0,sizeof(int)*CLMAX);
	    memset((void*)place,0,sizeof(int)*CLMAX);
	    memset((void*)rplace,0,sizeof(int)*CLMAX);
	    stage[1] = place[j] = step = *stage = 1;
	    rplace[1] = j;
	    for(stepmade=1;stepmade;) {
		++step;
		stepmade = 0;
		if(DEBUG) printf("\n%d step:",step);
		S = *stage;
		for(k=1;k<=S;++k) {
		    if(stage[k]!=(step-1)) continue;
		    E = rplace[k];
		    M = map[E][0];
		    for(l=1;l<=M;++l) {
			R = map[E][l];
			if(!place[R]) {
			    stepmade = 1;
			    (*stage)++;
			    stage[place[R] = *stage] = step;
			    rplace[*stage] = R;
			    if(DEBUG) printf(" %d>%d",E,R);
			} else {
			    if(DEBUG) printf(" %d!>%d",E,R);
			    return 1;
			  }
		    }
		}
	    }
	}
	return 0;
}

int main() {
    
    scanf("%d\n",&T);
    for(i=1;i<=T;++i) {
	scanf("%d",&N);
	for(j=1;j<=N;++j) {
	    scanf("%d", &M);
	    map[j][0] = M;
	    for(k=1;k<=M;++k)
		scanf("%d",&(map[j][k]));
	}
	printf("Case #%d: %s\n", i, check() ? "Yes" : "No");
    }
    return 0;
}