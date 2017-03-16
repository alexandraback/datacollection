#include <cstdio>
#include <cstdlib>
FILE * fin = fopen("C-small-attempt0.in", "r");
FILE * fout = fopen("c.out", "w");

int maxlen[1000];
int len[1000][1000];

void work(int r){
     fprintf (fout, "Case #%d: ", r);
     int N;
     fscanf (fin, "%d", &N);
     //fprintf (fout, "%d\n", N);
     int F[1000];
     int opt = 0;
     for (int i = 0; i < N; i ++)
         fscanf (fin, "%d", &F[i]); // i + 1's BFF is F[i]
     bool re[1000];
     for (int i = 0; i < 1000; i ++) re[i] = false;
     for (int i = 0; i < N; i ++){
         maxlen[i] = 0;
         if (F[F[i] - 1] == i + 1){
            //fprintf (fout, "%d ", i);
            opt ++;
            re[i] = true;
            }
     }
  //   fprintf (fout, "\n");
     opt = opt;
     for (int i = 0; i < N; i ++)
         for (int j = 0; j < N; j ++) len[i][j] = 0;
     for (int i = 0; i < N; i ++){
         if (re[i]) continue;
         int count = 0;
         len[i][i] = 0;
         int next = F[i] - 1;
         while (len[i][next] == 0){
               count ++;
               if (next == i){
                  if (count > opt) opt = count;
                  break;
               }
               len[i][next] = count;
               if (count > maxlen[next]) maxlen[next] = count;
               if (re[next]) break;
               next = F[next] - 1;
         }
     }
     int tmpopt = 0;
     for (int i = 0; i < N; i ++){
         if (re[i]){
            //fprintf (fout, "%d: %d %d\n", i, maxlen[i], maxlen[F[i] - 1]);
            tmpopt += (maxlen[i] > maxlen[F[i] - 1]? maxlen[i] : maxlen[F[i] - 1]) + 2;
            re[F[i] - 1] = false;
            if (maxlen[i] + maxlen[F[i] - 1] + 2 > opt){
                          opt = maxlen[i] + maxlen[F[i] - 1] + 2;
            }
         }
     }
     if (tmpopt > opt) opt = tmpopt;
     fprintf (fout, "%d", opt);
     fprintf (fout, "\n");
     return;
     }

int main(){
    int T;
    fscanf (fin, "%d", &T);
    for (int i = 0; i < T; i++) work(i + 1);
    return 0;
}