//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL


int main()
{
    //freopen("input2.txt","r",stdin);freopen("output2.txt","w",stdout);
    double c,f,x,curtime,rate,tim,t;
    int test,tt;

    cin>>test;
    for(tt=1;tt<=test;tt++)
    {
        cin>>c>>f>>x;
        rate=2.0;tim=0;curtime=INF;
        while(1)
        {
            t=tim+(x/rate);
            if(curtime>t)curtime=t;
            else break;
            tim+=c/rate;
            rate+=f;
        }
        printf("Case #%d: %.7f\n",tt,curtime);
    }
return 0;
}
