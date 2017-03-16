#include <stdio.h>
#include <math.h>
#define EPS 1e-10
//#define DEBUG

typedef long long ll;

int n;
char side[50],z[2];
int s[50],p[50];

double pos[50];
double tid;

char other(char x) {
	return x=='L'?'R':'L';
}

void print() {
	int taken[50],i,j,ix;
	double least;
	printf("tid %f\n",tid);
	for(i=0;i<n;i++) taken[i]=0;
	for(i=0;i<n;i++) {
		ix=-1;
		least=1e200;
		for(j=0;j<n;j++) if(!taken[j] && least>pos[j]) least=pos[j],ix=j;
		taken[ix]=1;
		printf("%d. %c %d %.8f\n",ix,side[ix],s[ix],pos[ix]);
	}
}

int main() {
	int T,caseno=1,i,j,k;
	double next,cur;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%s %d %d",z,&s[i],&p[i]),side[i]=z[0];
		if(n<3) {
			printf("Case #%d: Possible\n",caseno++);
			continue;
		}
		for(i=0;i<n;i++) pos[i]=p[i];
		tid=0;
		while(1) {
#ifdef DEBUG
			print();
#endif
			/*	force left */
			for(i=0;i<n;i++) if(side[i]=='R') {
				for(j=0;j<n;j++) if(side[j]=='L') {
					if(pos[j]+5-EPS>pos[i] && pos[j]<pos[i]+5-EPS) goto fail;
				}
				side[i]='L';
			fail:;
			}
			/*	change lane */
			for(i=0;i<n;i++) {
				for(j=0;j<n;j++) if(j!=i && side[j]==side[i]) {
					if(fabs(pos[i]+5-pos[j])<EPS) {
#ifdef DEBUG
						printf("let car %d (right behind %d) change lane\n",i,j);
#endif
						for(k=0;k<n;k++) if(side[k]!=side[i]) {
							if(pos[k]>=pos[i]-5+EPS && pos[k]<=pos[i]+5-EPS) {
#ifdef DEBUG
								printf("obstructed by car %d\n",k);
#endif
								goto done;
							}
						}
						side[i]=other(side[i]);
#ifdef DEBUG
						printf("car %d at %c\n",i,side[i]);
#endif
					}
				}
			}
			next=1e100;
			for(i=0;i<n;i++) for(j=0;j<n;j++) if(i!=j && side[i]==side[j]) {
				if(s[i]>s[j] && pos[i]<pos[j]) {
					/*	how long until i overtakes j */
					cur=(pos[j]-pos[i]-5.)/(s[i]-s[j]);
					if(next>cur) next=cur;
				}
			}
#ifdef DEBUG
			printf("next overtakage in %f\n",next);
#endif
			tid+=next;
			if(next<EPS) break;
			if(next>1e50) {
				printf("Case #%d: Possible\n",caseno++);
				goto slutt;
			}
			for(i=0;i<n;i++) pos[i]=p[i]+s[i]*tid;
		}
	done:
		printf("Case #%d: %.16f\n",caseno++,tid);
	slutt:;
	}
	return 0;
}
