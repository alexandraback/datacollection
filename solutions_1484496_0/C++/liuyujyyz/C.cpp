#include <cstdio>
#include <cstdlib>

FILE * fin = fopen ("C-small-attempt1.in", "r"),  * fout = fopen ("C-small.out", "w");

int ele[1000];
int re1[20], re2[20];

bool find (int t, int q)
{
     if (t == 0) return true;
     for (int i = 0; i < q; i ++)
     {
         if (t < ele[i]) continue;
         re2[q - 1] = ele[i];
         t -= ele[i];
         int tmp = ele[i];
         ele[i] = ele[q - 1];
         ele[q - 1] = tmp;
         if (find (t, q - 1)) return true;
         re2[q - 1] = 0;
         ele[q - 1] = ele[i];
         ele[i] = tmp;
         t += ele[i];
     }
     return false;
}

bool find_in (int t, int q)
{
     if (t < 0) return false;
     if (t == 0) return true;
     for (int i = 0; i < q; i ++)
     {
         re2[20 - q] = ele[q - 1 - i];
         t -= ele[q - 1 - i];
         int tmp = ele[q - 1 - i];
         ele[q - 1 - i] = ele[q - 1];
         ele[q - 1] = tmp;
         if (find (t, q - 1)) return true;
         re2[20 - q] = ele[q - 1 - i];
         t += ele[q - 1 - i];
         ele[q - 1] = ele[q - 1 - i];
         ele[q - 1 - i] = tmp;
     }
     return false;
}

void dele ()
{
     for (int i = 0; i < 20; i ++)
     {
         for (int j = 0; j < 20; j ++)
         {
             if (re1[i] == re2[j])
             {
                re1[i] = 0;
                re2[j] = 0;
             }
         }
     }
}

void work (int r)
{
     for (int i = 0; i < 0; i ++)
          int ga = rand () % 2;
     fprintf (fout, "Case #%d:\n", r);
     int N;
     fscanf (fin, "%d", &N);
     int sum = 0;
     for (int i = 0; i < N; i ++)
     {
         re1[i] = re2[i] = 0;
         fscanf (fin, "%d", &ele[i]);
         sum += ele[i];
     }
     bool found = false;
     for (int i = 0; i < 2000; i ++)
     {
         int p = 0;
         for (int k = 0; k < N; k ++)
         {
             if (rand () % 4 == 0) re1[k] = ele[k];
             else re1[k] = 0;
             p += re1[k];
         }
         if (p == 0) continue;
         printf ("%d %d\n", i, p);
         bool t = find (p, N);
         dele ();
         int q = 0;
         for (int j = 0; j < N; j ++) q += re1[j];
         if (q != 0)
         {
               found = true;
                     //fprintf (fout, "p1:");
                    for (int j = 0; j < N; j ++)
                    {
                        if (re1[j] != 0)
                           fprintf (fout, "%d ", re1[j]);
                    }
                    fprintf (fout, "\n");
                    for (int j = 0; j < N; j ++)
                    {
                        if (re2[j] != 0)
                           fprintf (fout, "%d ", re2[j]);
                    }
                    fprintf (fout, "\n");
                    break;
         }
     }
     if (!found) fprintf (fout, "Impossible\n");
     return;
}

int main ()
{
    int T;
    fscanf (fin, "%d", &T);
    for (int i = 0; i < T; i ++)
    {
        work (i + 1);
    }
    return 0;
}
