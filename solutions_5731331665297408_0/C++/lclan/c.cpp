#include <bits/stdc++.h>
#define mpr std::make_pair
typedef long long ll;
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
vector<int> edge[100];
int a[100];
int x[100];
int y[100];
int z[100];
int used[100];
int ma[100][100];
vector<int> path;
ll n,m;
bool check()
{
    vector<int> stk;
    int i,tar,fr;
    stk.push_back(z[path[0]]);
    //for(int j=0;j<stk.size();j++)cout<<stk[j]<<' ';
   //     cout<<endl;
    for(i=1;i<path.size();i++)
    {

        tar = z[path[i]];
        while(stk.size()>0)
        {
            fr=stk[stk.size()-1];
            if(ma[fr][tar]==0)
            {
                stk.pop_back();
            }else break;
        }
        if(stk.size()==0)return false;
        stk.push_back(tar);
        //for(int j=0;j<stk.size();j++)cout<<stk[j]<<' ';
       // cout<<endl;
    }
    return true;
}
bool dfs(int now)
{
  //  cout<<now<<' '<<c<<endl;
    if(path.size()==n)
    {
      //  for(int i=0;i<n;i++)cout<<z[path[i]]<<' ';
       // cout<<endl;
        bool ddd=check();
       // cout<<ddd<<endl;
       // system("pause");
        return ddd;
    }
    int i;

    for(i=0;i<n;i++)
    {
        if(used[i]==0)
        {
            path.push_back(i);
            used[i]=1;
            if(dfs(i))return true;
            used[i]=0;
            path.pop_back();
        }
    }
    return false;
}
int main()
{
    freopen("out.txt","w",stdout);
    int i,j,k;
    int t,r;

    r=1;
    bool f;
    cin>>t;
    ll ans;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
           cin>>a[i];
           x[i]=a[i];
        }
        sort(x,x+n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(x[i]==a[j])
                {
                    y[j]=i;
                    z[i]=j;
                    break;
                }
            }
        }
        mst(ma);
        for(i=0;i<m;i++)
        {
            cin>>j>>k;
            j--;k--;
            edge[j].push_back(k);
            edge[k].push_back(k);
            ma[j][k]=ma[k][j]=1;
        }
        int tmp;
        for(i=0;i<n;i++)
        {
            for(j=0;j<edge[i].size();j++)
            {
                for(k=j+1;k<edge[i].size();k++)
                {
                    if(a[edge[i][j]] > a[edge[i][k]])
                    {
                        tmp = edge[i][j];
                        edge[i][j] = edge[i][k];
                        edge[i][k] = tmp;
                    }
                }
            }
        }
        for(i=0;i<n;i++)
        {
            mst(used);
            path.clear();
            path.push_back(i);
            used[i]=1;
            if(dfs(i))
            {
               break;
            }
        }
        cout<<"Case #"<<r<<": ";
        r++;
        for(i=0;i<path.size();i++)
        {
            cout<<a[z[path[i]]];
        }
        cout<<endl;
    }
}
