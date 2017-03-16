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
#define MAX 2000
int n;
int a[MAX],b[MAX];
int fini[MAX];
int id1[MAX],id2[MAX];
//////////////////////////////////

int cmp1(const void* aa, const void* bb) {
  int* ia = (int*)aa;
  int* ib = (int*)bb;
  int diff = a[*ia]-a[*ib];
  //  if(diff)
  return diff;

    //  return b[*ib]-b[*ia];
}

int cmp2(const void* aa, const void* bb) {
  int* ia = (int*)aa;
  int* ib = (int*)bb;
  int diff = b[*ia]-b[*ib];
  //  if(diff)
  return diff;
    //  return a[*ib]-a[*ia];
}

void init() {
}

void input() {
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++) {
    scanf("%d%d",a+i,b+i);
    id1[i]=id2[i]=i;
  }
}

int stars;
int steps;
void output() {
  memset(fini,0,sizeof(fini));
  stars=0;
  steps=0;
  qsort(id1,n,sizeof(int),cmp1);
  qsort(id2,n,sizeof(int),cmp2);

  int i1=0,i2=0;
  int f=0;
  while(i2<n) {
    if(b[id2[i2]]<=stars) {
      stars += 2 - fini[id2[i2]];
      fini[id2[i2]]=2;
      steps++;
      i2++;
    } else {
      while(fini[id1[i1]]>0 && i1<n) {
	i1++;
      }
      if(i1==n) {
	f=1;break;
      }
      if(a[id1[i1]]<=stars) {
	fini[id1[i1]]=1;
	stars+=1;
	steps++;
	i1++;
      } else {
	f=1;break;
      }
    }
  }
  if(f) {
    printf("Too Bad");
  } else {
    printf("%d",steps);
  }
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
