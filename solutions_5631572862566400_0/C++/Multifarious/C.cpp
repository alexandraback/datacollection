
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <stack>
#include <cmath>
#include <string.h>
#include <queue>
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;

int N;
const int MAXN = 1005;

int child[MAXN];
int marked[MAXN];
int cycle_size[MAXN];
int graph_num[MAXN];
int G[MAXN][MAXN];

int traceback(int pos)
{
    int best = 1;
    for(int i = 0; i < N; i++)
    {
        if((G[i][pos] == 1) && (G[pos][i] != 1))
        {
            int next = 1 + traceback(i);
            if(next > best)
            {
                best = next;
            }
        }
    }
    return best;
}

void dfs(int step, int pos)
{
    if(cycle_size[pos] > 0)
    {
        return;
    }
    if(marked[pos] < 0)
    {
        return;
    }
    if(marked[pos] > 0)
    {
        int cycle = step - marked[pos];
        cycle_size[pos] = cycle;
        int npos = child[pos];
        while(npos != pos)
        {
            cycle_size[npos] = cycle;
            npos = child[npos];
        }
        return;
    }
    else
    {
        marked[pos] = step;
        dfs(step+1,child[pos]);
        marked[pos] = -1;
        return;
    }
}

int main()
{
    int T;
	cin >> T;

	for(int tcase = 1; tcase <= T; tcase++)
	{
        cin >> N;
        memset(marked,0,sizeof(marked));
        memset(cycle_size,0,sizeof(cycle_size));
        memset(G,0,sizeof(G));
        
        for(int i = 0; i < N; i++)
        {
            cin >> child[i];
            child[i]--;
            G[i][child[i]] = 1;
        }
        for(int i = 0; i < N; i++)
        {
            dfs(1,i);
        }

        int maxs = 0;
        for(int i = 0; i < N; i++)
        {
            if(cycle_size[i] > maxs)
            {
                maxs = cycle_size[i];
            }
        }
        int sm = 0;
        for(int i = 0; i < N; i++)
        {
            if(cycle_size[i] == 2)
            {
                int next = traceback(i);
                sm += next;
            }
        }
        //deb(maxs);
        //deb(sm);
        if(maxs < sm)
        {
            maxs = sm;
        }
        printf("Case #%d: %d\n",tcase,maxs);
	}
	return 0;
}