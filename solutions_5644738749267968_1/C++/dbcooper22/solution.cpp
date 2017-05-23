#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
#include <cstring>
#include <stack>
#include <bitset>

using namespace std;

#define NMAX 2147483647
#define LMAX 9223372036854775807LL
#define pb push_back
#define pob pop_back
#define mp make_pair
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>(b);--i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)

int War(vector <double> A, vector <double> B) {
  int ans = 0;
  while(A.size()) {
    bool found = 0;
    REP(i,B.size())
      if(A[0] < B[i]) {
        found = 1;
        B.erase(B.begin()+i);
        break;
      }
    if(!found) {
      ans++;
      B.erase(B.begin());
    }
    A.erase(A.begin());
  }
  return ans;
}

int DW(vector <double> A, vector <double> B) {
  int ans = 0;
  while(A.size()) {
    if(A[0] > B[0]) {
      ans++;
      A.erase(A.begin());
      B.erase(B.begin());
    }
    else {
      A.erase(A.begin());
      B.erase(B.begin()+(int)B.size()-1);
    }
  }
  return ans;
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int TS, N;
  scanf("%d",&TS);
  FORE(ts,1,TS) {
    scanf("%d",&N);
    vector <double> A(N), B(N);
    REP(i,N) cin>>A[i];//scanf("%lf",&A[i]);
    REP(i,N) cin>>B[i];//scanf("%lf",&B[i]);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    /*REP(i,A.size()) printf("%.3lf ",A[i]);//cout << A[i] << " ";
    cout << endl;
    REP(i,B.size()) printf("%.3lf ",B[i]);//cout << B[i] << " ";
    cout << endl;*/
    printf("Case #%d: %d %d\n",ts,DW(A, B),War(A,B));
  }
  return 0;
}
