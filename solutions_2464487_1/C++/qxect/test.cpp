#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(it,c) for(typeof(c) it = ((c).begin()); it != ((c).end()) ; ++it)
#define PI acos(-1.0)
#define LL unsigned long long
LL x,t;
bool test(LL now){
  LL total = (2LL*now-1LL)*now + 2LL*now*x;
  return 2LL*now*x <= t && total <= t;
}
int main()
{
  int tn;
  int z;
  LL L, R, B;
  LL mid;

  cin >> tn;
  for(z =1;z<=tn;z++){
    cin >> x >> t;
    L = 0;
    R = 1000000000LL;
    B = 0;
    while(L<=R){
      mid = (L+R)/2LL;
      if(test(mid)){
        B = max(B, mid);
        L = mid+1;
      }else{
        R = mid-1;
      }
    }
    cout << "Case #" << z << ": " << B << endl;
    
  }
  return 0;
}
