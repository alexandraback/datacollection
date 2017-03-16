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
#include <cmath>
#include <cstdlib>
#include <ctime>
#define FOR( i,a,b ) for(int i=a;i<b;i++)
#define VI vector<int>
#define VS vector<string>
#define mp make_pair
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define NS string::npos
using namespace std;
vector<vector<int> > adj_list;
vector<int> visited;
int diamond_check(int i)
{
    //cout<<i<<" "<<visited[i]<<endl;
    if(visited[i]==GRAY)
    return 0;
    if(visited[i]==BLACK)
    return 1;
    visited[i]=GRAY;
    int tmp=0;
    for(int k=0;k<adj_list[i].size();k++)
    tmp=tmp|diamond_check(adj_list[i][k]);
    visited[i]=BLACK;
    return tmp;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("a-1c-output-large.txt","w",stdout);
    int test;
    scanf("%d",&test);
    int n;
    for(int k=1;k<=test;k++)
    {

        scanf("%d",&n);
        //cout<<n<<endl;
        adj_list.clear();
        adj_list.resize(n+1);

        for(int i=1;i<=n;i++)
        {
            int temp;
            int m;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
            scanf("%d",&temp);
            adj_list[i].push_back(temp);
            }
        }
        int flag=false;
        for(int i=1;i<=n;i++)
        {
                visited.clear();
                visited.resize(n+1);
                if(diamond_check(i))
                {
                    flag=true;
                    cout<<"Case #"<<k<<": Yes\n";
                    break;
                }
        }
        if(!flag)cout<<"Case #"<<k<<": No\n";
    }
return 0;
}
