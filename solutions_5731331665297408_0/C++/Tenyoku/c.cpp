#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool G[10][10];
string zip[10];
int n, m;
int pos;
bool dfs(int node, int *list)
{
    if(node == list[pos]) ++pos;
    while(pos != n)
    {
        if(!G[node][list[pos]]) return false;
        dfs(list[pos], list);
    }
    return true;
}

int main()
{
    int T;
    cin >>T;
    for(int cas=1; cas<=T; ++cas)
    {
        cin >>n >>m;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                G[i][j] = 0;
        for(int i=0; i<n; ++i)
            cin >>zip[i];
        int a, b;
        for(int i=0; i<m; ++i)
        {
            cin >>a >>b;
            G[a-1][b-1] = G[b-1][a-1] = 1;
        }
        int list[10];
        for(int i=0; i<n; ++i) list[i] = i;
        string ans = "A";
        do
        {
            pos = 0;
            string tmp = "";
            for(int i=0; i<n; ++i)
                tmp += zip[list[i]];
            if(tmp < ans && dfs(list[0], list))
                ans = tmp;
        }while(next_permutation(list, list+n));
        cout <<"Case #" <<cas <<": " <<ans <<endl;
    }
}
