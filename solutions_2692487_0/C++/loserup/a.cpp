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
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
#define A frist
#define B second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;
int b[150];
int main()
{
      freopen("A.in","r",stdin);
      freopen("A1.txt","w",stdout);
  //  freopen("A_2_out.txt","w",stdout);

    int T;
    scanf("%d",&T);
    LL aa,n;
    rep(cas,T)
    {
        cin>>aa>>n;
        //scanf("%d%d",&a,&n);
        rep(i,n)scanf("%d",&b[i]);

        if(aa==1)
        {
            printf("Case #%d: %I64d\n",cas+1,n);
            continue;
        }
        sort(b,b+n);
        LL ret = n;
        LL a;
        rep(i,n+1)
        {
            int ans = 0;
            a = aa;
            for(int j=0;j<i;)
            {
                if(a>b[j])
                {
                    a+=b[j];
                    j++;
                }
                else
                {
                    a = a*2-1;
                    ans++;
                }
            }
            ret = min(ret,ans+n-i);
        }
        printf("Case #%d: %I64d\n",cas+1,ret);
        //cout << ret << endl;
    }
}






