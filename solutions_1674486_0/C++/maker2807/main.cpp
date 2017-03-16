#include <iostream>
#include <vector>

using namespace std;

bool dfs(int i,vector <bool> &visited, vector <vector <int> > &inh) {
    for (int k=0; k<inh[i].size(); k++) {
        if (visited[inh[i][k]]) {
            //cerr << "from " << i << " visited " << inh[i][k] << " " <<  visited[inh[i][k]] << endl;
            //cerr << inh[i][k] << " " << visited[inh[i][k]];
            return true;
        }
        else {
            visited[inh[i][k]] = true;
            //cerr << "rek" << endl;
            if (dfs(inh[i][k],visited,inh)) return true;
        }
    }
    return false;
}


int main()
{
    int T;

    cin >> T;

    for (int k=1; k<=T; k++) {
        int N;
        cin >> N;
        vector <vector <int> > inh;
        vector <bool> visited_f(N,false);
        for (int i=0; i<N; i++) {
            int m;
            cin >> m;
            vector <int> p(m);
            for (int j=0; j<m; j++) {
                cin >> p[j];
                p[j]--;
            }
            inh.push_back(p);
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<inh[i].size(); j++) {
                //cout << inh[i][j] << " ";
            }
            //cout << endl;
        }
        cout << "Case #" << k <<": ";
        bool wrt = false;
        for (int i=0; i<N; i++) {
            vector <bool> visited = visited_f;
            //for (int p=0; p<N; p++) cout << visited[p];
            //cout << endl;
            if (dfs(i,visited,inh)) {
                cout << "Yes";
                wrt = true;
                break;
            }
        }
        if (!wrt) cout << "No";
        cout << endl;


    }
    return 0;
}
