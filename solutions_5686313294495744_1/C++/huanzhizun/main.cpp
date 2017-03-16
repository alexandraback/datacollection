#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int MAXN=1005;
int uN,vN;//u,v数目
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)//从左边开始找增广路径
{
    int v;
    for(v=0;v<vN;v++)//这个顶点编号从0开始，若要从1开始需要修改
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {//找增广路，反向
                linker[v]=u;
                return true;
            }
        }
    return false;//这个不要忘了，经常忘记这句
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
char c[22];
vector<string>g1,g2;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,N=0;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(g,0,sizeof(g));
        string x,y;
        int cn1=0,cn2=0;
        g1.clear();
        g2.clear();
        for(int i=0;i<n;i++){
            cin>>x>>y;
            int f1=-1,f2=-1;
            for(int j=0;j<cn1;j++){
                if(x==g1[j]){
                    f1=j;
                    break;
                }
            }
            if(f1==-1){
                f1=cn1++;
                g1.push_back(x);
            }
            for(int j=0;j<cn2;j++){
                if(y==g2[j]){
                    f2=j;
                    break;
                }
            }
            if(f2==-1){
                f2=cn2++;
                g2.push_back(y);
            }
            g[f1][f2]=1;
        }
        uN=cn1;
        vN=cn2;
        printf("Case #%d: %d\n",++N,n-(cn1+cn2-hungary()));
    }
}