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
#define pi 3.1415926535898
using namespace std;



LL r,t;
LL f(LL x)
{
    LL en = (2*r+1) + (x-1)*4;
    LL st = (2*r+1);

    if(x<=t*2/(st+en)+2)
    {
        LL ret = (st+en)*(x)/2;
        if(ret <= t)return 1;
    }

    return 0;
}
int main()
{
    freopen("A_1.in","r",stdin);
    freopen("A_1_out.txt","w",stdout);
  //  freopen("A_2_out.txt","w",stdout);

    int T;
    scanf("%d",&T);

    rep(i,T)
    {
        scanf("%I64d%I64d",&r,&t);

        LL le = 0,ri = 707106780 + 10;

        while(le<ri)
        {
            LL mid = (le+ri+1)/2;
            if(f(mid)==0)
            {
                ri = mid-1;
            }
            else
            {
                le = mid;
            }
        }
        printf("Case #%d: %I64d\n",i+1,le);
    }
}

