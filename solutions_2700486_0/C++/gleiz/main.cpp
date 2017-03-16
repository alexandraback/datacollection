#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define BOUND 3000
double C[BOUND][BOUND] = {{0}};
double two[BOUND] = {0};
int main()
{
    int T = 0;
    long long N = 0, X = 0, Y = 0;
   // freopen("D:\\workspace\\cb\\GCJ2013\\Round1B\\B\\bin\\Debug\\B-small-attempt3.in", "r", stdin);

    two[0] = 1.0;
    for (int i = 1; i<BOUND; i++){
        C[i][1] = i * 1.0;
        C[i][0] = 1.0;
        C[i][i] = 1.0;

        two[i] = two[i-1] * 2.0;
        for (int j = 2; j<i; j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }

    cin >> T;
    for (int cas = 1; cas <= T ; cas++){
        cin >> N >> X >> Y;
        double res = 0.0;

        X = labs(X);
        Y = labs(Y);
        long long rnd = (X + Y)/2;

        long long start = 1, acc = 0, cnt = 1;

        while (cnt <= rnd){
            acc += (start + start - 1);
            start += 2;
            cnt++;
        }
        if (N <= acc){
            res = 0.0;
        }else{
            if (X == 0){
                if (N >= acc + (start + start - 1)){
                    res = 1.0;
                }else{
                    res = 0.0;
                }
            }else{
                long long need = Y + 1;
                if (N < acc + need){
                    res = 0.0;
                }else if (N >= acc + rnd*2 + need){
                    res = 1.0;
                }else{
                    N -= acc;
                    double attempt = 0.0, sum = 0.0;
                    for (long long other = 0; other <= N; other++){
                        int this_site = N - other;
                        if (this_site > rnd * 2 || this_site < 0 || other > rnd * 2){
                            continue;
                        }else{
                            if (this_site >= need){
                                attempt += C[N][other];
                            }
                            sum += C[N][other];
                        }
                    }
                    res += attempt / sum;
                }
            }
        }
        printf("Case #%d: %.8lf\n", cas, res);
    }
    return 0;
}
