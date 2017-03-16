#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;

#define PI 3.1415926535897932385

int main()
{
    int t,x=0;
    long long r,tt;
   // freopen("A1.in","r",stdin);
   // freopen("A1.out","w",stdout);
    cin>>t;
    while(t--)
    {
        x++;
        cin>>r>>tt;
        long long ans=0;
        long long lo=1,hi=1000000000000000000LL,mid;
        while(lo<hi)
        {
            mid=lo+(hi-lo)/2;
            long long kk=tt;
            kk/=mid;
            long long v=2*r;
            if(kk-v<0) {hi=mid-1; continue;}
            kk-=v;
            v=1+(mid-1)*2;
            if(kk-v<0) {hi=mid-1; continue;}
            kk-=v;
            lo=mid+1;
        }
        mid=hi+1;
        long long kk=tt;
        kk/=mid;
        long long v=2*r;
        if(kk-v<0)
        {
            kk-=v;
            v=1+(mid-1)*2;
            if(kk-v<0)
            {
                mid=hi;
                if(mid==0) ans=0;
                else
                {
                    kk=tt;
                    kk/=mid;
                    v=2*r;
                    if(kk-v<0)
                        ans=hi-1;
                    else
                    {
                        kk-=v;
                        v=1+(mid-1)*2;
                        if(kk<v) ans=hi-1;
                        else ans=hi;
                    }
                }
            }
            else ans=hi+1;
        }
        else
        {
            mid=hi;
                if(mid==0) ans=0;
                else
                {
                    kk=tt;
                    kk/=mid;
                    v=2*r;
                    if(kk-v<0)
                        ans=hi-1;
                    else
                    {
                        kk-=v;
                        v=1+(mid-1)*2;
                        if(kk<v) ans=hi-1;
                        else ans=hi;
                    }
                }
        }
        printf("Case #%d: %lld\n",x,ans);
    }
    return 0;
}
