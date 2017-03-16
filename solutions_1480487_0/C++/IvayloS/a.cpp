#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

bool can(int x, const vector<int>& a, int idx, ld v) {
  ld score = (ld)a[idx] + (ld)x * v;
  int n = (int)a.size();
  ld lft = 1.0 - v;
  for (int j=0;j<n;++j){
    if (j == idx) continue;
    ld req = (score - (ld)a[j])/(ld)x;
    if (req > 0)
    lft -= req;
  }
  return lft < -epsylon;
}
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    int s  =0;
    for (int i =0 ;i<n;++i){
      cin >> a[i];
      s+= a[i];
    }
    vector<ld> res(n);
    for (int i  =0 ;i<n;++i){
      ld beg = 0.0;
      ld end = 1.0;
      for (int j=0;j<200; ++j){
         ld mid = (end + beg)*0.5;
         if (can(s, a, i, mid)) {
            end= mid;
         } else {
          beg = mid;
         }
      }
      res[i] = beg * 100.0;
    }
    cout<<"Case #"<<it<<":";
    for (int i=0;i<n;++i){
      printf(" %.7llf", res[i]);
    }
    cout << endl;
  }
  return 0;
}
