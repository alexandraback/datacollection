#include <bits/stdc++.h>

using namespace std;

void gen(string c, set<int>& pos) {

    vector<bool> up(3);

    for(int i = c.size() - 1, j = 2; i >= 0; i--, j--) {
        if(c[i] == '?') {
            up[j] = 1;
        }
    }

    int u, d, cs;

    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= 9; k++) {
                u = (up[2])? k: c[c.size() - 1] - '0';
                d = (up[1])? j: (c.size() > 1)? c[c.size() - 2] - '0': 0;
                cs = (up[0])? i: (c.size() > 2)? c[0] - '0': 0;
                pos.insert(u+d*10+cs*100);
            }
        }
    }
}


int main() {

    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);

    int t;
    string c, j;
    cin >> t;


    for(int ti = 1; ti <= t; ti++) {

        cin >> c >> j;

        set<int> cq, jq;

        gen(c, cq);
        gen(j, jq);

        int mins = -1, minc, minj;

        for(set<int>::iterator it = jq.begin(); it != jq.end(); ++it) {
            for(set<int>::iterator ic = cq.begin(); ic != cq.end(); ++ic) {

                if(mins == -1) {
                    mins = abs(*it - *ic);
                    minc = *ic;
                    minj = *it;
                }else if( mins > abs(*it - *ic)){
                    mins = abs(*it - *ic);
                    minc = *ic;
                    minj = *it;
                }

            }
        }

        cout <<"Case #"<< ti <<": ";
        cout << setw(c.size()) << setfill('0') << minc << " ";
        cout << setw(j.size()) << setfill('0') << minj << '\n';
    }

    return 0;
}

