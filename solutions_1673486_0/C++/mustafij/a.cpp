#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;

double prob[100010]; int A,B;
double memo[100010];

//double getExp(int ind)
//{
//    if(ind>=A) return B-A+1;
//    if(memo[ind]>-.5) return memo[ind];
//    double rv=B+2; // enter
//    double a=prob[ind]*(getExp(ind+1))+1;
//    double b=(1-prob[ind])*(B+1)+A-ind;
//    rv=min(a,rv); rv=min(b,rv);
//    return memo[ind]=rv;
//}

double getExp()
{
    double rv=B+2; double sum[10]; memset(sum,0,sizeof sum);

    for(int mask=0;mask<(1<<A);mask++)
    {
        int i;
        for(i=0;i<A;i++) if((mask&(1<<i))==0) break;
        double p=1;
        for(int j=0;j<A;j++)
        {
            if(mask&(1<<j)) p*=prob[j]; else p*=(1-prob[j]);
        }
        for(int b=A;b>=0;b--)
        {
            double press=A-b+(B-b)+1;
            if(i<b) press=press+B+1;
            double now=press*p;
            sum[b]+=now;
            //cerr<<mask<<' '<<b<<' '<<now<<endl;
        }
    }
    for(int i=0;i<=A;i++) rv=min(sum[i],rv);
    return rv;
}

int main()
{
    int T; cin>>T; int cn=0;
    while(T--)
    {
        cin>>A>>B;
        for(int i=0;i<A;i++) cin>>prob[i];
        memset(memo,-1,sizeof memo);
        printf("Case #%d: %.12lf\n",++cn,getExp());
    }

}
