#include <iostream>
#include <cstring>
using namespace std;

bool map[2010][2010];
int used [2010][2010];
bool reached [2010];
bool hvNode[2010];
bool done;
int n, m, p, q;

bool DFS(int i)
{
    if (hvNode[i] == true)
    {
        for(int j = 0; j < m ; j++)
        {
            if (map[i][j] && !used[i][j])
            {
                if (reached[j] == 1)
                    done = 1;
                reached[j] = 1;
                used[i][j] = 1;
                DFS(j);
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        memset(map,0,sizeof map);
        done = false;
        cin >> m;
        for (int j = 0 ; j < m ; j++)
        {
            cin >> p;
            if (p == 0)
                hvNode[j] = false;
            else
                hvNode[j] = true;
            for (int k =0 ; k < p ; k++)
            {
                cin >> q;
                map[j][q-1] = 1;
            }
        }
        for (int z = 0 ; z < m ; z++)
        {
            DFS(z);
            memset(used,0,sizeof used);
            memset(reached,0,sizeof reached);
        }
        cout << "Case #" <<i+1 << ": ";
        if (done)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}