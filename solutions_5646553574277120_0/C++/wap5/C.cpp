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
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  int i, j, d, flag, cnt;
  long long c, v, denom[100];
  long long mid;

  scanf("%d", &tt);
  for (int qq=1;qq<=tt;qq++)
        {
            printf("Case #%d: ", qq);
            cin>>c>>d>>v;
            cnt=0;
            j=0;
            flag=0;
            mid = pow((c+1),j);
            for (i=0; i<d; i++)
            {
                cin>>denom[i];

            }
            //-------------------------------------
            i=0;j=0;
            do
            {
                mid = pow((c+1),i);
                flag=0;
                while ((denom[j]<=mid)&&(j<=d-1))
                {
                    if (denom[j]==mid) flag=1;
                    j++;
                }
                if (flag==0) cnt++;
                i++;
            }
            while (mid<=v);
            cout<<cnt-1<<endl;

        }

  return 0;
}
