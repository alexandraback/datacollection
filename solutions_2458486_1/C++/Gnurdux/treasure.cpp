#include <iostream>
#include <vector>
using namespace std;

int N;
int numstartingkeys[200];
bool used[200];
int opener[200];
vector<int> keys[200];
vector<int> openables[200];
bool keyreached[200];
bool chestreached[200];

void dfschest(int chest);

void dfskey(int key) {
    if (keyreached[key]) return;
    keyreached[key] = true;
    for (vector<int>::iterator i = openables[key].begin(); i != openables[key].end(); i++) {
        dfschest(*i);
    }
}

void dfschest(int chest) {
    if (chestreached[chest] || used[chest]) return;
    chestreached[chest] = true;
    for (vector<int>::iterator i = keys[chest].begin(); i != keys[chest].end(); i++) {
        dfskey(*i);
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int K;
        cin >> K >> N;
        for (int i = 0; i < 200; i++) {
            numstartingkeys[i] = 0;
            openables[i].clear();
        }
        for (int i = 0; i < K; i++) {
            int key;
            cin >> key;
            numstartingkeys[key - 1]++;
        }
        for (int i = 0; i < N; i++) {
            int numkeys;
            cin >> opener[i] >> numkeys;
            opener[i]--;
            openables[opener[i]].push_back(i);
            used[i] = false;
            keys[i].clear();
            for (int j = 0; j < numkeys; j++) {
                int key;
                cin >> key;
                keys[i].push_back(key - 1);
            }
        }
        int chestopened[N];
        int i;
        for (i = 0; i < N; i++) {
            int j;
            for (j = 0; j < N; j++) {
                if (used[j] || numstartingkeys[opener[j]] == 0) continue;
                numstartingkeys[opener[j]]--;
                used[j] = true;
                for (vector<int>::iterator k = keys[j].begin(); k != keys[j].end(); k++) {
                    numstartingkeys[*k]++;
                }
                for (int l = 0; l < 200; l++) {
                    keyreached[l] = false;
                    chestreached[l] = false;
                }
                for (int l = 0; l < 200; l++) {
                    if (numstartingkeys[l] != 0) dfskey(l);
                }
                int l;
                for (l = 0; l < N; l++) {
                    if (!used[l] && !chestreached[l]) break;
                }
                if (l == N) break;
                
                for (vector<int>::iterator k = keys[j].begin(); k != keys[j].end(); k++) {
                    numstartingkeys[*k]--;
                }
                used[j] = false;
                numstartingkeys[opener[j]]++;
            }
            if (j == N) break;
            chestopened[i] = j;
        }
        cout << "Case #" << t << ":";
        if (i == N) {
            for (int j = 0; j < N; j++) cout << ' ' << chestopened[j] + 1;
            cout << '\n';
        } else {
            cout << " IMPOSSIBLE\n";
        }
    }
    return 0;
}
