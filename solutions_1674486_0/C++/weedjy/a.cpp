#include <cstdlib>
#include <iostream>

using namespace std;

int m[1000];
int mi[1000][1000];


int dfs(int node, int s[])
{
//    cout << "started at " << node << endl;
    if(s[node] == 1) 
    {
//        cout << node << " is already visited" << endl;
        return 1;
    }
    else s[node] = 1;
//    if(m[node]==0) cout << "stopped at " << node << endl;
    for(int j = 0; j < m[node]; j++)
    {
//        cout << "searching " << mi[node][j] << endl;
        if(dfs(mi[node][j], s) == 1) return 1;
    }
    return 0;
}

int calc(int k, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(m[i] < 2) continue;
        int s[1000];
        for(int p = 0; p < 1000; p++) s[p] = 0;
        if(dfs(i, s) == 1)
        {
            cout << "Case #" << k+1 << ": Yes" << endl;
            return 0;
        }
    }
    cout << "Case #" << k+1 << ": No" << endl;
    return 1;
}

int dump(int n)
{
    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
        for(int j = 0; j < m[i]; j++)
        {
            cout << mi[i][j] << " ";
        }
        cout << endl;        
    }
}

int main(int argc, char *argv[])
{
    int T;
    cin >> T;

    int k = 0;
    while(k < T)
    {
        for(int p = 0; p < 1000; p++)
        {
            m[p]=-1;
            for(int q = 0; q < 1000; q++) mi[p][q]=-1;
        }

        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> m[i];
            for(int j = 0; j < m[i]; j++)
            {
                cin >> mi[i][j];
                mi[i][j]--;
            }
        }
//        dump(n);
        calc(k, n);
        k++;
    }
    return 0;
}
