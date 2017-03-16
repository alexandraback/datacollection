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

//////////////////////////////////


void init() {
  //  scanf("%d",&);
}

#define MAX 1000
int n;
int c[MAX];
int m[MAX][MAX];
int acc[MAX][MAX];
int sc;
int sommet[1000000];

void input() {
  scanf("%d",&n);
  int i,j;
  sc = 0;
  memset(acc,0,sizeof(acc));
  for(i=0;i<n;i++) {
    scanf("%d",&(c[i]));
    if(c[i]==0) {
      sommet[sc]=i;
      sc++;
    }
    for(j=0;j<c[i];j++) {
      scanf("%d",&(m[i][j]));
      m[i][j]--;
      acc[i][m[i][j]]=1;
    }
  }
}

int v[MAX];
int cp;
int p[MAX];

void output() {
  int i,j,k;
  int f = 0;
  for(i=0;i<sc&&!f;i++) {
    cp = 1;
    p[0] = sommet[i];
    k = 0;
    memset(v,0,sizeof(v));
    while(!f && k < cp) {
      int id = p[k];
      if(v[id]) {
	f = 1;
	break;
      }
      v[id]=1;
      for(j=0;j<n;j++) {
	if(acc[j][id]) {
	  if(v[j]) {
	    f = 1;
	    break;
	  }
	  p[cp]=j;
	  cp++;
	}
      }
      k++;
    }
  }
  if(f)
    printf("Yes");
  else
    printf("No");
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
