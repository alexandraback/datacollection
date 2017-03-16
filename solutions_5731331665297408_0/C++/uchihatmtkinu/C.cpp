#include<iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int T;
int N, M;
int a[10];
int no[10];
bool b[10];
int path[10];
int tree[10];
int len;

int w[10][10];
bool found;


void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {cin >>a[i]; no[i] = i;}
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            w[i][j] = 0;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin>>x>>y;
        w[x-1][y-1] = w[y-1][x-1] = 1;
    }
    for (int i = 0; i < N; i++) b[i] = 0;
    for (int i =0; i < N; i++)
        for (int j = i+1; j < N; j++)
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                tmp = no[i];
                no[i] = no[j];
                no[j] = tmp;
            }
}

void print()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (no[j] == path[i]) cout<<a[j];
}

void find_s(int current, int step)
{
    int len_tmp = len;
    int tree_tmp[10];
    if (step == N)
    {
        print();
        found = true;
        return;
    }
    for (int i = 0; i < N; i++)
        if (b[no[i]] == 0)
        {
            for (int j = 0; j < len; j++) tree_tmp[j] = tree[j];

            for (int j = len_tmp - 1; j >= 0; j--)
            {
                if (w[tree[j]][no[i]] == 1)
                {
                    b[no[i]] = 1;
                    path[step] = no[i];
                    len = j + 2;

                    tree[len - 1] = no[i];
                    find_s(no[i],step+1);
                    b[no[i]] = 0;
                    if (found) return;
                }
            }
            len = len_tmp;
            for (int j = 0; j < len; j++) tree[j] = tree_tmp[j];
        }
}


void solve()
{
    for (int i = 0; i < N; i++)
    {
        found = false;
        len = 1;
        b[no[i]] = 1;
        path[0] = no[i];
        tree[0] = no[i];
        find_s(no[i],1);
        b[no[i]] = 0;
        if (found) return;
    }

}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    cin >> T;
    for (int test = 1; test <= T; test++) {
        cout << "Case #" << test << ": ";
        init();
        solve();
        cout << endl;
    }
    return 0;
}
