#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;


#define PB push_back
#define MP make_pair
#define LL unsigned long long
LL t;
LL f(LL x,LL r)
{
    return 2*x*x+(2*r-1)*x;
    //return 2*x*x+(2*r-1)*x;
}
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
    LL a,b,c;
    LL r;
    int tt;
    scanf("%d",&tt);
    int cas=0;//cout<<f( 500017803,1)/(1e18)<<endl;

    while(tt--)
    {
        cin>>r>>t;//cout<<t-2*48*48-(2*r-1)*48<<endl;
        LL l=0,rr=707106789;
        LL ans=0;
        while(l<=rr)
        {
            LL mid = (l+rr)/2;
            //cout<<mid<<" "<<f(mid,r)<<endl;
            LL d = f(mid,r);
            if(d<=t)
            {
                l = mid+1;
            }
            else rr = mid-1;
        }
        while(f(l,r)<=t){l++;}//cout<<f(l,r)<<" "<<l<<endl;
        while(f(l,r)>t){l--;}
        //cout<<l<<" "<<f(l,r)<<" "<<t<<" "<<2*l*l<<" "<<(2*r-1)<<" "<<l<<endl;
        printf("Case #%d: ",++cas);
        printf("%lld\n",l);
        //cout<<ans<<endl;
    }

}
