#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
#define eps 1e-9
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi acos(-1.0)
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define inf 1000000000

using namespace std;

long long ans,a,b,ten[10];
map<pair<long,long>,bool>q;

void func(long long n)
    {
    bool d=0;
    string s,r;
    ostringstream os;
    os<<n;
    s=os.str();
    int len=s.length();
    long long temp,chk;
    if (len==1) return;
    for(int i=len-1;i>=1;i--)
        {
        temp=n;
        chk=((temp%ten[i])*ten[len-i])+(temp/ten[i]);
        if(chk>=a && chk<=b && chk>n) {
                                        ostringstream rr;
                                        rr<<chk;
                                        r=rr.str();
                                        int rl=r.length();
                                        if(len==rl && !q[mp(n,chk)])
                                            {
                                            q[mp(n,chk)]=1;
                                            ans++;
                                            }
                                        }
        }
    return;
    }

int main()
{
int t,kk=1;
/*
freopen("C-small-attempt0.in","r",stdin);
freopen("Cout.txt","w",stdout);
*/
scanf("%d",&t);
ten[1]=10;
ten[2]=100;
ten[3]=1000;
ten[4]=10000;
ten[5]=100000;
ten[6]=1000000;
ten[7]=10000000;
ten[8]=100000000;
while(t--)
    {
    scanf("%lld%lld",&a,&b);
    if(a>b) swap(a,b);
    ans=0;
    q.clear();
    for(long long i=a;i<=b;i++)
        {
        func(i);
        }
    //cout<<"Case #"<<kk++<<": "<<ans<<endl;
    printf("Case #%d: %lld\n",kk++,ans);
    }
return 0;
}
