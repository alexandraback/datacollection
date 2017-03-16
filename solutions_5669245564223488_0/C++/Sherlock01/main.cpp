#include<iostream>
#include<stack>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
const double eps=1e-6;
const int INF=0x3f3f3f3f;
const int N=103;
vector<int>L;
string s[N];
int ans,n;
int a[N];
bool v[N];
bool OK(string &stmp)
{//cout<<stmp<<endl;
    memset(a,0,sizeof(a));
    for(unsigned int i=0;i<stmp.size();++i)
    {
        if(i==0||stmp[i]!=stmp[i-1])
        {
            if((++a[stmp[i]-'a'])>1)
            {
                return false;
            }
        }
    }
    return true;
}
void dfs()
{
    if(L.size()==n)
    {
        string stmp;
        for(unsigned int i=0;i<L.size();++i)
        {
            stmp+=s[L[i]];
        }
        if(OK(stmp))
        ++ans;
        return ;
    }
    for(int i=1;i<=n;++i)
    {
        if(v[i]) continue;
        L.push_back(i);
        v[i]=true;
        dfs();
        L.erase(L.end()-1);
        v[i]=false;
    }
}
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int T;
    cin>>T;
    for(int ca=1;ca<=T;++ca)
    {
        printf("Case #%d: ",ca);
        cin>>n;
        for(int i=1;i<=n;++i)
        cin>>s[i];

        ans=0;
        memset(v,false,sizeof(v));
        dfs();
        printf("%d\n",ans);
    }
    return 0;
}
