#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<int> coins;

void visit() {
        visited[0] = true;
        for(int cnt = 1; cnt < (1 << (coins.size())); cnt++) {
            int sum = 0;
            for(int i = 0; i < coins.size(); i++) {
                //cout << "cnt: " << cnt << " i: " << i << " sum: " << sum << endl;
                if((1 << i) & cnt) {
                    sum += coins[i];
                    //cout << "sum <- " << coins[i] << endl;
                }
            }
            visited[sum] = true;
        }
}

void revisit(int c, int v) {
    for(int i = v - c; i >= 0; i--) {
        visited[i + c] = (visited[i] || visited[i + c]);
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int t;
    in >> t;
    int c;
    int d;
    int v;
    for(int o = 0; o < t; o++) {
        in >> c >> d >> v;
        visited.clear();
        coins.clear();
        visited.resize(v + 1, false);
        coins.resize(d);
        for(int i = 0; i < d; i++) {
            in >> coins[i];
        }
        visit();
        int res = 0;
        for(int i = 1; i <= v; i++) {
            if(!visited[i]) {
                res++;
                coins.push_back(i);
                revisit(i, v);
            }
            /*cout << "i: " << i << " visited: " << endl;
            for(int j = 0; j < visited.size(); j++) {
                cout << visited[j] << " ";
            }
            cout << endl;
            cout << "coins: " << endl;
            for(int j = 0; j < coins.size(); j++) {
                cout << coins[j] << " ";
            }
            cout << endl;*/
        }
        out << "Case #" << (o + 1) << ": " << res << endl;
    }
    return 0;
}
