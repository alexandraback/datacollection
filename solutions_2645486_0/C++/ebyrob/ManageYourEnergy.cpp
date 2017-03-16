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
 *  unix  - :w | !g++ -o %.o % ; ./%.o B-example.in
 *                                              && instead of ; ?
 *  mswin - :w | !cl % & %:r.exe M-example.in
 *
 * where M-example.in could be: [ABCD]-(example|small|large).in
 */

/*
 * store one test case, both problem and solution, no intermediates
 */
typedef struct testcase_s {
   int e;
   int r;
   int n;
   int v[10000];
   int y;
} testcase;

int rsolve(testcase &tc, int i, int e)
{
   if( tc.n == i )
      return 0;

   if( e > tc.e )
      e = tc.e;

   int min = e + tc.r - tc.e;
   if( min < 0 ) min = 0;
   int max = e;

   int maxgain = 0;
   for( int s = 0; s <= e; ++s )
   {
      int g = s * tc.v[i];
      int g2 = rsolve(tc, i+1, e - s + tc.r);
//      printf("i=%d, g = %d, g2 = %d ", i, g);
      if( g + g2 > maxgain )
         maxgain = g + g2;
   }
   return maxgain;
}

/*
 * Process one test case, read input and fill in output within struct.
 */
void solve(testcase &tc)
{
   int e = tc.e; // start with E joules of energy for the day.
                 // never below 0 or drop from exhaustion.
   // gain = v[i] * spent
   // maximize gain for the day.  (must activate in order)

   tc.y = rsolve(tc, 0, tc.e);
//   printf("\n");
}

/*
 * Read in one test case from passed in file pointer.
 */
void readtestcase(testcase &tc, FILE *fp)
{
   fscanf(fp, "%d %d %d ", &tc.e, &tc.r, &tc.n);
   for( int i=0; i<tc.n; ++i )
      fscanf(fp, " %d ", &tc.v[i]);
}

/*
 * Write out one test case solution to passed in file pointer.
 */
void writetestcase(testcase &tc, FILE *fp)
{
   fprintf(fp, "%d", tc.y);
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
