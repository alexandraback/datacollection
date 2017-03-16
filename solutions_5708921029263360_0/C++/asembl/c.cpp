#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std ;

struct tuple {
    int i,j,k;

    tuple() {}
    tuple(int _i, int _j, int _k) {
        i = _i;
        j = _j;
        k = _k;
    }
};
tuple ans1[1000], ans2[1000];
int tot1 = 0, tot2 = 0;

bool valid( int mask, int J, int P, int S, int m ) {
        int cnt1[10][10] = {0};
        int cnt2[10][10] = {0};
        int cnt3[10][10] = {0};

        tot2 = 0 ;
        for ( int i = 0 ; i < J ; ++i ) {
                for ( int j = 0 ; j < P ; ++j )
                        for ( int k = 0 ; k < S ; ++k ) {
                                int l = i ;
                                l = l * J + j ;
                                l = l * P + k ;

                                if ( mask & (1<<l) ) {
                                    ans2[tot2++] = tuple(i,j,k);
                                    cnt1[i][j] ++;
                                    cnt2[i][k] ++;
                                    cnt3[j][k] ++;
                                    if ( cnt1[i][j] > m || cnt2[i][k] > m || cnt3[j][k] > m )
                                        return false;
                                }
                        }
        }
        return true;
}
int cntone(int mask) {
    if ( mask==0 ) return 0;
    return cntone(mask>>1) + (mask&1);
}

void work() {
    int J,P,S;
    int m;

    scanf("%d%d%d%d",&J,&P,&S,&m);

    int tot = J*P*S;
    tot1 = 0 ;
    for ( int mask = (1<<tot)-1 ; mask ; --mask ) {

        int size = cntone(mask);

        if ( size > tot1 )
            if ( valid(mask,J,P,S,m) ) {
                for ( int i = 0 ; i < tot2 ; ++i )
                    ans1[i] = ans2[i];
                tot1 = tot2 ;
            }
    }

    printf("%d\n",tot1);
    for ( int i = 0 ; i < tot1; ++i ) {
        printf("%d %d %d\n",ans1[i].i+1,ans1[i].j+1,ans1[i].k+1);
    }
}
int main() {

    int T ;
    scanf("%d",&T);
    for ( int i = 0 ; i < T ; ++i ) {
        printf("Case #%d: ",i+1);
        work();
    }
    return 0;
}
