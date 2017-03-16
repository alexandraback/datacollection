// #include <stdlib.h>
#include <stdio.h>
#include <string.h>

// using namespace std;

/* 
 * runme:
 *   g++ -o filename.o filename.cpp
 *   ./filename.o M-example.in
 *
 * runme vim:
 *  unix  - :w | !g++ -o %.o % ; ./%.o C-example.in
 *                                              && instead of ; ?
 *  mswin - :w | !cl % & %:r.exe C-example.in
 *
 * where M-example.in could be: [ABCD]-(example|small|large).in
 */

typedef struct tribe_s {
   int d;  // first attack day
   int n;  // total attacks
   int w;  // westmost first
   int e;  // eastmost first
   int s;  // strength
   int dd; // days per attack
   int dp; // change in position
   int ds; // change in str
} tribe;

/*
 * store one test case, both problem and solution, no intermediates
 */
typedef struct testcase_s {
   int n;
   tribe tribes[1000];
   int succeeded;
} testcase;

int wall[10000000];

/*
 * Process one test case, read input and fill in output within struct.
 */
void solve(testcase &tc)
{
   // wall builds night after attack.  of height s to barely stop attack.
/*
   printf("\n");
   for( int j=0; j<tc.n; ++j )
   {
      tribe *t = &tc.tribes[j];
      printf("%d %d %d %d %d %d %d %d\n",
            t->d, t->n, t->w, t->e, t->s, t->dd, t->dp, t->ds);
   }
*/

   memset(wall, 0, sizeof(wall));
   tc.succeeded = 0;
   for( int i=0; i<=676060; ++i )
   {
      for( int j = 0; j < tc.n; ++j )
      {
         tribe *t = &tc.tribes[j];
         if( i < t->d ) continue;
         if( (i - t->d) % t->dd != 0 ) continue;
         int an = (i - t->d) / t->dd;
         if( an >= t->n ) continue;

         // printf("i = %d, d = %d, dd = %d, an = %d, n=%d\n", i, t->d, t->dd, an, t->n);

         int e = t->e + an * t->dp;
         int w = t->w + an * t->dp;
         int s = t->s + an * t->ds;

         // printf("d%d, w = %d, e = %d, s = %d ", i, w, e, s);
         for( int k = w*2; k <= e*2; ++k )
         {
            if( wall[k + 5000000] < s )
            {
               ++tc.succeeded;
               // printf("succeeded");
               break;
            }
         }
         // printf("\n");
      }
      for( int j = 0; j < tc.n; ++j )
      {
         tribe *t = &tc.tribes[j];
         if( i < t->d ) continue;
         if( (i - t->d) % t->dd != 0 ) continue;
         int an = (i - t->d) / t->dd;
         if( an >= t->n ) continue;

         int e = t->e + an * t->dp;
         int w = t->w + an * t->dp;
         int s = t->s + an * t->ds;

         for( int k = w*2; k <= e*2; ++k )
         {
            if( wall[k + 5000000] < s )
               wall[k + 5000000] = s;
         }
      }
   }
}

/*
 * Read in one test case from passed in file pointer.
 */
void readtestcase(testcase &tc, FILE *fp)
{
   fscanf(fp, "%d ", &tc.n);
   for( int i=0; i<tc.n; ++i )
   {
      tribe *t = &tc.tribes[i];
      fscanf(fp, 
            "%d %d %d %d %d %d %d %d ",
            &t->d, &t->n, &t->w, &t->e, &t->s, &t->dd, &t->dp, &t->ds
            );
   }
}

/*
 * Write out one test case solution to passed in file pointer.
 */
void writetestcase(testcase &tc, FILE *fp)
{
   fprintf(fp, "%d", tc.succeeded);
}

/*
 * Process command line argument (input file), count test cases, call solve().
 */
int main(int argc, char **argv)
{
   FILE *in = stdin;
   FILE *out = stdout;
   if( argc >= 2 )
   {
      char outname[256];
      const char *end = strrchr(argv[1], '.');
      int len = NULL == end ? strlen(argv[1]) : end - argv[1];
      sprintf(outname, "%.*s.out", len, argv[1]);
      in = fopen(argv[1], "r");
      out = fopen(outname, "w");
   }

   int t;
   fscanf(in, "%d ", &t);
   testcase cases[t];
   for( int i=0; i<t; ++i )
   {
      readtestcase(cases[i], in);
   }
   fclose(in);

   for( int i = 0; i < t; ++i )
   {
      solve(cases[i]);
      
      fprintf(out, "Case #%d: ", 1 + i);
      writetestcase(cases[i], out);
      fprintf(out, "\n"); 
      fflush(out);
   }
   fclose(out);
}
