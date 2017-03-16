#include <cstdio>
using namespace std;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    
    for(int testcase = 1; testcase <= t; testcase++) {
            int n;
            scanf("%d", &n);
            
            
            int a[21];
            for(int i = 0; i < n; i++) scanf("%d", &a[i]);
            
            printf("Case #%d:\n", testcase);
            bool ok = false;
            for(int i = 1; i < (1<<n); i++) {
                    int sum = 0;
                    int b[31], c[31], ccnt = 0, bcnt = 0;
                    for(int j = 0; j < n; j++) {
                            if(i&(1<<j)) {
                                    c[ccnt++] = a[j];
                                    sum += a[j];
                            } else
            
                            b[bcnt++] = a[j];
                    }
                    
                    for(int j = 1; j < (1<<bcnt); j++) {
                            int sum2 = 0;
                            int ef[31], ecnt = 0;
                            for(int k = 0; k < bcnt; k++) {
                                    if(j&(1<<k)) {
                                                 sum2 += b[k];
                                                 ef[ecnt++] = b[k];
                                    }
                            }
                            if(sum2==sum) {
                                          for(int k = 0; k < ecnt; k++) printf("%d ", ef[k]);
                                          printf("\n");
                                          for(int k = 0; k < ccnt; k++) printf("%d ", c[k]);
                                          printf("\n");
                                          ok = true;
                                          goto out;
                            }
                    }
            }
            out:
                
            if(!ok) printf("Impossible\n");
    }
}

                                     
            
