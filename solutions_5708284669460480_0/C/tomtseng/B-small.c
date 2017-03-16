#include <stdio.h>
#include <string.h>

char keys[7];
char Ltarget[7];
char testStr[7];

void carryTheOne(int S, int K) {
  int i;
  for (i = 0; i < S-1; i++) {
    if (testStr[i] >= K) {
      testStr[i] = 0;
      testStr[i+1]++;
    }
  }
}

int countOccurrences(int L, int S) {
  int i, j, count = 0, sawWord;
  for (i = 0; i <= S-L; i++) {
    sawWord = 1;
    for (j = 0; j < L; j++) {
      if (keys[testStr[i+j]] != Ltarget[j]) {
        sawWord = 0; break;
      }
    }
    if (sawWord) count++;
  }
  return count;
}

double tryAllStrings(int K, int L, int S) {
  int i, totalCount = 0, maxBananas = 0, tmp;
  memset(testStr,0,sizeof(char)*7);

  int maxString = 1;
  for (i = 0; i < S; i++) {
    maxString *= K;
  }
  for (i = 0; i < maxString; i++) {
    carryTheOne(S, K);
    tmp = countOccurrences(L, S);
    maxBananas = maxBananas < tmp ? tmp : maxBananas;
    totalCount += tmp;
    testStr[0]++;
  }

  return (double)maxBananas - ((double)totalCount)/maxString;
}

int main() {
  int T, K, L, S, i, j, minBananas;
  double prob;
  FILE *fin = fopen("B.in", "r");
  FILE *fout = fopen("B.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    prob = 0.0;
    fscanf(fin, "%d %d %d\n", &K, &L, &S);
    for (j = 0; j < K; j++) { // read keyboard
        fscanf(fin, " %c", &(keys[j]));
    }
    for (j = 0; j < L; j++) {
        fscanf(fin, " %c", &(Ltarget[j]));
    }
    prob = tryAllStrings(K, L, S);
    fprintf(fout, "Case #%d: %.7lf\n", i, prob);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
