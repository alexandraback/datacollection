#include <cstdio>
#include <cstdlib>

/*N(x + cX) <= \sum y + pX = X + \sum y   so c = [(X + newtotal) / N - x] / X*/

FILE * fin = fopen ("A-small-attempt2.in", "r"), * fout = fopen ("A-small.out", "w");;

void work (int r)
{
     fprintf (fout, "Case #%d: ", r + 1);
     int N;
     fscanf (fin, "%d", &N);
     int score[300];
     int total = 0;
     int sum = 0;
     for (int i = 0; i < N; i ++)
     {
         fscanf (fin, "%d", &score[i]);
         total += score[i];
     }
     sum = total;
     double frac[300];
     bool fix[300];
     for (int i = 0; i < N; i ++)
     {
         fix[i] = false;
     }
     int p = N;
     while (true)
     {
           int count = 0;
           int newtotal = total;
           int newN = N;
           for (int i = 0; i < p; i ++)
           {
               //fprintf (fout, "%lf ", frac[i] * 100);
               if (fix[i]) continue;
               frac[i] = 1.0 / N + (total + 0.0) / (N * sum + 0.0) - (score[i] + 0.0) / (sum + 0.0);
               if (frac[i] < 0.0)
               {
                  fix[i] = true;
                  frac[i] = 0.0;
                  count ++;
                  newtotal -= score[i];
                  newN --;
               }
           }
           //fprintf (fout, "\n");
           if (count == 0) break;
           total = newtotal;
           N = newN;
           if (N == 0) break;
           //if (total == 0) break;
     }
     for (int i = 0; i < p; i ++)
     {
         fprintf (fout, "%lf ", frac[i] * 100.0);
     }
/*     for (int i = 0; i < N; i ++)
     {
         double frac = 2.0 / N - (score[i] + 0.0) / (total + 0.0);
         if (frac <= 0.0) frac = 0.0;
         fprintf (fout, "%lf ", frac * 100.0);
     }*/
     fprintf (fout, "\n");
     return;
 }

int main ()
{
    int T;
    fscanf (fin, "%d", &T);
    for (int i = 0; i < T; i ++)
    {
        work (i);
    }
    return 0;
}
