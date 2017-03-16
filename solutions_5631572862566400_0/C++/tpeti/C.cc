#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

void run() {
  int N;
  scanf("%d",&N);
  vector<int> F(N);
  for (int i=0;i<N;++i) { scanf("%d",&F[i]); --F[i]; }
  int p=0;
  vector<pair<int,int> > circ;
  int maxper=0;
  while (p<N) {
    int r=p;
    for (int i=0;i<N;++i) {
      if (F[r]<0) break;
      r=F[r];
    }
    int s=F[r];
    if (s>=0) {
      int per=1;
      do { ++per; s=F[s]; } while (s!=r);
      if (per>maxper) maxper=per;
      if (per>2) {
	for (int i=0;i<per;++i) { s=F[r]; F[r]=-1; r=s; }
      } else {
	circ.emplace_back(pair<int,int>(r,F[r]));
	F[F[r]]=-1;
	F[r]=-1;
      }
    }
    ++p;
  }
  vector<int> maxtail(N,0);
  p=0;
  while (p<N) {
    if (F[p]<0) { ++p; continue; }
    int r=F[p],tail=1;
    while (F[r]>=0) { ++tail; r=F[r]; }
    maxtail[r]=max(maxtail[r], tail);
    ++p;
  }
  int sol=0;
  for (vector<pair<int,int> >::const_iterator it=circ.begin();it!=circ.end();++it) {
    sol+=2+maxtail[it->first]+maxtail[it->second];
  }
  if (sol<maxper) sol=maxper;
  printf("%d\n",sol);
}

int main() {
  int T;
  scanf("%d",&T);
  for (int t=1;t<=T;++t) {
    printf("Case #%d: ",t);
    run();
  }
  return 0;
}
