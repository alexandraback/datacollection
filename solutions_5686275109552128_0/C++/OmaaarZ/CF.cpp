#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define LL long long
using namespace std;

int p[1010];
bool check(int mid)
{
    int temp[1010],b[1010];
    for(int s = 0 ; s <=mid ; s++)
    {
        for(int i = 0 ; i <=1000;i++)
            temp[i]= p[i],b[i]=0;
        int z =s;
        for(int i = 1000 ; i  >= 0 ; i--)
        {
            if(temp[i]>0)
            {
                if(i%2 == 1)
                {
                    if(temp[i]<z&&i/2 +2 <i&& i/2 >1)
                    {
                        temp[i/2+2]+=min(temp[i],z);
                        temp[i/2-1]+=min(temp[i],z);
                        b[i/2+2]+=min(temp[i],z);
                    }
                    else
                    {
                        temp[i/2+1]+=min(temp[i],z);
                        temp[i/2]+=min(temp[i],z);
                    }
                }
                else
                    temp[i/2]+=2*min(temp[i],z);
                int tot = min(temp[i],z);
                z-=tot;
                temp[i]-=tot;
            }
            if(z==0)
                break;
        }
        int ma =-1;
        for(int i = 1000 ; i >=0;i--)
        {
            if(temp[i]>0)
            {
                ma = i;
                break;
            }
        }
        if(b[ma]>=temp[ma])
            ma--;
        if(s+ma<=mid)
            return true;
    }
    return false;
}
int main()
{
  freopen("B-small-attempt2.in","r",stdin);
   freopen("output.in","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >>t;
    int tc=1;
    while(t--)
    {
        int d;
        memset(p, 0 , sizeof p);
        cin >> d;
        for(int i = 0 ; i< d; i ++)
        {
            int x;
            cin >> x;
            p[x]++;
        }
        int low = 0 , high = 1000;
        while(low < high )
        {
            int mid = (low + high)/2;
            if(check(mid))
                high = mid;
            else
                low = mid+1;
        }
        cout << "Case #" <<tc++<<": " << low <<endl;
    }
    return 0;
}


