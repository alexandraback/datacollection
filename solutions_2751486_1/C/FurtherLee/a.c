#include <stdio.h>
#include <string.h>

FILE *fin = NULL;
FILE *fout = NULL;

char name[1000010];

long n;

long strl;

int isCon(char c) {
  return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

long long calc() {
  long long ret = 0;
  long lastT = 0;
  long t = 0;
  long lastInd = 0;
  long lastSatInd = 0;
  long totalT = 0;
  long i;
  
  strl = strlen(name);

  for (i = 0; i < strl; ++i) {
    if (isCon(name[i])) {
      if (lastInd == i - 1) {
	t++;
	lastInd = i;
	if (t >= n) {
	  lastSatInd = i;
	  ret += i - n + 2;
	}
	else {
	  if (lastSatInd > 0)
	    ret += lastSatInd - n + 2;
	}
      }
      else {
	t = 1;
	lastInd = i;

	if (t >= n) {
	  lastSatInd = i;
	  ret += i - n + 2;
	}
	else {
	  if (lastSatInd > 0)
	    ret += lastSatInd - n + 2;
	}
      }
    }
    else {
      if (lastSatInd > 0)
	ret += lastSatInd - n + 2;
    }
    //    printf("%s %ld %ld %ld %lld\n", &name[i], i, t, lastSatInd, ret);
  }

  /*  
  for(i = 0; i < strl; ++i) {
    if (isCon(name[i])) {
      if (lastInd == i - 1) {
	t++;
	lastInd++;
	if (t >= n)
	  ret += i - n + 2;
	else {
	  if (lastT >= n) 
	    ret += totalT;
	}
	printf("%s %ld %ld %lld\n", &name[i], i, t, ret);
      }
      else {
	t = 1;
	lastInd = i;
	if (t >= n)
	  ret += i - n + 2;
	else {
	  if (lastT >= n) 
	    ret += totalT;	
	}
	printf("%s %ld %ld %lld\n", &name[i], i, t, ret); 
     }
    }
    else {
      if (lastInd == i - 1) {
	if (t >= n)
	  totalT += t - n + 1;
	lastT = t;
	t = 0;
      }
      
      if (lastT
    }
  }
  */

  return ret;
}

void work(int caseNum) {
  fscanf(fin, "%s %ld", name, &n);
  fprintf(fout, "Case #%d: %lld\n", caseNum, calc());
}

int main() {
  int cases, i;
  fin = fopen("a.in", "r");
  fout = fopen("a.out", "w");
  
  fscanf(fin, "%d", &cases);  
  for(i = 1; i <= cases; ++i) 
    work(i);
  close(fin);
  close(fout);
  
  return 0;
}

