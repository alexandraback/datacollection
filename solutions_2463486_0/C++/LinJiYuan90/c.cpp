#include "sstream"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

vector<int> vt_p;
vector<long long> vt_fp;

long long reverse(long long x)
{
  long long ans = 0;
  while (x > 0) {
      ans = ans * 10 + x % 10;
      x /= 10;
  }
  return ans;
}

int ten(int x)
{
    int ten = 1;
    while (x > 0) {
        ten *= 10;
        x /= 10;
    }
    return ten;
}

void init()
{
  for (int i = 1; i < 10; i++) {
    vt_p.push_back(i);
  }
  for (int x = 1; x < 1000; x++) {
    int y = reverse(x);
    int t = ten(x);
    for (int m = 0; m < 10; m++) {
      vt_p.push_back(x*t*10 + m*t + y);
    }
    vt_p.push_back(x*t + y);
  }
  sort(vt_p.begin(), vt_p.end());
  vt_p.resize(unique(vt_p.begin(), vt_p.end()) - vt_p.begin());

  for (int i = 0; i < vt_p.size(); i++) {
    long long x = (long long)vt_p[i]*vt_p[i];
    long long y = reverse(x);
    if (x == y) {
      vt_fp.push_back(x);
      //cout<<x<<endl;
    }
  }
}

int main()
{
    init();
    int T, t = 1;
    for (cin>>T; T--; ){
        cout<<"Case #"<<t++<<": ";
        long long a, b;
        cin>>a>>b;
        a = lower_bound(vt_fp.begin(), vt_fp.end(), a) - vt_fp.begin();
        b = upper_bound(vt_fp.begin(), vt_fp.end(), b) - vt_fp.begin();
        cout<<b - a<<endl;
    }
    return 0;
}

