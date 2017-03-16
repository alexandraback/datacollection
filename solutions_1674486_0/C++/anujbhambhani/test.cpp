#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long lint;typedef vector<int> vi;typedef vector<vi> vii;typedef pair<int, int> p;
class node{public :    int x;    int y;    int cost;};
bool operator < ( const node & first, const node & second){    return first.cost<second.cost;}
int vis[1001];
int mat[1001][1001];
int n;
bool dfs(int i)
{
    bool ans=1;
    for(int j=0;j<n;j++)
    {
        if(mat[i][j])
        {
            if(vis[j])
            ans&=0;
            vis[j]=1;
            ans&=dfs(j);
        }
    }
    return ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    cout << setiosflags(ios::fixed) << setprecision(4);
    int cs;
    cin>>cs;

    for(int sc=1;sc<=cs;sc++)
    {
        cout<<"Case #"<<sc<<":";
        cin>>n;
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++)
                mat[x][y]=0;
        for(int x=0;x<n;x++)
        {
            int m;
            cin>>m;
            for(int y=0;y<m;y++)
            {
                int nn;cin>>nn;
                mat[x][nn-1]=1;
            }
        }
        int x;
        for(x=0;x<n;x++)
        {
            memset(vis,0,sizeof(vis));
            bool f=dfs(x);
            if(f==0)break;
        }
        if(x==n)
        cout<<" No\n";
        else
        cout<<" Yes\n";
    }
    return 0;
}
