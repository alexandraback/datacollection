#include <bits/stdc++.h>
using namespace std;

#define MAX 103

int tab[MAX][MAX], ans[MAX][MAX];

bool verify(int n, int id, int j){
    set<int> q;
    for (int i = 0; i < n; i++)
        q.insert(tab[id][i]);

    for (int i = 0; i < 2*n-1; i++){
        if (i == id) continue;
        if (q.find(tab[i][j]) != q.end())
            q.erase(tab[i][j]);
    }
    return q.empty();
}

int check(int n, int id, int j, int l=-1){
    int c = 0;
    for (int i = 0; i < n; i++){
        if (i == l) continue;
        if (tab[id][i] == ans[i][j])
            c++;
    }
    return c;
}

void write_line(int n, int id, int line){
    for (int i = 0; i < n; i++)
        ans[line][i] = tab[id][i];
}

void write_column(int n, int id, int column){
    for (int i = 0; i < n; i++)
        ans[i][column] = tab[id][i];
}

int main(){
    int t, cases = 1;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        map<int, int> q;
        for (int i = 0; i < 2*n-1; i++)
            for (int j = 0; j < n; j++){
                int aux;
                cin >> aux;
                if (q.find(aux) == q.end())
                    q[aux] = 0;
                q[aux]++;
            }

        vector<int> wr;
        for (auto p : q){
            if (p.second % 2)
                wr.push_back(p.first);
        }
        cout << "Case #" << cases++ << ": ";
        sort(wr.begin(), wr.end());

        for (int i = 0; i < wr.size(); i++)
            cout << wr[i] << " ";
        cout << endl;


        /*vector<bool> mark(n, false);
        vector<bool> usage(2*n-1, false);
        for (int i = 0; i < 2*n-1; i++){
            for (int j = 0; j < n; j++){
                if (mark[j]) continue;
                if (verify(n, i, j)){
                    write_line(n, i, j);
                    mark[j] = true;
                    usage[i] = true;
                }
            }
        }

        int missing_line = -1;
        for (int i = 0; i < n; i++)
            if (!mark[i]){
                missing_line = i;
                break;
            }


        if (missing_line != -1){
            vector<int> wr;
            for (int i = 0; i < 2*n-1; i++){
                if (!usage[i]){
                    wr.push_back(tab[i][missing_line]);
                }
            }

                    }
        else{
            cout << "SOMETHING WRONG" << endl;;
        }*/


    }
    return 0;
}
