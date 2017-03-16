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
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    int a,b;
    cin >> a >> b;
    int ans =0;
    set<pair<int,int> > met;

    for (int i = a; i<= b;++i) {
      int nd = 0;
      int t = i;
      while (t) {
        nd++;
        t/=10;
      }
      int p = 1;
      for (int j=0;j<nd - 1;++j) {
        p *= 10;
      }
      t = i;
      int temp;
      for (int j=0;j<nd;++j) {
        temp = t/10 + p * (t%10);
        t = temp;
        if (t != i && t >= a && t <= b && i <= t) {
          met.insert(mpair(i,t));
        }
      }
    }
    cout<<"Case #"<<it<<": " << met.size() <<endl;
  }
  return 0;
}
