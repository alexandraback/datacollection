#include <bits/stdc++.h>

using namespace std;

const int me = 1025;


int t;
int b, total;
int a[105][105], used[105];
vector<int> ans[7][30][7];
long long n;

int f(int n, int s){
    int m = --n;
    for(int i = 1; i <= m; i ++){
        if(s <= n)
            return i;
        s -= n;
        n --;
    }
}
int g(int n, int s){
    int m = --n;
    for(int i = 1; i <= m; i ++){
        if(s <= n)
            return i + s;
        s -= n;
        n --;
    }
}
void dfs(int x){
    if(x == n){
        total ++;
        return;
    }
    used[x] = 1;
    for(int i = 1; i <= n ;i ++)
        if(!used[i] && a[x][i])
            dfs(i);
    used[x] = 0;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    for(int i = 0; i < 0; i ++){
        int a, b;
        cin >> a>> b;
        cout << f(a, b) << " and " << g(a, b) << endl;
    }
    for(int i = 1, sum = i; i <= 6; i ++, sum += i)
    for(int j = 0; j < (1 << sum); j ++){
        for(int k = 0; k <= i; k ++)
            for(int q = 0; q <= i; q ++)
                a[k][q] = 0;
        for(int k = sum - 1; k >= 0; k --)
            if(j & (1 << k))
                a[f(i, k + 1)][g(i, k + 1)] = 1;
        total = 0;

        for(int k = 1; k <= i; k ++)
            used[k] = 0;
        n = i;
        dfs(1);
        if(ans[i][total][1].empty()){
            for(int k = 1; k <= i; k ++)
                for(int q = 1; q <= i; q ++)
                    ans[i][total][k].push_back(a[k][q]);
        }
    }
    cin >> t;
    for(int cc = 0; cc < t; cc ++){
        cin >> b >> n;

        cout << "Case #" << cc + 1 << ": ";
        if(ans[b][n][1].empty())
            cout << "IMPOSSIBLE" << endl;
        else{
                cout << "POSSIBLE" << endl;
            for(int i = 1; i <= b; i ++){
                for(int j : ans[b][n][i])
                    cout << j;
                cout << endl;
            }
        }
    }

    return 0;
}
