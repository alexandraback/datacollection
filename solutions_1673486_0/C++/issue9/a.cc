#include <cstdio>
#include <algorithm>

using namespace std;

int a,b;
typedef double real;
real p[100000];
real pa[100001];
real res[4];

#define D if(0)


int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ++ti) {
       printf("Case #%d: ", ti); 
       D printf("\n");
       scanf("%d%d", &a, &b);
       pa[0] = 1;
       for (int i = 0; i < a; ++i) {
           scanf("%lf", p+i);
           pa[i+1] = pa[i] * p[i];
           D printf("  pa[%d] = %g\n", i+1, pa[i+1]);
       }
       
       // 1
       res[0] = 1 + (b - a) + (1 - pa[a]) * (1 + b);
           D printf("  res[0] = %g\n", res[0]);
       // 2
       res[1] = 1e100;
       for (int i = 1; i < a; ++i) {
           // backspace (a-i) times
           // leave first i characters
           real v = 1 + (a - i) * 2 + b - a \
               + (1 - pa[i]) * (1 + b);
           D printf("  res[1][%d] = %g\n", i, v);
           if (v < res[1]) res[1] = v;
       }
       // 3
       res[2] = 2 + b;
           D printf("  res[2] = %g\n", res[2]);
       printf("%.8lf\n", min(res[0], min(res[1],res[2])));
    }

    return 0;
}
