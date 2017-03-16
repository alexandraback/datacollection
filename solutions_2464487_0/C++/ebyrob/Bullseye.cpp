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
 *  unix  - :w | !g++ -o %.o % ; ./%.o A-example.in
 *                                              && instead of ; ?
 *  mswin - :w | !cl % & %:r.exe M-example.in
 *
 * where M-example.in could be: [ABCD]-(example|small|large).in
 */

/*
 * store one test case, both problem and solution, no intermediates
 */
typedef struct testcase_s {
   long long r;
   long long t;
   long long y;
} testcase;

/*
 * Process one test case, read input and fill in output within struct.
 */
void solve(testcase &tc)
{
   // tc.y = tc.r + tc.t;
//   r | 1b | 1w | 1b | 1w |
// 1mm paint = pi * 1^2
// factor out pi
// (r+1)^2 - r ^ 2 
// (r+3)^2 - (r+2) ^ 2

   long long tr = tc.t;
   long long i = 1;
   for( ; tr >= 0; i += 2 )
   {
      tr -= (tc.r + i) * (tc.r + i) - (tc.r + i - 1) * (tc.r + i - 1);
   }
   tc.y = (i - 3) / 2;
}

/*
 * Read in one test case from passed in file pointer.
 */
void readtestcase(testcase &tc, FILE *fp)
{
   fscanf(fp, "%lld %lld ", &tc.r, &tc.t);
}

/*
 * Write out one test case solution to passed in file pointer.
 */
void writetestcase(testcase &tc, FILE *fp)
{
   fprintf(fp, "%lld", tc.y);
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
