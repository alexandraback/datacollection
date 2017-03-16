#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define ll  long long
#define llu unsigned long long
#define M 100
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define Check(x,w) (x&(1<<w))==(1<<w)?true:false
#define pii pair<int,int>
#define X 5800000
#define EPS 1e-9
#define PI acos(-1)
#define Mems(p,n) memset(p,n,sizeof(p))
#define MOD 100000000
using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

string s[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
string v="ZOWRUFXSGI";
int ara[]={0,8,2,4,1,5,6,7,3,9},mara[30],alu[11];

int main()
{
    freopen("inAL.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,tt,a,b,c,d,i,j,k;
    fs(tt);
    for(t=1; t<=tt; t++)
    {
        string u;
        cin>>u;
        Mems(mara,0);
        Mems(alu,0);
        for(i=0; i<u.size(); i++)
            mara[u[i]-'A']++;
        for(i=0; i<=9; i++)
        {
            b=ara[i];
            alu[b]=mara[v[b]-'A'];
            //pf("b=%d alu=%d\n",b,alu[b]);
            for(k=0; k<alu[b]; k++)
            {
                for(j=0; j<s[b].size(); j++)
                    mara[s[b][j]-'A']--;
            }
        }
        pf("Case #%d: ",t);
        for(i=0; i<=9; i++)
        {
            for(j=0; j<alu[i]; j++)
                pf("%d",i);
        }
        pf("\n");
    }
    return 0;
}
