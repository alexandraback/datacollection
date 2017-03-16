#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

char buf[101];

int ndigits(int x) {
  int ret = 0;
  while (x > 0) { ret++; x /= 10; }
  return ret;
}

int lev[12];

int main(int argc, char **argv) {
  
	int nC;

	gets(buf);
    sscanf(buf,"%i", &nC);

	lev[0] = 1;
	for (int i = 1; i < 12; i++) { lev[i] = lev[i-1]*10; }

	for (int cs = 0; cs < nC; cs++) 
    {
	  int n1, n2;
	  scanf("%i",&n1);
	  scanf("%i",&n2);

      int c1 = 0;
	  int c2 = 0;

	  for (int p = n1; p <= n2; p++) {
		int dig = ndigits(p);
		
        int x = p;
		for (int s = 0; s + 1 < dig; s++) {
          x = (x%10)*lev[dig-1]+(x/10);
		  if (x == p) { break; }
		  if ((x > p)&&(x<=n2)) { c1++; }
        }
		x = p;
		while (x*10 <= n2) { x *= 10; c1++; }
      }

	  int ret = c1 + c2;
 
      printf("Case #%i: %i\n", cs + 1, ret);     
    }
}
