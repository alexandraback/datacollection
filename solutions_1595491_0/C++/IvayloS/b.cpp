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
    int n,s,p;
    cin >> n >> s >> p;
    int ans = 0;
    int t;
    for (int i  = 0; i < n; ++i) {
      cin >> t;
      if (t >= p * 3 - 2)  {
        ans++;
      } else if ( p - 2 >= 0 && s > 0 && t < p*3 -2 && t >= p*3 -4) {
        s--;
        ans++;
      }
    }
    cout<<"Case #"<<it<<": "<< ans <<endl;
  }
  return 0;
}
