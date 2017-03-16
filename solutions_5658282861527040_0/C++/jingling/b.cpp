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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <ctime>
using namespace std;

#define debug(x) cerr<<#x<<" = "<<(x)<<endl;

int main(int argc, char *argv[])
{
  int __T;
  cin>>__T;
  for(int __t = 1 ; __t <= __T; __t++){

    int a, b,k, ans=0;
    cin>>a>>b>>k;
    for(int i = 0 ; i < a; i++){
      for(int j = 0 ; j < b; j++){
        int x = i&j;
        if(x<k)
          ans++;
      }

    }

    cout<<"Case #"<<__t<<": "<<ans<<endl;
  }

    return 0;
}
