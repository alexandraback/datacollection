#include <algorithm>
#include <numeric>
#include <functional>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <ctime>
using namespace std;


#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define debugv(x) {if (1) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}

int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);

  int __T;
  cin>>__T;
  for(int __t = 1 ; __t <= __T; __t++){

    int n;cin>>n;
    int ans = 0;
    string s;cin>>s;
    int pre = 0;
    for(int i = 0 ; i < n+1; i++){
      int x = s[i] - '0';
      if(!x)continue;
      if(pre < i){
        ans += i - pre;
        pre = i;
      }
      pre += x;
    }

    cout<<"Case #"<<__t<<": "<<setprecision(9)<<ans<<endl;
  }

    return 0;
}
