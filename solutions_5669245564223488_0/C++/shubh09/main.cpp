#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n;
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'
#define pans(t,ans)                             do{cout<<"Case #"<<t<<": "<<ans<<endl;} while(0)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int fact(int n)
{
    if (n==0) return 1;
    return n*fact(n-1);
}

bool check(string &str)
{
    int n=sz(str);
    vi arr(26,-1);
    int i;
    FOR(i,0,n)
    {
        char c=str[i];
        int ind=c-'a';
        if (arr[ind]==-1)
        {
            arr[ind]=i;
            continue;
        }
        else
        {
            if (arr[ind]+1!=i) return false;
            arr[ind]++;
        }
    }
    return true;
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(T);
    int i,j,t,k;
    FOR(t,0,T)
    {
        sd(n);
        vstr v;
        FOR(i,0,n)
        {
            string str;
            cin>>str;
            v.pb(str);
        }
        bool succ=true;
        FOR(i,0,n)
        {
            vi arr(26,0);
            string str=v[i];
            int n2=sz(str);
            int l=1,u=n2-2;
            while (l<n2&&str[l]==str[0]) l++;
            while (u>=0&&str[u]==str[n2-1]) u--;
            FOR(j,l,u+1) arr[str[j]-'a']++;
            FOR(j,0,n)
            {
                if (i==j) continue;
                string str2=v[j];
                FOR(k,0,sz(str2)) if (arr[str2[k]-'a']>0) succ=false;
            }
            if (!check(str)) succ=false;
            if (!succ) break;
        }
        if (!succ)
        {
            pans(t+1,0);
            continue;
        }
        vstr v2;
        FOR(i,0,n)
        {
            string str=v[i];
            string temp;
            temp.pb(str[0]);
            temp.pb(str[sz(str)-1]);
            v2.pb(temp);
        }
        sort(all(v2));
//        p(sz(v2));
        int ans=0;
        do
        {
            string str;
            FOR(i,0,n) str.append(v2[i]);
            int n2=sz(str);
//            cout<<str<<endl;
            vi arr(26,-1);
            bool succ=true;
            FOR(i,0,n2)
            {
                char c=str[i];
                int ind=c-'a';
                if (arr[ind]==-1)
                {
                    arr[ind]=i;
                    continue;
                }
                else
                {
                    if (arr[ind]+1!=i) succ=false;
                    else arr[ind]++;
                }
                if (!succ) break;
            }
            if (succ)
            {
//                cout<<"Succ "<<str<<endl;
                ans++;
            }
        } while(next_permutation(all(v2)));
        string sss=v2[0];
        int cnt=1;
        FOR(i,1,sz(v2))
        {
            if (sss==v2[i]) cnt++;
            else
            {
                sss=v2[i];
                ans*=fact(cnt);
                cnt=1;
            }
//            cout<<sss<<' '<<cnt<<endl;
        }
        ans*=fact(cnt);
        pans(t+1,ans);
    }
}
