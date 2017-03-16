#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long llint;

const int mxn = 110;
const llint inf = (1ULL<<63) - 1;

int nizA[mxn], nizB[mxn];
llint kolA[mxn], kolB[mxn];
int nA, nB;

map <pair<llint,llint>, llint> mem[mxn][mxn];

llint rek(int A, llint leftA, int B, llint leftB){
  if(leftA < 0 || leftB < 0) return -inf;
  if(A == nA || B == nB) return 0;

  map <pair<llint,llint>, llint>::iterator it = mem[A][B].find(make_pair(leftA, leftB));

  if(it != mem[A][B].end()) return it->second;


  if(leftA == 0) return mem[A][B][make_pair(leftA,leftB)] = rek(A+1, kolA[A+1], B, leftB);
  if(leftB == 0) return mem[A][B][make_pair(leftA,leftB)] = rek(A, leftA, B+1, kolB[B+1]);

  llint dodajem = 0, ret = 0;

  if(nizA[A] != nizB[B]) ret = max(
	    rek(A+1,kolA[A+1],B,leftB),
	    rek(A,leftA,B+1,kolB[B+1])
	    );
  else{
    dodajem = min(leftA, leftB);
    ret = max(ret, dodajem + rek(A, leftA-dodajem, B, leftB-dodajem));
  } 
  
  
  return mem[A][B][make_pair(leftA,leftB)] = ret;
}

void solve(){
  memset(kolA, 0, sizeof(kolA));
  memset(kolB, 0, sizeof(kolB));

  for(int i = 0; i < mxn; i++)
    for(int j = 0; j < mxn; j++)
      mem[i][j].clear();

  scanf("%d %d", &nA, &nB);
  for(int i = 0; i < nA; i++)
    scanf("%lld %d", &kolA[i], &nizA[i]);
  for(int i = 0; i < nB; i++)
    scanf("%lld %d", &kolB[i], &nizB[i]);

  printf( "%lld\n", rek(0,kolA[0],0,kolB[0]) );
}

int main(){
  int t;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
    printf("Case #%d: ", i+1);
    solve();
  }

  return 0;
}
