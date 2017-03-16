
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>



int main(int argc, const char * argv[])
{
    int cn;
    int pn;
    int pn2;
    int t, t2;
    double av1, av2;
    int p[200];
    int win[200];
    double f[200];
    
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    
    scanf("%d\n", &cn);
    
    for (int ci = 1; ci <= cn; ci++) {
        t = 0;
        scanf("%d", &pn);
        for (int i = 0; i < pn; ++i) {
            scanf("%d", &p[i]);
            t+=p[i];
        }
        t2 = t * 2;
        av1 = (double)t2 / pn;
        pn2 = 0;
        for (int i = 0; i < pn; ++i) {
            if (p[i] > av1) {
                win[i] = 1;
                t2 -= p[i];
            }
            else {
                pn2++;
                win[i] = 0;
            }
//            pn2 += (p[i] > av1)?0:1;
//            win[i] = (p[i] > av1)?1:0;
//            t -= (p[i] > av1)?p[i]:0;
        }
        av2 = (double)t2 / pn2;
//        printf("t = %d, av2 = %f\n", t, av2);
//        printf("av2 = %f, t = %d", av2, t);
        printf("Case #%d: ", ci);
        for (int i = 0; i < pn; ++i) {
            f[i] = (win[i] == 0)?(av2 - p[i]) * 100 / t:0;
            printf("%.6f ", f[i]);// > 0.0f? f[i]: 0.0f );
        }
        printf("\n");
        
    }
    
    
    return 0;
}

