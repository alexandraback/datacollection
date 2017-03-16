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

int enu(int N, int M, vector<int> &v, vector<int> &s) {
  if (N==0) {
    vector<int> v2 = v;
    sort(v2.begin(),v2.end());
    for (int i=0;i<s.size();i++) {
      if (!binary_search(v2.begin(),v2.end(),s[i])) return -1;
    }
    return 0;
  }
  //cout << N << " left" << endl;
  for (int i=2;i<=M;i++) {
    //cout << "try " << i << endl;
    int sz = v.size();
    for (int j=0;j<sz;j++) {
      v.push_back(v[j]*i);
      //cout << " push " << v[j]*i << endl;
    }
    
    int k=enu(N-1,M,v,s);
    if (k != -1) return k*10+i;
    v.resize(v.size()/2);
  }
  return -1;
}

int main() {
  int R;
  cin >> R >> R;
  int N, M, K;
  cin >> N >> M >> K;
  printf("Case #1:\n");
  for (int i=1;i<=R;i++) {
    vector<int> p;
    for (int j=0;j<K;j++) {
      int a;
      cin >> a;
      p.push_back(a);
    }
    vector<int> v(1,1);
    int k=enu(N,M,v,p);
    
    printf("%d\n", k);
  }
  return 0;
}


