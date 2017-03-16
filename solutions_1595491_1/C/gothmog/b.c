#include <stdio.h>

void test_googler(int total_score, int p, int *best, int *surprising)
{
   int s1 = total_score / 3;
   int s2 = total_score / 3;
   int s3 = total_score / 3;

   if( (s1+s2+s3) < total_score) s1++;     /* We are at most two away in total - but since not surprising this can only be 1 per score */
   if( (s1+s2+s3) < total_score) s2++;

   if (s1 >= p) /* s1 is either the biggest or equal to the biggest) */
   {
      *best = s1;
      *surprising = 0;
      return; /* Did it without being surprising */
   }
   else /* Surprising cases */
   {
      s1 = total_score / 3;
      s2 = total_score / 3;
      s3 = total_score / 3;

      if( (s1+s2+s3+2) == total_score)      /* We are at most two away in total - if we can be surprising we may hit p */
      {
         s1 += 2;
         if(s1 >= p)
         {
            *best = s1;
            *surprising = 1;
         }
         return;
      }

      if( (s2 > 0) && ((s1+s2+s3) == total_score))     /* We can do one up-one down assuming that we are not zero */
      {
         s1 += 1;
         s2 -= 1;
         if(s1 >= p)
         {
            *best = s1;
            *surprising = 1;
         }
         return;
      }
   }
}

#define MAX_GOOGLERS 200
int main(int argc, char *argv[])
{
   if(argc == 2)
   {
      FILE *fp = NULL;
      char *filename = argv[1];
      int p = 0;
      int n_googlers = 0;
      int n_surprising = 0;
      int googler_score[MAX_GOOGLERS];
      int test_cases = 0;
      int i = 0;
      int n = 0;

      fp = fopen(filename, "rt");

      if(fp)
      {
         fscanf(fp, "%d", &test_cases);

         for(i=1; i<=test_cases; i++)
         {
            int count = 0;

            fscanf(fp, "%d %d %d", &n_googlers, &n_surprising, &p);

            for(n=0; n < n_googlers; n++)
            {
               fscanf(fp, "%d", &googler_score[n]);
            }

            for(n=0; n < n_googlers; n++)
            {
               int best = 0;
               int surprising = 0;

               test_googler(googler_score[n], p, &best, &surprising);

               if(best >= p)
               {
                  if(surprising == 0)
                  {
                     count++;    /* Did it without being surprising */
                  }
                  else
                  {
                     if(n_surprising > 0)
                     {
                        count++; /* We did it by being surprising */
                        n_surprising--; /* Lose a life */
                     }
                  }
               }
            }
            printf("Case #%d: %d\n", i, count);
         }
         fclose(fp);
      }
   }

   return 0;
}
