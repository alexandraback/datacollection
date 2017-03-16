#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

ifstream fin;
ofstream fout;

int f[1005][1005];
bool used[1005];
bool can;

void set0(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        used[i] = false;
    }
}

void dfs(int now)
{
    if (used[now])
        can = true;
    if (can) return;

    used[now] = true;
    for (int i = 1; i <= f[now][0]; ++i)
    {
        dfs(f[now][i]);
    }
}

void solve(int num)
{
    int n,edgeNum = 0;
    fin>>n;
    for (int i = 1; i <= n; ++i)
    {
        int w;
        fin>>w;
        f[i][0] = w;
        for (int j = 1; j <= w; ++j)
        {
            int delta;
            fin>>delta;
            f[i][j] = delta;
        }
    }
    can = false;

    for (int i = 1; i <= n; ++i)
    {
        set0(n);
        dfs(i);
    }

    if (can)
        fout<<"Case #"<<num<<": "<<"Yes"<<endl;
    else
        fout<<"Case #"<<num<<": "<<"No"<<endl;
}

int main()
{
    int total;
    fin.open("input.txt");
    fout.open("output.txt");

    fin>>total;
    for (int i=1;i<=total;++i)
    {
        solve(i);
    }

    fin.close();
    fout.close();
    return 0;
}
