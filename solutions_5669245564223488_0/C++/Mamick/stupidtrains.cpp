#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> strings;
int numUsed;
bool used[15];
int n;
int total;
int chosen[15];

bool works() {
    bool visited[50];
    char current;
    current = strings[chosen[0]][0];
    memset(visited, 0, sizeof(visited));
    visited[current - 'a'] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < strings[chosen[i]].length(); j++) {
            if (strings[chosen[i]][j] != current) {
                current = strings[chosen[i]][j]; 
                if (visited[current - 'a']) return false;
                visited[current - 'a'] = true;
            }
        }
    }
    return true;
}

void countWays() {
    if (numUsed == n) {
        // for (int i  = 0; i < n; i++) {
        //     cout << strings[chosen[i]] ;
        // }
        // cout << endl;
        if (works()) total++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            numUsed++;
            chosen[numUsed - 1] = i;
            countWays();
            numUsed--;
            used[i] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; cases++) {
        cin >> n;
        numUsed = 0;
        total = 0;
        strings.clear();
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            strings.push_back(tmp);
        }
        countWays();
        cout << "Case #" << cases << ": " << total << endl;
    }
}