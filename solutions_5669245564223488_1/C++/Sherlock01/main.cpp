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
const ll MOD=1000000007;
const int N=10003;
map<char,int>mst;
string s[N];
vector<string>vst;
ll A[N];
int a[N],b[N];
int f(string &stmp)
{
    if(stmp[0]==stmp[stmp.size()-1])
    return 1;
    return 0;
}
int main()
{
    //freopen("data.txt","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    A[0]=((ll)(1));
    for(int i=1;i<N;++i)
    {
        A[i]=(A[i-1]*i)%MOD;
    }
    int T;
    cin>>T;
    for(int ca=1;ca<=T;++ca)
    {
        printf("Case #%d: ",ca);
        mst.clear();
        vst.clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>s[i];
            vst.push_back(s[i]);
            for(unsigned int j=0;j<s[i].size();++j)
            {
                mst[s[i][j]]++;
            }
        }
        ll ans=(ll(1));
        for(char c='a';c<='z';++c)
        {
            int k=0;
            for(int i=1;i<=n;++i)
            {
                if(s[i][0]==c&&s[i][s[i].size()-1]==c)
                {
                    ++k;
                }
            }
            ans=(ans*A[k])%MOD;
        }
        //memset(v,false,sizeof(v));
        while(true)
        {
            bool flag=false;
            for(unsigned int i=0;i<vst.size();++i)
            {
                for(unsigned int j=0;j<vst.size();++j)
                {
                    if(i==j) continue;
                    if(f(vst[i])+f(vst[j])>=2&&vst[i][vst[i].size()-1]==vst[j][0])
                    {
                        vst[i]+=vst[j];
                        vst.erase(vst.begin()+j);
                        flag=true;
                        break;
                    }
                }
                if(flag==true)
                break;
            }
            if(flag==false)
            break;
        }
        while(true)
        {
            bool flag=false;
            for(unsigned int i=0;i<vst.size();++i)
            {
                for(unsigned int j=0;j<vst.size();++j)
                {
                    if(i==j) continue;
                    if(f(vst[i])+f(vst[j])>=1&&vst[i][vst[i].size()-1]==vst[j][0])
                    {
                        vst[i]+=vst[j];
                        vst.erase(vst.begin()+j);
                        flag=true;
                        break;
                    }
                }
                if(flag==true)
                break;
            }
            if(flag==false)
            break;
        }
        while(true)
        {
            bool flag=false;
            for(unsigned int i=0;i<vst.size();++i)
            {
                for(unsigned int j=0;j<vst.size();++j)
                {
                    if(i==j) continue;
                    if(f(vst[i])+f(vst[j])>=0&&vst[i][vst[i].size()-1]==vst[j][0])
                    {
                        vst[i]+=vst[j];
                        vst.erase(vst.begin()+j);
                        flag=true;
                        break;
                    }
                }
                if(flag==true)
                break;
            }
            if(flag==false)
            break;
        }
        for(unsigned int i=0;i<vst.size();++i)
        {
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            for(unsigned int j=0;j<vst[i].size();++j)
            {
                ++b[vst[i][j]-'a'];
                if(j==0||vst[i][j]!=vst[i][j-1])
                {
                    ++a[vst[i][j]-'a'];
                }
            }
            for(int j=0;j<26;++j)
            {
                char c='a'+j;
                if(a[j]>1) ans=0;
                if(a[j]==1&&b[j]<mst[c]) ans=0;
            }
            if(ans==0)
            break;
        }
        int ln=vst.size();
        ans=(ans*A[ln])%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
