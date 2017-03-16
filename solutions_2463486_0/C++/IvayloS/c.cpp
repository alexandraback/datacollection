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
bool fair(ll i) {
  ll rev = 0;
  ll ti = i;
  while (ti) {
    rev = rev*10 + ti%10;
    ti /= 10;
  }
  return i == rev;
}

ll nums[39] = {
  1LL, 
4LL, 
9LL, 
121LL, 
484LL, 
10201LL, 
12321LL, 
14641LL, 
40804LL, 
44944LL, 
1002001LL, 
1234321LL, 
4008004LL, 
100020001LL, 
102030201LL, 
104060401LL, 
121242121LL, 
123454321LL, 
125686521LL, 
400080004LL, 
404090404LL, 
10000200001LL, 
10221412201LL, 
12102420121LL, 
12345654321LL, 
40000800004LL, 
1000002000001LL, 
1002003002001LL, 
1004006004001LL, 
1020304030201LL, 
1022325232201LL, 
1024348434201LL, 
1210024200121LL, 
1212225222121LL, 
1214428244121LL, 
1232346432321LL, 
1234567654321LL, 
4000008000004LL, 
4004009004004LL};

int main()
{
  freopen("google-small.in","r",stdin);
  freopen("google-small.out","w",stdout);
  
  //for ( int i = 0;i <= 10000000; ++i){
  //  if (fair(i) && fair((ll)i*(ll)i)) {
  //    cout << (ll)i*(ll)i << "LL, " << endl;
  //  }
  //}
  
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    ll a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i=0;i<39;++i) {
      if(nums[i] >= a && nums[i] <= b) {
        ans++;
      }
    }
    cout<<"Case #"<<it<<": " << ans<<endl;
  }

  return 0;
}
