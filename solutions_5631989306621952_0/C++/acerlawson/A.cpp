//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
#include<time.h>

#define Msn(x,y) (memset((x),0,sizeof((x[0]))*(y+1)))
#define msn(x) (memset((x),0,sizeof((x))))
#define msx(x) (memset((x),0x7f,sizeof((x[0]))))
#define fuck(x) cerr << #x << " <- " << x << endl
#define acer cout<<"sb"<<endl
#define mkp(x,y) (make_pair(x,y))
#define fi first
#define se second
#define ture true
#define lch  (id<<1)
#define rch (id<<1|1)

typedef long long ll;
using namespace std;
int n;
string s,t,t1,t2;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aans.out","w",stdout);
    cin>>n;
    for(int _=1;_<=n;_++)
    {
        cin>>s;
        t="";
        for(int i=0;i<s.length();i++)
        {
            t1=s[i]+t;
            t2=t+s[i];
            t=max(t1,t2);
        }
        cout<<"Case #"<<_<<": "<<t<<endl;
    }
    return 0;
}
