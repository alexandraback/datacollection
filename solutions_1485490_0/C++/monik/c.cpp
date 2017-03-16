#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

#define MAX 110

using namespace std;

int N,M,T;
vector<long long> apoc,bpoc;
vector<int> aid,bid;
map<pair<long long,long long>,long long>H[MAX][MAX];

long long get(long long p1, long long p2, int z1, int z2) {

  if (z1 == N || z2 == M) return 0;

  assert(0 <= z1 && z1 < N+1);
  assert(0 <= z2 && z2 < M+1);

  if (H[z1][z2].find(make_pair(p1,p2)) != H[z1][z2].end()) return H[z1][z2][make_pair(p1,p2)];

  long long vysledok = 0;

  if (aid[z1] == bid[z2]) {  // fit
    long long usek = min(apoc[z1]-p1,bpoc[z2]-p2);
    long long np1 = p1 + usek;
    long long np2 = p2 + usek;
    int nz1 = z1;
    int nz2 = z2;

    assert(np1 <= apoc[z1]);
    assert(np2 <= bpoc[z2]);

    if (np1 == apoc[z1]) {   // vyzrali sme vsetko
      np1 = 0;
      ++nz1;
      nz1 = min(nz1,N);
    }
    if (np2 == bpoc[z2]) {
      np2 = 0;
      ++nz2;
      nz2 = min(nz2,M);
    }

    vysledok = usek + get(np1,np2,nz1,nz2);
  }
  else {
    long long v1 = get(0,p2,min(z1+1,N),z2);
    long long v2 = get(p1,0,z1,min(z2+1,M));

    vysledok = max(v1,v2);
  }

  H[z1][z2][make_pair(p1,p2)] = vysledok;

  return  vysledok;
}

int main(void) {
  cin >> T;
  REP(t,T) {
    apoc.resize(0); bpoc.resize(0);
    aid.resize(0); bid.resize(0);
    REP(i,MAX) REP(j,MAX) H[i][j].clear();

    cin >> N >> M;

    apoc.resize(N); aid.resize(N);
    bpoc.resize(M); bid.resize(M);

    REP(n,N) cin >> apoc[n] >> aid[n];
    apoc.push_back(47); 
    aid.push_back(444);
    REP(m,M) cin >> bpoc[m] >> bid[m];
    bpoc.push_back(42);
    bid.push_back(222);

    cout << "Case #" << t+1 << ": " << get(0,0,0,0) << endl;
  }
  return 0;
}
