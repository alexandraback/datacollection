#include <cstdio>

const int N = 1000;
const double eps = 1E-8;
int i, j, n, sum;
double l, r, x;
int a[N];

bool find(){ 
     double t = a[i] + x * sum;
     double res = 1.0 * sum - x * sum;
     for (j = 0; j < n; j++)
         if (j != i && a[j] < t)
            res -= t - a[j];
     if (res < 0) 
        return false;
     return true;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int test = 1; test <= t; test++){
        scanf("%d",&n);
        sum = 0;
        for (i = 0; i < n; i++){
            scanf("%d",&a[i]);
            sum += a[i];
        }
        printf("Case #%d:", test);
        for (i = 0; i < n; i++){
            l = 0;
            r = 1;
            while (l < r - eps){
                  x = (l + r) / 2;
                  if (find())
                     l = x;
                  else r = x;
            }
            printf(" %.7lf", x * 100);
        }
        printf("\n");
    }
    return 0;
}
