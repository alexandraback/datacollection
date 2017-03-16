#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)                              for (i=a;i<b;i++)
#define FORL(i,size)                            for (i=0;i<size;i++)
#define FORR(i,size)                            for (i=size-1;i>=0;i--)
#define s(n)                                    scanf("%d",&n)
#define p(n)                                    printf("%d\n",n)
#define ps(n)                                   printf("%s\n",n)
#define sd(n)                                   int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define mp(a,b)                                 make_pair(a,b)
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int> > > TG;
int i, j, k;

int mulmod(int a, int b, int MOD = 1000000007) {
    ll t = (ll) a*b;
    if (t >= MOD) t = t % MOD;
    return t;
}

int fact(int n, int MOD = 1000000007)
{
    int ans=1;
    for(int p=2;p<=n;p++)
    {
        ans=mulmod(ans,p,MOD);
    }
    return ans;
}

bool check(string s, char c)
{
    for(int p=0;p<s.size();p++)
    {
        if(s[p]!=c)
            return false;
    }
    return true;
}

int main() {

    int T = 1;
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //T = g_fi.ReadNext();
    cin>>T;

    FOR(k, 1, T+1) {
        cout<<"Case #"<<k<<": ";
        int n;
        cin>>n;
        vector <string> cs(n);
        multiset <string> cas;
        FOR(i,0,n)
        {
            cin>>cs[i];
            cas.insert(cs[i]);
        }        
        int ans=1;
        int cnt = 0;
        char c = cs[0][0];
        
        FOR(i,0,26)
        {
            string ns = "";
            char c = 'a'+i;
            int cnt=0;
            FOR(j,0,n)
            {
                if(check(cs[j],c))
                {
                    cas.erase(cs[j]);
                    ns+=cs[j];
                    cnt++;
                }
            }
            if(ns.size()>0)
                cas.insert(ns);
            ans=mulmod(ans,fact(cnt));
        }
        set<string> cbs;
        while(!cas.empty())
        {
            string s = *cas.begin();
            cas.erase(s);
            char c = s[0];
            char d = s[s.size()-1];
            bool f1=false;
            tr(cbs,jj)
            {
                string s1 = *jj;
                if(s1[0]==d)
                {
                    cbs.erase(s1);
                    string s2 = s + s1;
                    cbs.insert(s2);
                    f1=true;
                    break;
                }
                if(s1[s1.size()-1]==c)
                {
                    cbs.erase(s1);
                    string s2 = s1 + s;
                    cbs.insert(s2);
                    f1=true;
                    break;
                }
            }
            if(!f1)
            {
                cbs.insert(s);
            }
        }
        int k=0;
        vector<int> cf(26,-1);
        bool f = true;
        tr(cbs,ii)
        {
            string s = *ii;
            FOR(i,0,s.size())
            {
                int si = (int)(s[i]-'a');
                if(cf[si]==-1)
                    cf[si]=k;
                else if(cf[si]>=0 && cf[si]!=k)
                {
                    f=false;
                    break;
                }
            }
            if(!f)
                break;
            k++;
        }
        if(!f)
            cout<<0<<endl;
        else
            cout<<mulmod(ans,fact(k))<<endl;
    }
    
    return 0;
}