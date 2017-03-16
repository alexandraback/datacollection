#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef long long lnt;


lnt Abs(lnt k) { return k < 0 ? -k : k; }


void Update(lnt& aa, lnt& bb, const char* s1, const char* s2) {
  lnt a = atoll(s1);
  lnt b = atoll(s2);
  if (aa == -1 ||
      Abs(aa - bb) > Abs(a - b) ||
      Abs(aa - bb) == Abs(a - b) && a < aa ||
      Abs(aa - bb) == Abs(a - b) && a == aa && b < bb) {
    aa = a;
    bb = b;
  }
}


void Fill(char* s, int i0, int n, int k) {
  for (int i = i0; i < n; ++i) {
    if (s[i] == '?') {
      s[i] = '0' + k;
    }
  }
}


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    static char s1[20], s2[20];
    scanf("%s %s", s1, s2);

    int n = strlen(s1);

    lnt aa = -1, bb = -1;
    static char s3[20], s4[20];
    for (int i = 0; i < n; ++i) {
      if (s1[i] != '?' && s2[i] != '?') {
        if (s1[i] < s2[i]) {
          Fill(s1, i + 1, n, 9);
          Fill(s2, i + 1, n, 0);
          break;
        }
        if (s1[i] > s2[i]) {
          Fill(s1, i + 1, n, 0);
          Fill(s2, i + 1, n, 9);
          break;
        }
      } else if (s1[i] == '?' && s2[i] == '?') {
        strcpy(s3, s1);
        strcpy(s4, s2);
        s3[i] = '0';
        s4[i] = '1';
        Fill(s3, i + 1, n, 9);
        Fill(s4, i + 1, n, 0);
        Update(aa, bb, s3, s4);

        strcpy(s3, s1);
        strcpy(s4, s2);
        s3[i] = '1';
        s4[i] = '0';
        Fill(s3, i + 1, n, 0);
        Fill(s4, i + 1, n, 9);
        Update(aa, bb, s3, s4);

        s1[i] = '0';
        s2[i] = '0';
      } else if (s1[i] == '?') {
        if (s2[i] != '0') {
          strcpy(s3, s1);
          strcpy(s4, s2);
          s3[i] = s2[i] - 1;
          Fill(s3, i + 1, n, 9);
          Fill(s4, i + 1, n, 0);
          Update(aa, bb, s3, s4);
        }
        if (s2[i] != '9') {
          strcpy(s3, s1);
          strcpy(s4, s2);
          s3[i] = s2[i] + 1;
          Fill(s3, i + 1, n, 0);
          Fill(s4, i + 1, n, 9);
          Update(aa, bb, s3, s4);
        }
        s1[i] = s2[i];
      } else {
        if (s1[i] != '9') {
          strcpy(s3, s1);
          strcpy(s4, s2);
          s4[i] = s1[i] + 1;
          Fill(s3, i + 1, n, 9);
          Fill(s4, i + 1, n, 0);
          Update(aa, bb, s3, s4);
        }
        if (s1[i] != '0') {
          strcpy(s3, s1);
          strcpy(s4, s2);
          s4[i] = s1[i] - 1;
          Fill(s3, i + 1, n, 0);
          Fill(s4, i + 1, n, 9);
          Update(aa, bb, s3, s4);
        }
        s2[i] = s1[i];
      }
    }
    Update(aa, bb, s1, s2);

    static char fmt[1000];
    sprintf(fmt, "Case #%%d: %%0%dlld %%0%dlld\n", n, n);
    printf(fmt, case_idx, aa, bb);
  }
  return 0;
}
