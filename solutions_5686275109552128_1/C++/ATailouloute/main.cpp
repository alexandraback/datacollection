/*
 * author ATailouloute
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <climits>

using namespace std;

#define F(i,L,R)   for(int i=L; i<R;  i++)
#define FE(i,L,R)  for(int i=L; i<=R; i++)
#define FF(i,L,R)  for(int i=L; i>R;  i--)
#define FFE(i,L,R) for(int i=L; i>=R; i--)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

int main() {

    freopen("B-large.in","r",stdin) ;
    freopen("B-large.out","w",stdout) ;

    int A[1200];
    int T;
    int D , tmp , ans , sum;

    scanf("%d", &T) ;
    FE(caseID, 1, T) {
        scanf("%d", &D) ;
        F(i, 0, D){
            scanf("%d", &A[i]) ;
            tmp = max(tmp,A[i]) ;
        }
        ans = tmp ;
        FE(i, 1, tmp){
            sum = i ;
            F(j, 0, D){
                if( A[j] > i ) {
                    if( A[j]%i == 0 )
                        sum += (A[j]/i-1) ;
                    else
                        sum += (A[j]/i) ;
                }
            }
            ans = min(ans,sum) ;
        }
        printf("Case #%d: %d\n", caseID, ans) ;
    }
    return 0 ;
}
