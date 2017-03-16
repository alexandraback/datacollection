#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

const inline int __GET_INT(){int ret;scanf("%d",&ret);return ret;}
#define INPT_INT __GET_INT()

typedef long long LL;

int N, M;
string code[10];
bool adj[10][10];
vector<int> v;

void dfs(int &i)
{
    int cur = v[i];

    while( i+1 < v.size() )
    {
        int next = v[i+1];

        if( adj[cur][next] )
        {
            ++i;
            dfs(i);
        }
        else break;
    }
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small.out","w",stdout);

    int caseCnt = INPT_INT;

    for(int cNo = 1;cNo<=caseCnt;++cNo)
    {
        N = INPT_INT; M = INPT_INT;
        memset(adj,0,sizeof(adj));

        for(int i = 0;i<N;++i)
        {
            cin>>code[i+1];
        }

        for(int i = 0;i<M;++i)
        {
            int u = INPT_INT, v = INPT_INT;

            adj[u][v] = adj[v][u] = 1;
        }

        v.clear();
        string res = "";
        for(int i = 0;i<N;++i) v.push_back(i+1);

        do
        {
            int i = 0; dfs(i);

            if(i+1==v.size())
            {
                string tmp = "";
                for(int j = 0;j<v.size();++j) tmp += code[ v[j] ];
                if(res=="") res = tmp;
                else res = min(res,tmp);
            }
        }
        while( next_permutation(v.begin(),v.end()) );

        printf("Case #%d: ",cNo); printf("%s\n",res.c_str());
    }
    return 0;
}
