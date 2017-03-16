#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a,b,c) { c=a;a=b;b=c; }
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef unsigned long long int ll;

int ncase,icase;

void flush()     { ll c; while((c=getchar())!='\n'&&c!=EOF); }
void printcase() { printf("Case #%d: ", icase); }
void nline()     { putchar('\n'); }
void sp()        { putchar(' '); }

//////////////////////////////////

//////////////////////////////////


void init() {
  //  scanf("%d",&);
}

#define MAX 1000

ll n,m;
ll A[MAX];
ll a[MAX];
ll B[MAX];
ll b[MAX];

void input() {
  scanf("%llu%llu",&n,&m);
  ll i;
  for(i=0;i<n;i++)
    scanf("%llu%llu",a+i,A+i);    
  for(i=0;i<m;i++)
    scanf("%llu%llu",b+i,B+i);
}

ll cal(ll in, ll im) {
  if(in >= n || im >= m) {
    return 0;
  }
  

  ll i,j,k,l;
  ll maxres = 0;
  ll tmp;
  ll f = 0;
  for(i=im;i<m;i++) {
    if(B[i]==A[in]) {
      f = 1;
      break;
    }
  }

  if(f) {
    if(b[i]>a[in]) {
      ll diff = b[i]-a[in];
      b[i] -= diff;
      tmp = a[in] + cal(in+1,i);
      if(tmp>maxres)
	maxres=tmp;

      b[i]+=diff;
    } else if (b[i]<a[in]) {
      ll diff = a[in]-b[i];
      a[in]-=diff;
      tmp = b[i] + cal(in,i+1);

      if(tmp>maxres)
	maxres=tmp;
      a[in]+=diff;
    } else {
      tmp = b[i] + cal(in+1,i+1);
      if(tmp>maxres)
	maxres=tmp;
    }
  }
  
  tmp = cal(in+1,im);
  if(tmp>maxres)
    maxres=tmp;
  return maxres;
}

void output() {
  ll maxres = cal(0,0);
  printf("%llu",maxres);
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
