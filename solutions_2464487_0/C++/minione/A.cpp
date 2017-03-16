#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int T;
 long long r,t;

bool Check( long long k)
{
    double R=r;
    double K=k;
    double P=2*R*K+2*K*(K+1)-3*K;
    double TT=t;
    if (P>TT) return false;
    else return true;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    cin>>T;
    for (int tt=1; tt<=T; ++tt)
    {
        cin>>r>>t;
        long long left,right,mid;
        left=1;
        right=t;
        for (int c=1; c<=100; ++c)
        {
            mid=(left+right)/2;
            if (Check(mid)) left=mid;
            else right=mid;
        }
        long long ans=0;
        for (int i=left+3; i>=left-3; --i)
        {

            if (Check(i))
            {
                ans=i;
                break;
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
