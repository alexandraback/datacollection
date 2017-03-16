#include <stdio.h>
#include <algorithm>

using namespace std;

FILE *fin;
int proc(void)
{
    int N;
    long long D[110]={0}, A;
    fscanf(fin, "%lld %d", &A, &N);
    int i;
    for (i=0;i<N;++i){
        fscanf(fin, "%lld", &D[i]);
    }
    sort(D, D+N);

    if (A == 1) return N;

    int res = N;
    int op = 0;
    for (i=0;i<N;++i){
        if (D[i] < A){
            A = A + D[i];
        }else{
            while (D[i] >= A){
                A = A + (A-1);
                ++op;
            }
            A = A + D[i];
        }
        if (res > op + N-i-1){
            res = op + N - i - 1;
        }
    }
    return res;
}
int main(void)
{
    fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int T, t;
    fscanf(fin, "%d", &T);
    for (t=1;t<=T;++t){
        fprintf(fout, "Case #%d: %d\n", t, proc());
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
