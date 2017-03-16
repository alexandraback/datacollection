#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define swap(a,b,c) { c=a;a=b;b=c; }
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef long long ll;

int ncase,icase;

void flush()     { int c; while((c=getchar())!='\n'&&c!=EOF); }
int  printcase() { printf("Case #%d: ", icase); }
void nline()     { putchar('\n'); }
void sp()        { putchar(' '); }

//////////////////////////////////
int A,B;
#define MAX 100000
double p[MAX],pp[MAX];
//////////////////////////////////


void init() {
}

void input() {
  scanf("%d%d",&A,&B);
  int i;
  for(i=0;i<A;i++) {
    scanf("%lf",p+i);
    if(i==0)
      pp[0]=p[0];
    else
      pp[i]=p[i]*pp[i-1];
  }
}

void output() {
  double mexp = B+2;
  int i;
  for(i=0;i<A;i++) {
    double expp=(double)(B-A+2*i+1)+(double)(B+1)*(1.0-pp[A-1-i]);
    mexp=min(expp,mexp);
  }
  printf("%lf",mexp);
}

void solve() {
  printcase();
  input();
  output();
  nline();
}

int main(int argc, char** argv) {
  if(argc>1)
    freopen(argv[1],"r",stdin);
  if(argc>2)
    freopen(argv[2],"w",stdout);

  init();

  scanf("%d",&ncase); flush();
  for(icase=1;icase<=ncase;++icase)
    solve();
}
