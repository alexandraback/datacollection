#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

int GET_INT(){int ret; scanf("%d",&ret); return ret;}

#define INT GET_INT()

typedef long long LL;
typedef pair<int,int> pii;

int N;
int A[1005], B[1005];

bool taken[1005][3];

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B_small.out","w",stdout);

    int T; scanf("%d",&T);

    REP(t,1,T){
        scanf("%d",&N);
        FOR(i,N){
            scanf("%d%d",&A[i],&B[i]);
        }

        CLR(taken,0);

        int totalStars = 0, twoCount = 0;
        int played = 0;


        while(twoCount < N){
            int best_i = -1, best_j = -1;
            int best_xtra = -1;

            FOR(i,N){
                if(!taken[i][2]){
                    if(totalStars >= B[i]){ //printf("%d, <%d,%d>\n",i,totalStars,B[i]);
                        int xtra = 2;
                        if(taken[i][1])
                            xtra = 1;

                        if(best_xtra == -1){
                            best_xtra = xtra;
                            best_i = i;
                            best_j = 2;
                        }else if(xtra > best_xtra){
                            best_xtra = xtra;
                            best_i = i;
                            best_j = 2;
                        }else if(xtra == best_xtra && best_j == 1){
                            best_xtra = xtra;
                            best_i = i;
                            best_j = 2;
                        }
                    }
                }

                if(!taken[i][1] && !taken[i][2]){
                    if(totalStars >= A[i]){
                        int xtra = 1;

                        if(best_xtra == -1){
                            best_xtra = xtra;
                            best_i = i;
                            best_j = 1;
                        }else if(xtra > best_xtra){
                            best_xtra = xtra;
                            best_i = i;
                            best_j = 1;
                        }else if(xtra == best_xtra && best_j == 1 && B[i]>B[best_i]){
                            best_xtra = xtra;
                            best_i = i;
                            best_j = 1;
                        }
                    }
                }
            }//FOR

            ++played;

            if(best_xtra == -1){
                break;
            }

            totalStars += best_xtra;
            taken[best_i][best_j] = true;
            if(best_j == 2){
                twoCount++;
            }
        }

        printf("Case #%d: ",t);

        if(twoCount < N) puts("Too Bad");
        else printf("%d\n",played);
    }

    return 0;
}
