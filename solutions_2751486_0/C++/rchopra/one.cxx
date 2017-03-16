
#include <stdio.h>
#include <string.h>

bool check(char* str, int j, int n, int slen) {
  if ( (j+n)>slen ) 
     return false;
  int i =j;
  for(i =j; i<(j+n); i++) {
    char c = str[i];
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
       return false;
    }
  }
  return true;
}

int main(int argc, char**argv) {
  FILE *fp = fopen(argv[1], "r");
  int tcount;
  fscanf(fp, "%d\n", &tcount);
  int i =1;
  for(i=1; i<=tcount; i++) {
    char str[1000001];
    int n;
    fscanf(fp, "%s %d\n", str, &n);
    int slen = strlen(str);
    int prev_cons = -1;
    long long unsigned nval = 0;
    int j =0;
    for(j =0; j<slen; j++) {
      // check for n-consonants
      if (check(str, j, n, slen)) {
        nval += ( (j-prev_cons)*(slen-(j+n)+1) );
        prev_cons = j;
      }
    }
    printf("Case #%d: %llu\n", i, nval);
  }
  fclose(fp);
  return 0;
}

