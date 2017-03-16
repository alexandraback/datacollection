#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

vector<int>V[1010];
vector<int>mark(1010);
vector<int> In(1010);
bool ans = false;

void dfs(int v, int color)
{
   // cout << "v = " << v << endl;
    mark[v] = color;
    for(int i = 0; i < V[v].size(); i++)
    {
        if(mark[V[v][i]] == 0)
            dfs(V[v][i], color);
        else if(mark[V[v][i]] == color)
        {
            //cout << "! "<<V[v][i] << endl;
            ans = true;
        }
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d\n", &n);
    for(int test = 1; test <= n; test++)
    {
        int num;
        cin >> num;
        for(int i = 0; i < num; i++)
        {
            V[i].clear();
            In[i] = 0;
        }
        for(int j = 0; j < num; j++)
        {
            int kol = 1;
                cin >> kol;
                for(int i = 0; i < kol; i++)
                {
                    int t;
                    cin >> t;
                    t--;
                    V[j].pb(t);
                    In[t]++;
            }
        }
        for(int i = 0; i < num; i++)
            mark[i] = 0;
        ans = false;
        for(int i = 0; i < num; i++)
        {
            if(In[i] == 0)
            {
                  for(int y = 0; y < num; y++)
                    mark[y] = 0;

                dfs(i, i + 1);
            }
        }

        cout << "Case #"<< test<<": ";
        if(ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
