#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cassert>
#include <limits.h>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define S(t,i) scanf("%" ## t, &i)
#define SI(i) scanf("%d", &i)

const int INF=INT_MAX;
const int MAXN=55;

int t;

int r,c,m, tmp;
int d0, d1;
char p[MAXN][MAXN];


int main() {
    //ios_base::sync_with_stdio(0);
    
    SI(t);
    
    FOR(i,1, t) {
        SI(r);
        SI(c);
        SI(m);
        printf("Case #%d:\n",i);
        if (r<=c) {
            d0=0;
            d1=1;
        } else {
            d0=1;
            d1=0;
            tmp=r;
            r=c;
            c=tmp;
        }
        
        if (r==1) {
            p[1][1]='c';
            FOR(ii,2,c-m) {
                p[1][ii]='.';
            }
            FOR(ii,1+c-m,c) {
                p[1][ii]='*';
            }
        } else if (r==2) {
            if (m==(r*c)-1) {
                FOR(x,1,r) {
                    FOR(y,1,c) {
                        p[x][y]='*';
                    }
                }
                p[1][1]='c';
            } else if ((m%2==0) && (r*c-m)>=4) {
                FOR(x,1,r) {
                    FOR(y,1,c-m/2) {
                        p[x][y]='.';
                    }
                    FOR(y,c+1-m/2,c) {
                        p[x][y]='*';
                    }
                }
                p[1][1]='c';
            } else {
                printf("Impossible\n");
                continue;
            }
        } else {
            FOR(ri, 1, r)
            FOR(ci, 1, c)
            p[ri][ci]='.';
            
            int mcols=min(c-3,m/r);
            FOR(ri, 1, r)
            FOR(ci, c-mcols+1, c) {
                p[ri][ci]='*';
            }
                
            m-=mcols*r;
            
            if (m) {
                if (mcols<c-3) {
                    FOR(ri, 1, min(r-2,m)) {
                        p[ri][c-mcols]='*';
                    }
                    m-=min(r-2,m);
                    if (m) {
                        assert(m==1);
                        p[1][c-mcols-1]='*';
                    }
                } else {
                    
                    int mrows=min(r-3,m/3);
                    FOR(ri, r-mrows+1, r)
                    FOR(ci, 1, 3) {
                        p[ri][ci]='*';
                    }
                    
                    m-=mrows*3;
                    
                    if (m) {
                        if (mrows<r-3) {
                            p[r-mrows][3]='*';
                            m--;
                            if (m==1) {
                                p[r-mrows-1][3]='*';
                            }
                        } else {
                            if (m!=1 && m!=3 && m!=5 && m!=8) {
                                printf("Impossible\n");
                                continue;
                            }
                            else {
                                if (m>=1) {
                                    p[3][3]='*';
                                }
                                if (m>=3) {
                                    p[3][2]='*';
                                    p[3][1]='*';
                                }
                                if (m>=5) {
                                    p[2][3]='*';
                                    p[1][3]='*';
                                }
                                if (m==8) {
                                    p[2][2]='*';
                                    p[1][2]='*';
                                    p[2][1]='*';
                                }
                            }
                        }
                    }
                }
            }
            
            p[1][1]='c';
            
        }
        
        if (d0==0){
            FOR(ri,1,r){
                FOR(ci,1,c){
                    printf("%c",p[ri][ci]);
                }
                printf("\n");
            }
        } else {
            FOR(ri,1,c){
                FOR(ci,1,r){
                    printf("%c",p[ci][ri]);
                }
                printf("\n");
            }
        }
        
    }
    
    
    
	return 0;
}
