#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

#define rep(i, n) for(int i=0;i<n;i++)

int main() {
  int test; cin>> test;
  rep(z, test) {
    int r, c, w;
    cin>>r>>c>>w;
    long long int ans = 0;
    ans = c/w;
    ans = r*ans;
    ans += w;
    if(c%w == 0) {
      ans -= 1;
    }
    cout<<"Case #"<<z+1<<": "<<ans<<endl;
  }
}
    
