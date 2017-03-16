#include<cstdio>
using namespace std;

int main(){
    int T, N;
    int s1, s2;
    int t1, t2;
    int tmps, tmph, tmpt;
    scanf(" %d ", &T);
    for(int t=1; t<=T; ++t){
	scanf(" %d ", &N);
	if(N == 1){
	    scanf(" %d %d %d ", &tmps, &tmph, &tmpt);
	    if(tmph == 1){
		printf("Case #%d: 0\n", t);
		continue;
	    }
	    s1 = tmps;
	    s2 = tmps;
	    t1 = tmpt;
	    t2 = tmpt+1;
	}else{
	    scanf(" %d %d %d ", &s1, &tmph, &t1);
	    scanf(" %d %d %d ", &s2, &tmph, &t2);
	}
	double tt1 = (360.0-s1)/360.0 * t1;
	double tt2 = (360.0-s2)/360.0 * t2;
	int res = 0;
	if(tt1 > tt2){
	    if((720.0-s2)/360.0 * t2 <= tt1)	res = 1;
	}else if(tt1 < tt2){
	    if((720.0-s1)/360.0 * t1 <= tt2)    res = 1;
	}
	printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
