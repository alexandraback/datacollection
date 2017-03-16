//my magic will tear you apart!
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

int t;


int main() {
  if(fopen("B.in","r")) freopen("B.in","r",stdin);
  freopen("B.out", "w", stdout);
  cin >> t;
  for(int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    int n;
    cin >> n;
    int f[3000];
    memset(f,0,sizeof(f));
    for(int j = 0; j < 2*n - 1; j++) {
      for(int k = 0; k < n; k++) {
        int x;
        cin >> x;
        f[x]++;
      }
    }
    vector<int> v;
    for(int j = 0; j < 3000; j++) {
      if(f[j] % 2 == 1) {
        v.pb(j);
      }
    }
    sort(v.begin(), v.end());
    for(int j = 0; j < v.size(); j++) {
      cout << v[j] << " ";
    }
    cout << endl;
  }
  return 0;
}