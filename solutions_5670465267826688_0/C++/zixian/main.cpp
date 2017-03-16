#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int multable[5][5];
char input[10010];

int computeStrVal(int, int);
int fastPow(int, ll);

int main(){
  int numTC, TC = 1, L, X, l, r, val;
  ll start, end, limit;

  //Make multiplication table
  multable[1][1] = 1; multable[1][2] = 2; multable[1][3] = 3;
  multable[1][4] = 4; multable[2][1] = 2; multable[2][2] = -1;
  multable[2][3] = 4; multable[2][4] = -3; multable[3][1] = 3;
  multable[3][2] = -4; multable[3][3] = -1; multable[3][4] = 2;
  multable[4][1] = 4; multable[4][2] = 3; multable[4][3] = -2;
  multable[4][4] = -1;

  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d %d %s", &L, &X, input);
    for(int i=0; i<L; i++) input[i]-='i'-2;
    val = fastPow(computeStrVal(0, L-1), X);
    if(val!=-1){ printf("Case #%d: NO\n", TC++); continue; }
    limit = L*X; l = r = 1;
    for(start=0; start<limit; start++){
      if(l<0) l = -(multable[-l][input[start%L]]);
      else l = multable[l][input[start%L]];
      if(l==2) break;
    }
    for(end = limit-1; end>=0; end--){
      if(r<0) r = -(multable[input[end%L]][-r]);
      else r = multable[input[end%L]][r];
      if(r==4) break;
    }
    if(start+1<end) printf("Case #%d: YES\n", TC++);
    else printf("Case #%d: NO\n", TC++);
  }
  return 0;
}

int computeStrVal(int s, int e){
  if(s>e) return 1;
  if(s==e) return input[s];
  int mid = (s+e)>>1;
  int l = computeStrVal(s, mid), r = computeStrVal(mid+1, e);
  if(l<0) l = -(multable[-l][abs(r)]);
  else l = multable[l][abs(r)];
  return r<0? -l: l;
}

int fastPow(int n, ll p){
  if(p==1) return n;
  int temp = fastPow(n, p>>1);
  if(temp<0) temp = multable[-temp][-temp];
  else temp = multable[temp][temp];
  if(p&1){
    if(temp<0) temp = -(multable[-temp][abs(n)]);
    else temp = multable[temp][abs(n)];
    if(n<0) temp = -temp;
  }
  return temp;
}
