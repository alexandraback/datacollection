#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// using namespace std;

/* 
 * runme:
 *   g++ -o filename.o filename.cpp
 *   ./filename.o M-example.in
 *
 * runme vim:
 *  unix  - :w | !g++ -o %.o % ; ./%.o C-example.in
 *                                              && instead of ; ?
 *  mswin - :w | !cl % & %:r.exe M-example.in
 *
 * where M-example.in could be: [ABCD]-(example|small|large).in
 */

/*
 * store one test case, both problem and solution, no intermediates
 */
typedef struct testcase_s {
   int r;
   int n;
   int m;
   int k;
   int products[8000][12];
   char digits[8000][12];
} testcase;

int compareint(const void *a, const void *b)
{
   return ( *(int*)a - *(int*)b );
}

int realsolve(int n, int m, int k, int products[12])
{
   //printf("\n");
   qsort(products, k, sizeof(int), compareint);

   int numnums = 1;
   for( int i=0; i<n; ++i )
      numnums *= m - 1;
   int numtestproducts = pow(2,n);
   int testproducts[numnums][numtestproducts];
   for( int i=0; i<numnums; ++i )
   {
      char digits[12] = {0};
      int num = i;
      int d = 0;
      while( d < n )
      {
         digits[d++] = '2' + (num % (m - 1));
         num /= m - 1;
      }
      // printf("digits = %s\n", digits);

      for( int j = 0; j<numtestproducts; ++j )
      {
         int prod = 1;
         for( int d = 0; d < n; ++d )
            if( j & (d+1) ) prod *= digits[d] - '0';
         testproducts[i][j] = prod;
      }
   }

   // find testproducts[i][*] which contains most of products
   int maxnumfound = 0;
   int maxfoundnum = -1;
   for( int i=0; i<numnums; ++i )
   {
      int numfound = 0;
      for(int j=0; j<k; ++j )
      {
         for( int l = 0; l<numtestproducts; ++l )
         {
            if( products[j] == testproducts[i][l] )
            {
               ++numfound;
               break;
            }
         }
      }
      if( numfound > maxnumfound )
      {
         maxnumfound = numfound;
         maxfoundnum = i;
      }
   }
   printf("maxnumfound = %d, k = %d\n", maxnumfound, k);
   return maxfoundnum;
}

/*
 * Process one test case, read input and fill in output within struct.
 */
void solve(testcase &tc)
{
   // randomly picks N numbers between 2 and M
   // K times, take random subset (50% odds each card chosen) could be 0-N cards
   //          calculate the product (n1 * n2 ...) show all K products.
   // goal: guess knowing just M, N and the products.  
   // each R row is one "game" in this fashion...

   // solve one row at a time. 

   for( int i=0; i<tc.r; ++i )
   {
      int g = realsolve(tc.n,tc.m,tc.k,tc.products[i]);
      int d = 0;
      while( d < tc.n )
      {
         tc.digits[i][d++] = '2' + (g % (tc.m - 1));
         g /= tc.m - 1;
      }
   }

}

/*
 * Read in one test case from passed in file pointer.
 */
void readtestcase(testcase &tc, FILE *fp)
{
   fscanf(fp, "%d %d %d %d ", &tc.r, &tc.n, &tc.m, &tc.k);
   for( int i=0; i<tc.r; ++i )
   {
      for( int j=0; j<tc.k; ++j )
      {
         fscanf(fp, "%d ", &tc.products[i][j]);
      }
   }
}

/*
 * Write out one test case solution to passed in file pointer.
 */
void writetestcase(testcase &tc, FILE *fp)
{
   for( int i=0; i<tc.r; ++i )
   {
      fprintf(fp, "\n");
      for( int j=0; j<tc.n; ++j )
         fprintf(fp, "%c", tc.digits[i][j]);
   }
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
