#include <bits/stdc++.h>

using namespace std;
int con[100][100];
typedef long long LL;
LL ways[100];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for(int t = 1;t <= tc;++t){
        memset(con, 0, sizeof con);
        int B;
        LL M;
        cin >> B >> M;
        ways[B] = 1;
        --M;
        for(int i = B - 1;i >= 1;--i){
            ways[i] = ways[i + 1];
            con[i][i + 1] = 1;
            for(int j = i + 2;j <= B;++j){
                if(ways[j] <= M){
                    con[i][j] = 1;
                    M -= ways[j];
                    ways[i] += ways[j];
                }
            }
        }
        if(M != 0){
            cout << "Case #" << t << ": IMPOSSIBLE\n";
        } else {
            cout << "Case #" << t << ": POSSIBLE\n";
            for(int i = 1;i <= B;++i){
                for(int j = 1;j <= B;++j){
                    cout << con[i][j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
