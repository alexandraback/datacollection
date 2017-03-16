#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rp(i,a,n) for(int i=a;i<=int(n);i++)
#define IT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define oo INT_MAX
#define sc(x) scanf("%d", &x)
#define fill(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define mod 1000000007
#define pi 3.14159265358979323846264338327950288419716939937510582097494459230781
using namespace std;

int sub(string a,string b)
{
    int aa=0,bb=0;
    rep(i,a.size()) { aa*=10;bb*=10;aa+=a[i]-'0';bb+=b[i]-'0'; }
    return abs(aa-bb);
}
bool ok(string a,string x)
{
    rep(i,a.size()) if(a[i]!='?'&&a[i]!=x[i]) return 0;
    return 1;
}
string a,b;
vector<string> v;
vector<pair<int,pair<string,string> > >vv;
void fun(string x)
{
    if(x.size()==a.size()) {v.pb(x);return ;}
    for(char c='0';c<='9';c++) fun(x+c);
}

//int i;
int main()
{
    freopen("lol.in","r",stdin);
    freopen("lol.out","w",stdout);
    int t;
    cin >> t;
    rep(tt,t)
    {
        v.clear();
        vv.clear();
        cin >> a >> b;
        fun("");
        rep(i,v.size()) rep(j,v.size())
        {
            if(ok(a,v[i])&&ok(b,v[j])) vv.pb(mp( sub(v[i],v[j]) ,mp(v[i],v[j]) ));
        }
        sort(all(vv));
        //rep(i,vv.size()) cout << vv[i].F << " " << vv[i].S.F  << " " << vv[i].S.S << endl ;
        cout << "Case #" << tt+1 << ": " << vv[0].S.F  << " " << vv[0].S.S << endl;
    }

    //fun(a,b);
}
