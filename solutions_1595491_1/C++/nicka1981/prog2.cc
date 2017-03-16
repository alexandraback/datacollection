#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int cnt[101];
int surp[31];
int usurp[31];

char buf[101];

int main(int argc, char **argv) {
  
	int nC;

	gets(buf);
    sscanf(buf,"%i", &nC);

	for (int cs = 0; cs < nC; cs++) 
    {
      memset(cnt,0,sizeof(cnt));
	  int n, s, p;
	  scanf("%i",&n);
	  scanf("%i",&s);
	  scanf("%i",&p);

      for (int i = 0; i < n; i++) {
		int v;
		scanf("%i", &v);
        cnt[v]++;
      } 
	  int ret = cnt[30] + cnt[29];
	  if (p == 0) { ret += cnt[0]; }
      if (p <= 1) { ret += cnt[1]; }

	  memset(surp, 0, sizeof(surp));
	  memset(usurp, 0, sizeof(usurp));

	  for (int M = p; M <= 10; M++)
      for (int mid = M - 2; mid <= M; mid++)
      {
        if (M >= 2) {
          surp[M + mid + M-2] = 1;
        }
      }

	  for (int M = p; M <= 10; M++)
      for (int mid = M - 1; mid <= M; mid++)
      {
        if (M >= 1) {
          usurp[M + mid + M - 1] = 1;
		  usurp[M + mid + M] = 1;
        }
      }

      int a = 0;
      int b = 0;	
	  int ab = 0;
	  int nn = 0;

	  for (int i = 2; i <= 28; i++) {
        if ((surp[i] == 1) && (usurp[i] == 0)) {
            a += cnt[i];
		}
        if ((surp[i] == 0) && (usurp[i] == 1)) {
            b += cnt[i];
		}
        if ((surp[i] == 1) && (usurp[i] == 1)) {
            ab += cnt[i];
		}
        if ((surp[i] == 0) && (usurp[i] == 0)) {
            nn += cnt[i];
		}
	  }
      if (a >= s) {
        ret += s + b + ab;
      }
      else if (s - (a  + ab + nn) >= 0) {
		ret += ab + a + (b- (s - (a  + ab + nn)));
      }
      else {
        ret += a + b + ab;
      }

      printf("Case #%i: %i\n", cs + 1, ret);     
    }
}
