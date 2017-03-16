#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <set>
using namespace std;
int N;

string R(int I, vector <int> chests, vector <int> myKeys, vector <int> &chestKeyTypes, vector <vector <int> > &keysInChest) {
    string ans = "";
    int opened = 0;
    bool b = true;
    while (b) {
        b = false;
        for (int i = I; i < N; i++) {
            if (chests[i]) continue;
            int k = myKeys.size();
            if(!k) return "";
            bool haveKey = false;
            for (int j = 0; j < k; j++) {
                if (chestKeyTypes[i] == myKeys[j]) {
                    haveKey = true;
                    myKeys.erase(myKeys.begin() + j);
                    break;
                }
            }
            if (!haveKey) continue;
            chests[i] = 1;
            myKeys.insert(myKeys.end(), keysInChest[i].begin(), keysInChest[i].end());
            stringstream ss;
            string s;
            ss << i + 1; ss >> s;
            ans += s + ' ';
            opened++;
            I = 0;
            b = true;
            break;
        }
    }
    return opened == N ? ans : "";
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int K, x;
        string ans = "";
        cin >> K >> N;
        vector <int> myKeys(K), chestKeyTypes(N);
        vector <vector <int> > keysInChest(N);
        vector <int> chests(N, 0);
        for (int i = 0; i < K; i++) {
            cin >> myKeys[i];
        }
        for (int i = 0; i < N; i++) {
            int n;
            cin >> chestKeyTypes[i] >> n;
            for (int j = 0; j < n; j++) {
                cin >> x;
                keysInChest[i].push_back(x);
            }
        }
        for (int i = 0; i < N; i++){
            ans = R(i, chests, myKeys, chestKeyTypes, keysInChest);
            if(ans != "") break;
        }
        ans = (ans == "") ? "IMPOSSIBLE" : ans.substr(0, ans.size()-1);
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}
