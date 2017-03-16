#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPalindrome(long long num) 
{
  int nDigits = 0;
  long long tmpNum = num;
  int a[200];
  while (tmpNum > 0) {
    a[nDigits] = tmpNum % 10;
    tmpNum /= 10;
    nDigits++;
  }
  //printf("number of digits in %lld is %d\n", num, nDigits);

  int ndigs;
  for (ndigs = 0; ndigs < nDigits/2; ndigs++) {
    if (a[ndigs] != a[nDigits-ndigs-1])
      return false;
  }
  return true;
}

long long isSquare(long long num) 
{
  long long root = (long long) (sqrt(num));
  if (root*root == num) {
    return root;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) 
{
  FILE *fin, *fout;
  int i, nsets;

  fout = fopen(argv[2], "w");
  fin = fopen(argv[1], "r");
  fscanf(fin, "%d", &nsets); 
  for (i = 0; i < nsets; i++) {

    long long min, max, num;
    int fairSqaure = 0;
    fscanf(fin, "%lld %lld", &min, &max);
    long long numRoot = (long long) sqrt(min);
    num = numRoot*numRoot;
    while (num <= max)
    {
      if (num < min) {
        numRoot++;
        num = numRoot*numRoot;
        continue;
      }
      if ((isPalindrome(numRoot)) && (isPalindrome(num))) {
        printf("fair and sqaure %lld %lld\n",num, numRoot);
        fairSqaure++;
      }
      numRoot++;
      num = numRoot*numRoot;
    }
    fprintf(fout, "Case #%d: %d\n", i+1, fairSqaure);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
