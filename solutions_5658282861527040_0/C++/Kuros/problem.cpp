#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
#define mo 321555123
#define eps 1e-6
#define inf 1000000
int t,a,b,k;
int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("ans.txt","w",stdout);
    scanf("%d",&t);
    int cac=0;
    while(t--)
    {
        cac++;
        scanf("%d%d%d",&a,&b,&k);
        int ans=0;
        printf("Case #%d: ",cac);
        for(int i=0;i<a;i++)
        {
          for(int j=0;j<b;j++)
          {
            if((i&j)<k)
              ans++;
          }
        }
        printf("%d\n",ans);
    }
    return 0;
}
