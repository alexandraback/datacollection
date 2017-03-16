#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int Maxn=1010;

vector<int> vec[Maxn],rvec[Maxn],root;

set<int>::iterator it;
int flag[Maxn],rflag[Maxn];
bool f[Maxn][Maxn];
int ans;
void dfs(int i)
{
    flag[i] = 1;
    if(flag[vec[i][0]] == 1)
    {
        return;
    }
    dfs(vec[i][0]);
}
void check(int N)
{
    memset(flag,0,sizeof(flag));
    for(int i = 1;i <= N;i ++)
    {
        if(flag[i] == 0)
        {
            root.push_back(i);
            dfs(i);
        }
    }
    //for(int i = 0;i < root.size();i ++)
    //    cout<<root[i]<<" ";
}
int getrev(int x,int cnt,int Max)
{
    //cout<<"x = "<<x<<endl;
    if(rvec[x].size() <= 0)
    {

        Max = max(Max,cnt);
        //cout<<"Max = "<<Max<<endl;
        return Max ;
    }
    for(int i = 0;i < rvec[x].size();i ++)
    {
        if(rflag[rvec[x][i]] == false)
        {

            rflag[rvec[x][i]] = true;
            Max = getrev(rvec[x][i],cnt + 1,Max);
        }
    }

    return Max;
}
void getCircle(int x)
{
    if(flag[vec[x][0]] != 0)
    {
        //cout<<x<<" "<<vec[x][0]<<" "<<flag[x]<<" "<<flag[vec[x][0]]<<endl;
        if(!f[x][vec[x][0]])
        {
            if(abs(flag[x] - flag[vec[x][0]]) > 1)
                ans = max(ans,abs(flag[x] - flag[vec[x][0]]) + 1);
            else
            {
                int tmp = 2;
                rflag[vec[x][0]] = true;
                tmp += getrev(x,0,0);
                //cout<<"tmp = "<<tmp - 2<<endl;
                tmp += getrev(vec[x][0],0,0);
                //cout<<" tmp = "<<tmp<<endl;
                ans = max(ans,tmp);
            }
            f[x][vec[x][0]] = f[vec[x][0]][x] = true;
        }
        return;
    }

    flag[vec[x][0]] = flag[x] + 1;
    getCircle(vec[x][0]);
}
int main()
{
    freopen("C-small-attempt2.in","r",stdin);
    freopen("C-small-attempt2.out","w",stdout);
    int T,N,x;
    cin>>T;
    for(int cas = 1;cas <= T;cas ++)
    {
        cin>>N;
        for(int i = 0;i <= N;i ++)
            vec[i].clear(),rvec[i].clear(),root.clear();
        for(int i = 1;i <= N;i ++)
        {
            cin>>x;
            vec[i].push_back(x);
            rvec[x].push_back(i);
        }
        check(N);
        cout<<"Case #"<<cas<<": ";
        ans = 0;
        for(int i = 0;i < root.size();i ++)
        {
            for(int j = 0;j <= N;j ++)
                flag[j] = rflag[j] = 0;
            for(int j = 0;j <= N;j ++)
                for(int k = 0;k <= N;k ++)
                    f[j][k] = f[k][j] = 0;
            flag[root[i]] = 1;

            getCircle(root[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
