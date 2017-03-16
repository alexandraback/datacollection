// Marek Rogala; Code Jam 2012
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;
#define VAR(a,b) typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define SIZE(x) ((int)x.size())
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }
typedef long long LL;
const int INF = 1000000000;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

int const MAXN=101;

int n,m;

LL a[MAXN],A[MAXN],b[MAXN],B[MAXN];

LL sumujb(int beg, int e, int aid){
  LL res = 0;
  FOR(i,beg,e){
    if(B[i]==A[aid]) res+= b[i];
  }
  return min(res,a[aid]);
}

void zrob(int testcase){
  cin >> n >> m;
  FOR(i,1,n){
    cin >> a[i] >> A[i];
  }
  FOR(j,1,m){
    cin >> b[j] >> B[j];
  }
  
  if(n==3&&A[2]==A[3]){
    n--;
    a[2]+=a[3];
  }
  if((n==2||n==3)&&A[1]==A[2]){
    a[1]+=a[2];
    if(n==3){
      a[2]=a[3]; 
      A[2]=A[3];
    }
    n--;
  }
  
  LL result = 0;
  
  if(n==1){
    result = sumujb(1,m,1);
  } else if(n==2){
    FOR(k,1,m+1){
      result = max(result, sumujb(1,k-1,1)+sumujb(k,m,2));
    }
  } else {
    FOR(k1,1,m+1){
      FOR(k2,k1,m+1){
        LL kand = sumujb(1,k1-1,1)+sumujb(k1,k2-1,2)+sumujb(k2,m,3);
        //cout << " opcja " << k1 << ";"<<k2 << " -> " << kand<<endl;
        result = max(result, kand);
      }
    }
    if(A[1]==A[3]){
      a[1]+=a[3];
      result=max(result, sumujb(1,m,1));
    }
  }
  
  
	cout << "Case #"<<testcase<<": "<<result<<endl;
}

int main() {
	int T; cin >> T;
	for(int i=1;i<=T;i++) zrob(i);
	return 0;
}

