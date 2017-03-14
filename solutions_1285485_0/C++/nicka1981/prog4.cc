#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char buf[101];
char m[101][101];
/*
char fm[5001][5001];
*/
int gcd(int a, int b) {
  if (a < 0) { return gcd(-a,b); }
  if (b < 0) { return gcd(a,-b); }
  if (a == 0) { return b; }
  if (b == 0) { return a; }
  if (a < b) { return gcd(b,a); }
  return gcd(a%b, b);
}

int h, w, d;
int sw;
int sh;

int w0;
int h0;

int w0orig;
int h0orig;

int getExp(int k, int l) {
  return m[k/sh][l/sw];
}

void buildIt(int a, int b)
{
  sw = b;
  if (sw < 0) { sw = -b; }
  if (sw == 0) { sw = 1; }

  sh = a;
  if (sh < 0) { sh = -a; }
  if (sh == 0) { sh = 1; }

  sw *= 2;
  sh *= 2;

  h0 = (h0orig*sh) + sh/2;
  w0 = (w0orig*sw) + sw/2;
/*       
   	  for (int i = 0; i < h; i++) {
   	    for (int j = 0; j < w; j++) {
		  int iCheck = i;
		  int jCheck = j;

          if (m[iCheck][jCheck] == '#') {
            for (int k = (i*sh); k < (i+1)*sh; k++) {
			  for (int l = (j*sw); l < (j+1)*sw; l++) {
                fm[k][l] = '#';
              }
            }
		  }
          else {
            if (m[iCheck][jCheck] == 'X') {

            }
            for (int k = (i*sh); k < (i+1)*sh; k++) {
			  for (int l = (j*sw); l < (j+1)*sw; l++) {
                fm[k][l] = '.';
              }
            }
          }
        }
      }
*/
/*
  if (a == 1 && b == 1) {
  printf("%i %i\n",h0,w0);
  for (int i = 0; i < h*sh; i++) {	  	
	for (int j = 0; j < w*sw; j++) {
      printf("%c",fm[i][j]);
    }
    printf("\n");
  }
  }
*/
}

int tryIt(int a, int b)
{
  buildIt(a,b);

  double dStep;
  int sH;
  int sW;

  if (b > 0) { sH = 1; } 
  if (b < 0) { sH = -1; } 
  if (b == 0) { sH = 0; }

  if (a > 0) { sW = 1; } 
  if (a < 0) { sW = -1; } 
  if (a == 0) { sW = 0; } 

  if (a == 0) { 
	dStep = 1.0/sw;
  }
  else if (b == 0) {
	dStep = 1.0/sh;
  }
  else {
    dStep = sqrt(1.0/(sw*sw) + 1.0/(sh*sh));
  }

  int pw = w0;
  int ph = h0;
	
  double dTrav = 0;
  while (true) {
    dTrav += dStep;

	if (dTrav > d + 1e-9) {
        return 0;
    }
    pw += sW;
	ph += sH;

    if ((pw == w0)&&(ph == h0)) {
      return 1;
    }

    char uw = getExp(ph-1,pw-1);
    char ue = getExp(ph-1,pw);
    char lw = getExp(ph,pw-1);
    char le = getExp(ph,pw);

	if ((sW > 0) && (sH < 0)) {
		if ((uw == '#')&&(ue == '#')&&(le == '#')) {
            sW *= -1;
            sH *= -1;
        }
		if ((uw == '#')&&(ue == '#')&&(le != '#')) {
            sH *= -1;
        }
		if ((uw != '#')&&(ue == '#')&&(le == '#')) {
            sW *= -1;
        }
		if ((uw != '#')&&(ue == '#')&&(le != '#')) {
            return 0;
        }
    }

	if ((sW > 0) && (sH > 0)) {
		if ((lw == '#')&&(ue == '#')&&(le== '#')) {
            sW *= -1;
            sH *= -1;
        }
		if ((lw == '#')&&(le == '#')&&(ue != '#')) {
            sH *= -1;
        }
		if ((lw != '#')&&(le == '#')&&(ue == '#')) {
            sW *= -1;
        }
		if ((lw != '#')&&(le == '#')&&(ue != '#')) {
            return 0;
        }
    }

	if ((sW < 0) && (sH < 0)) {
		if ((uw == '#')&&(ue == '#')&&(lw == '#')) {
            sW *= -1;
            sH *= -1;
        }
		if ((uw == '#')&&(ue == '#')&&(lw != '#')) {
            sH *= -1;
        }
		if ((uw == '#')&&(ue != '#')&&(lw == '#')) {
            sW *= -1;
        }
		if ((uw == '#')&&(ue != '#')&&(lw != '#')) {
            return 0;
        }
    }

	if ((sW < 0) && (sH > 0)) {
		if ((uw == '#')&&(lw == '#')&&(le == '#')) {
            sW *= -1;
            sH *= -1;
        }
		if ((uw == '#')&&(lw == '#')&&(le != '#')) {
            sW *= -1;
        }
		if ((uw != '#')&&(lw == '#')&&(le == '#')) {
            sH *= -1;
        }
		if ((lw == '#')&&(uw != '#')&&(le != '#')) {
            return 0;
        }
    }

	if ((sW > 0) && (sH == 0)) {
        if ((ue == '#')&&(le == '#')) { sW *= -1; }
    }
	if ((sW < 0) && (sH == 0)) {
        if ((uw == '#')&&(lw == '#')) { sW *= -1; }
    }
	if ((sW == 0) && (sH > 0)) {
        if ((lw == '#')&&(le == '#')) { sH *= -1; }
    }
	if ((sW == 0) && (sH < 0)) {
        if ((uw == '#')&&(ue == '#')) { sH *= -1; }
    }
  }
}


int main(int argc, char **argv) {
  
	int nC;

	gets(buf);
    sscanf(buf,"%i", &nC);

	for (int cs = 0; cs < nC; cs++) 
    {
	  scanf("%i",&h);
	  scanf("%i",&w);
	  scanf("%i",&d);

	  for (int i = 0; i < h; i++) {
		scanf("%s",m[i]);
      }

   	  for (int i = 0; i < h; i++) {
 	  for (int j = 0; j < w; j++) {
		if (m[i][j] == 'X') {
          w0orig = j;
          h0orig = i;
        }
      }
      }

	  //int checkCnt = 0;
	  int ret = 0;
	  for (int a = -31; a <= 31; a++) {
		for (int b = -31; b <= 31; b++) {
		  if ((a == 0) && (b == 0)) {
            continue;
          }
          if (gcd(a,b) != 1) { continue; }
		//  checkCnt++;
          ret += tryIt(a,b);
	    }
      }
      
	  printf("Case #%i: %i\n", cs + 1, ret);  
   }
}
