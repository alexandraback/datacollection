#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
double pi = acos(-1);
int T;
long long rid;
long long r,t;
long long ans;
long long f(long long d)
{
    return  2*d*r+(2*d-2)*d+d;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out2.txt","w",stdout);
    int cas =1;
    cin>>T;
    while(T--)
    {

        ans=0;
        cin>>r>>t;
        rid = r;
        long long left = 0;
        long long right = sqrt(t);
        right = min(t/r,right);
        //cout<<f(2)<<endl;
        while(left!=right)
        {
            long long mid = (left+right+1)>>1;
            if(f(mid)<=t)
            {
                left=mid;
            }
            else
                right=mid-1;
        }
//        long long area = 2*rid+1;
//        while(area<=t)
//        {
//            ans++;
//            t-=area;
//            rid+=2;
//            area = 2*rid+1;
//        }
        printf("Case #%d: %lld\n",cas++,left);
    }
    return 0;
}
