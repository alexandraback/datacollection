#include <cstdio>
#include <cstdlib>

FILE * fin = fopen ("A-small-attempt0.in", "r"), * fout = fopen ("a-small.out", "w");

int count[1000000];
     
int flip (int i)
{
    int re = 0;
    while (i > 0)
    {
          int tmp = i % 10;
          re = re * 10 + tmp;
          i = i / 10;
    }
    return re;
}

void work (int r)
{
     fprintf (fout, "Case #%d: ", r);
     int N;
     fscanf (fin, "%d", &N);
     count[N - 1] = 1;
     for (int i = 1; i < N; i ++)
     {
         count[N - 1 - i] = 1 + count[N - i];
         int tmp = flip(N - i);
         if (tmp > N - i && tmp <= N && count[tmp - 1] + 1 < count[N - 1 - i])
         {
            count[N - 1 - i] = count[tmp - 1] + 1;
         }
         //fprintf (fout, "(%d, %d)", N - i - 1, count[N - i - 1]);
     }
     fprintf (fout, "%d\n", count[0]);
     return;
}

int main ()
{
    int T;
    fscanf (fin, "%d", &T);
    //printf ("%d", T);
    for (int i = 0; i < T; i ++)
    {
        work (i + 1);
    }
    //while (1);
    return 0;
}