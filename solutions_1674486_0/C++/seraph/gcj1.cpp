// Template By Fendy Kosnatha (Seraph)
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstring>
#include <string.h>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>

using namespace std;
vector<int> v[1001];
int root[1001];
int visit[1001];
int ada;
void DFS(int a)
{
    if (visit[a]==1)
        {
            ada=1;
            return;
        }
    visit[a] = 1;
    for (int i=0;i<v[a].size();i++)
    {
        
        DFS(v[a][i]);
        if (ada==1) return;
    }
}
int main()
{
    int tc;
    int count=1;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        memset(root, 0, sizeof(root));
        ada=0;
        for (int i=1;i<=n;i++)
        {
            int t;
            cin>>t;
            v[i].clear();
            for (int j=0;j<t;j++)
            {
                int temp;
                cin>>temp;
                v[i].push_back(temp);
                root[temp]=1;
            }
        }
        for (int i=1;i<=n;i++)
        {
            if (root[i]==0)
            {
                memset(visit, 0, sizeof(visit));
                DFS(i);
                if (ada==1) break;
            }
        }
        cout<<"Case #"<<count++<<": ";
        if (ada==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
