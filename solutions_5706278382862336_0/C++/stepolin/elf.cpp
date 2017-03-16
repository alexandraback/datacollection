#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cfloat>

using namespace std;

#define M 13
char s[2*M+2];

int main() {
  int T;
  cin >> T;
  for (int test=1; test <= T; test++) {
  	
  	long long p, q;
  	int g=1;
  	bool b=false, t=false;
  	double d;
  	
  	scanf("%I64d/%I64d", &p, &q);
  	if (p==1 && q ==1) {
  		b = true;	
  		g = 1;
  		goto fine;
  	}
  	
  	d = (double)p/q;
  	for (int i=1; i <= 40; i++) {
  		d *= 2;
  		if (d == 1) {
				b = true;
				if (!t) g = i;
				break;
			}
  		else if (d > 1) {
  			if (!t) g=i, t=true;
  			d -= 1;
  		}
			else
				continue;
  	}

fine:
    printf("Case #%d: ", test);
		if (b)
			printf("%d\n", g);
		else
			printf("impossible\n");
	}

  return 0;
}

