#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>

using namespace std;

bool enough(unsigned long long r, unsigned long long k, unsigned long long t) {
  if (k>=4294967296ULL) return false;
  //cout << k*k << ">" << t/8 << endl;
  if (k*k>t/2) return false;
  unsigned long long C = (t-k*k*2);
  if (2*r-1<=C/k) return true;
  return false;
}

int main() {
  int N;
  cin >> N;
  for (int i=1;i<=N;i++) {
    long long r, t;
    scanf("%lld %lld\n", &r, &t);

    //cout << "1:" <<  enough(r,1,t) << endl;
    //cout << "2:" <<  enough(r,2,t) << endl;
    //cout << "3:" <<  enough(r,3,t) << endl;
    long long mink=0, maxk=t/r+1;
    while (maxk-mink>1) {
      long long midk = (mink+maxk)/2;
      if (enough(r,midk,t)) mink=midk;
      else maxk=midk;
    }
    
    printf("Case #%d: %d\n", i, mink);
  }
  return 0;
}


