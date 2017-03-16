#pragma comment(linker,"/STACK:100000000000,100000000000")

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define D long double
#define pi pair<int,int>
#define F first
#define S second
#define forn(i,n) for (int(i)=0;(i)<(n);i++)
#define forr(i,x,y) for (int(i)=(x);(i)<=(y);i++)
#define ford(i,x,y) for (int(i)=(x);(i)>=(y);i--)
#define rev reverse
#define in insert
#define er erase
#define all(n) (n).begin(),(n).end()
#define graf vector<vector<pi> >
#define graf1 vector<vector<ll> >
#define sqr(a) (a)*(a)
#define file freopen("a.in","r",stdin);freopen("a.out","w",stdout);
#define y1 asdadasdasd

const int INF = 1e9;
const D cp = 2 * asin(1.0);
const D eps = 1e-9;
const ll mod = 1000000007;

using namespace std;

set<string> a[2];

void gen(int num, string mask, string g)
{
    if (g.size()==mask.size()) a[num].in(g);
    else
    {
        if (mask[g.size()]!='?') gen(num,mask,(g+mask[g.size()]));
        else
        {
            forn(i,10)
                {
                    string f;
                    f = g;
                    f += char(i+48);
                    gen(num,mask,f);
                }
        }
    }
}

int conv(string s)
{
    int x=0;
    forn(i,s.size()) x*=10,x+=s[i]-'0';
    return x;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //file;
    int T;
    cin>>T;
    forn(Q,T)
    {
        string s,s1;
        cin>>s>>s1;
        a[0].clear();
        a[1].clear();
        gen(0,s,"");
        gen(1,s1,"");
        set<pair<int,pair<string,string> > > f;
        for(set<string>::iterator i = a[0].begin();i!=a[0].end();i++)
        {
            for(set<string>::iterator j = a[1].begin();j!=a[1].end();j++)
            {
                f.in(mp(abs(conv(*i)-conv(*j)),mp(*i,*j)));
            }
        }
        cout<<"Case #"<<Q+1<<": "<<(*f.begin()).S.F<<' '<<(*f.begin()).S.S;
        cout<<endl;
    }
    return 0;
}
