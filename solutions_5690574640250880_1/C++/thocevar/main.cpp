#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <ctime>
using namespace std;

#define ALL(c) (c).begin(),(c).end()
#define PRESENT(c,x) (find(c.begin(),c.end(),x) != (c).end())
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FORD(i,a,b) for (int i=(a);i>=(b);i--)
#define INIT(a,v) memset(a,v,sizeof(a))
#define UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
template<class A, class B> A cvt(B x) { stringstream ss; ss<<x; A y; ss>>y; return y; }

typedef pair<int,int> PII;
typedef long long int64;

int h,w,m;
char t[51][51];

/*
void print() {
	REP (i,r) {
		REP (j,c) printf("%c",t[i][j]);
		printf("\n");
	}
}

void place(int h, int w) {
	INIT(t,'.');
	REP (i,m) t[i/w][i%w]='*';
	t[r-1][c-1]='c';
}
*/

int main() {
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	//freopen("C.in","r",stdin);
	int tests;
	scanf("%d",&tests);
	FOR (test,1,tests) {
		fprintf(stderr,"%d/%d\n",test,tests);
		printf("Case #%d:\n",test);
		scanf("%d %d %d",&h,&w,&m);
		if (h*w-1==m) {
			REP (i,h) {
				REP (j,w) {
					if (i==h-1 && j==w-1) printf("c");
					else printf("*");
				}
				printf("\n");
			}
			goto found;
		}
		FOR (dh,0,h) if (dh!=1) {
			FOR (dw,0,w) if (dw!=1) {
				FOR (dy,dh,h) if (dy!=1) {
					FOR (dx,dw,w) if (dx!=1) {
						if (m==(h-dh)*(w-dw)-(dy-dh)*(dx-dw)) {
							//printf("%d %d, %d %d\n",dh,dw,dy,dx);
							REP (i,h) {
								REP (j,w) {
									if (i==h-1 && j==w-1) printf("c");
									else if (i>=h-dh || j>=w-dw || (i>=h-dy && j>=w-dx)) printf(".");
									else printf("*");
								}
								printf("\n");
							}
							goto found;
						}
					}
				}
			}
		}
		FOR (y1,0,h) if (y1!=1) {
			FOR (x1,0,w) if (x1!=1) {
				FOR (y2,y1,h) if (y2!=1) {
					FOR (x2,0,x1) if (x2!=1) {
						if (m==h*w-(y1*x1)-(y2*x2)+(x2*y1)) {
							//printf("! %d %d, %d %d\n",y1,x2,y2,x2);
							REP (i,h) {
								REP (j,w) {
									if (i==h-1 && j==w-1) printf("c");
									else if ((i>=h-y1 && j>=w-x1) || (i>=h-y2 && j>=w-x2)) printf(".");
									else printf("*");
								}
								printf("\n");
							}
							goto found;
						}
					}
				}
			}
		}
		printf("Impossible\n");
		fprintf(stderr,"%d %d %d\n",h,w,m);
		found:;
	}
	return 0;
}
