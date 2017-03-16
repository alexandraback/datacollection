#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define sz          size()
#define pb          push_back
#define mp          make_pair
#define ALL(X)      (X).begin(),(X).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void output(int c,long long n){
  cout<<"Case #"<<c<<": "<<n<<endl;
}

long long n,r;

long long f(long long a, long long b) {
  long long k = (a + b) / 2;
  if(b<=a+1) return a;
  if ((1.0*2*k+2*r-1)*k>1e18) return f(a,k);
  if ((2*k+2*r-1)*k>n) return f(a,k);
  else return f(k,b);
}

int main(void)
{
  int t;
  cin>>t;
  FOR(c,1,t+1){
    cin>>r>>n;
    output(c,f(1,1000000000));
  }
  return 0;
}
