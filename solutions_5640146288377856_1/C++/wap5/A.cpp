#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  freopen("lin", "r", stdin);
  freopen("lout", "w", stdout);
  int tt;
  int r, c, w, ans;

  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++)
        {
            printf("Case #%d: ", qq);

            ans=0;
            cin>>r>>c>>w;
            if (c%w==0)
            {
                ans=c/w+w-1;
            }
            else
            {
                ans=c/w+w;
            }

            ans+=c/w*(r-1);
            cout<<ans<<endl;
            cerr<<ans<<endl;


        }

  return 0;
}
