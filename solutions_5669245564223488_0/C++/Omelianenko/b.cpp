#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<set>
#include<map>
using namespace std;
#define l first
#define r second
#define mp make_pair
#define ll long long
#define pb push_back
#define bro pair<int, int>
#define all(a) (a).begin(), (a).end()

const int N=101;

string s[N], t[N];
int f, n, used[N], T, k, ans, i, j;
vector <int> g[N];
pair <int, int> a[N];

bool vaild(string s)
{
    int used[26];
    for(int i=0; i<26; i++)
        used[i]=0;
    int n=s.length();
    for(int i=0; i<n; i++)
        if(used[s[i]-'a']==0)used[s[i]-'a']=1; else
        if(s[i]!=s[i-1]&&used[s[i]-'a'])return false;
    return true;
}

void dfs(int v, int pr, int d)
{
    used[v]=1;
    t[v]=t[pr]+s[v];
    if(d<n)
    {
        for(int i=1; i<=n; i++)
            if(used[i]==0&&vaild(t[v]+s[i]))dfs(i, v, d+1);
    } else ans++;
    used[v]=0;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("B-small-attempt2.in","r",stdin);
    freopen("3.txt","w",stdout);
    cin>>T;
    while(T--)
    {
        k++;
        f=0;
        ans=0;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>s[i];
            if(!f&&!vaild(s[i]))f=1;
        }
        if(!f)
        for(i=1; i<=n; i++)
            dfs(i, 0, 1);
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
}
