#include <bits/stdc++.h>

using namespace std;

int main() {


    int t;
    cin >> t;


    for(int ti = 1; ti <= t; ti++) {

        int b, m;
        cin >> b >> m;

        long long maxb = 1 + (b * (b + 1))/2;

        if(m > maxb){
            cout <<"Case #"<< ti <<": IMPOSSIBLE\n";
        }else{

            int npath = 1;

            vector<vector<int> > graph(b, vector<int>(b));
            graph[0][b - 1] = 1;

            for(int i = 0; i < b - 2 && npath < m; i++){
                for(int j = i + 1; j < b - 1; j++){
                    if(npath == m) break;
                    graph[i][j] = 1;
                    graph[j][b - 1] = 1;
                    npath++;
                }
            }

            cout <<"Case #"<< ti <<": POSSIBLE\n";
            for(int i = 0; i <b; i++){
                for(int j = 0; j < b; j++){
                    cout << graph[i][j];
                }
                cout << '\n';
            }

        }
    }

    return 0;
}

