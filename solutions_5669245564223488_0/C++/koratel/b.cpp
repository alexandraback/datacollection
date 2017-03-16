#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1 << 30;
const double EPS = 1e-8;
const ll mod=1000000007;

vector<string> v;

ll sprawdz(string s)
{
    int n=s.length();
    vi first(42, 4242), last(42, -1);
    for(int i=0; i<n; i++)
    {
        first[s[i]-'a']=min(i, first[s[i]-'a']);
    }
    for(int i=n-1; i>=0; i--)
    {
        last[s[i]-'a']=max(i, last[s[i]-'a']);
    }
    for(int i=0; i<30; i++)
    {
        for(int j=first[i]; j<last[i]; j++)
        {
            if(s[j]!=(i+'a')) return 0;
        }
    }
    return 1;
}

ll ile(string cur, int mask)
{
    int n=v.size();
    if(!sprawdz(cur)) return 0;
    if(mask+1==(1<<n)) return sprawdz(cur);
    ll temp=0;
    for(int i=0; i<n; i++)
    {
        if((1<<i)&mask) continue;
        temp+=ile(cur+v[i], mask|(1<<i));
    }
    return temp;
}

void solve(int num)
{
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];
    /*sort(v.begin(), v.end());
    int asc=1;
    vector<ll> hist(42, 0);
    for(int i=0; i<n; i++)
    {
        int ile=v[i].length();
        for(int j=0; j+1<ile; j++)
        {
            if(v[i][j]>v[i][j+1]) asc=0;
        }
        if(i+1<n)
        {
            if(v[i][ile-1]>v[i+1][0]) asc=0;
        }
        if(v[i][0]==v[i][ile-1]) hist[v[i][0]-'a']++;
    }
    ll ans=1;
    if(asc)
    {
        for(int i=0; i<30; i++)
        {
            while(hist[i]>1)
            {
                cout<<"razy "<<hist[i]<<endl;
                ans=(ans*hist[i])%mod;
                hist[i]--;
            }
        }
    }
    cout<<"teraz desc\n";

    reverse(v.begin(), v.end());
    for(int i=0; i<n; i++) cout<<v[i]<<" ";
    cout<<endl;
    for(int i=0; i<35; i++) hist[i]=0;
    int desc=1;
    for(int i=0; i<n; i++)
    {
        int ile=v[i].length();
        for(int j=0; j+1<ile; j++)
        {
            if(v[i][j]<v[i][j+1]) desc=0;
        }
        if(i+1<n)
        {
            if(v[i][ile-1]<v[i+1][0]) desc=0;
        }
        if(v[i][0]==v[i][ile-1])
        {
            hist[v[i][0]-'a']++;
            cout<<"dodajemy na "<<(int)v[i][0]-'a'<<endl;
        }
    }
    if(desc)
    {
        cout<<"desc ok\n";
        for(int i=0; i<30; i++)
        {
            while(hist[i]>1)
            {
                cout<<"razy "<<hist[i]<<endl;
                ans=(ans*hist[i])%mod;
                hist[i]--;
            }
        }
    }*/
    cout<<"Case #"<<num<<": ";
    cout<<ile("", 0)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}

