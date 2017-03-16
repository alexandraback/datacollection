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
 *  mswin - :w | !cl % & %:r.exe A-example.in
 *
 * where M-example.in could be: [ABCD]-(example|small|large).in
 */

/*
 * store one test case, both problem and solution, no intermediates
 */
typedef struct testcase_s {
   char member[1000001];
   int n;
   int nvalue;
} testcase;

const char vowels[] = "aeiou";

/*
 * Process one test case, read input and fill in output within struct.
 */
void solve(testcase &tc)
{
   // tc.nvalue = strlen(tc.member);

   // tsetse
   // 123456
   // 654321

   // ts....  = 1x5
   // x..ts.  = 3x2
   //     sum = 5 + 6 = 11

   // printf("name=%s\n", tc.member);

   int len = strlen(tc.member);
   int n = 0;
   int laststart = -1;
   tc.nvalue = 0;
   for( int i=0; i<len; ++i )
   {
      if( NULL != strchr(vowels, tc.member[i] ) )
      {
         n = 0;
      }
      else
      {
         ++n;
      }
      if( n >= tc.n )
      {
         // go left to last start. 
         int s = i - tc.n + 1;
         int e = i;
         int numstarts = s - laststart;
         int numends = len - e;

         // printf("i = %d, numstarts = %d, numends = %d, strings = %d\n", i, numstarts, numends, numstarts * numends);
         tc.nvalue += numstarts * numends;
         laststart = s;
      }
   }
}

/*
 * Read in one test case from passed in file pointer.
 */
void readtestcase(testcase &tc, FILE *fp)
{
   fscanf(fp, "%s %d ", tc.member, &tc.n);
}

/*
 * Write out one test case solution to passed in file pointer.
 */
void writetestcase(testcase &tc, FILE *fp)
{
   fprintf(fp, "%d", tc.nvalue);
}

testcase cases[100];

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
