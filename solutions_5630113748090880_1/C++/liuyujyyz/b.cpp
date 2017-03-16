#include <cstdio>
#include <cstdlib>
FILE * fin = fopen("B-large.in", "r");
FILE * fout = fopen("b.out", "w");

void work(int r){
     fprintf (fout, "Case #%d: ", r);
     int N;
     fscanf (fin, "%d", &N);
     int q[2500];
     for (int i = 0; i < 2500; i ++) q[i] = 0;
     for (int i = 0; i < N*(2 * N-1); i ++){
         int tmp;
         fscanf(fin, "%d", &tmp);
         q[tmp - 1] ++;
     }
     for (int i = 0; i < 2500; i ++){
         if (q[i] % 2 == 1) fprintf (fout, "%d ", i + 1);
     }
     fprintf (fout, "\n");
     return;
     }

int main(){
    int T;
    fscanf (fin, "%d", &T);
    for (int i = 0; i < T; i++) work(i + 1);
    return 0;
}