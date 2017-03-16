#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

const int keyMaxConst = 201;
const int chestMaxConst = 201;
int keyMax = 0;

class Chest {
    public:
        int open;
        int contains[keyMaxConst];
        int netChange[keyMaxConst];
        Chest() {
            for(int i = 0; i < keyMaxConst; i++) contains[i] = 0;
        }
        void calcNet() {
            for(int i = 0; i < keyMaxConst; i++) netChange[i] = contains[i] - (open == i ? 1 : 0);
        }
};

class State {
public:
    int N;
    Chest * c;
    int order[chestMaxConst];
    int nOpened;
    bool opened[chestMaxConst];
    int keysCount[keyMaxConst];
    int keysTot[keyMaxConst];

    State(int Nin, int keyCount[], int keyTot[], Chest * cin) {
        N = Nin; c = cin;
        nOpened = 0;
        for(int i = 0; i < keyMaxConst; i++) keysCount[i] = keyCount[i];
        for(int i = 0; i < keyMaxConst; i++) keysTot[i] = keyTot[i];
        for(int i = 0; i < chestMaxConst; i++) opened[i] = false;
    }

    bool verifyIndividuallyPossible() {
        for(int i = 0; i < N; i++) {
            if(!opened[i] && keysCount[c[i].open] == 0) {
                bool ok = false;
                for(int j = 0; j < N && !ok; j++)
                    if(c[j].open != c[i].open && c[j].contains[c[i].open] > 0) ok = true;
                if(!ok) { /*cout << "Couldn't open " << (i+1) << " ever after "; printSeq(); cout << endl;*/ return false; }
            }
        }
        return true;
    }

    bool canOpen(int m) {
        return (!opened[m] && keysCount[c[m].open] > 0);
    }
    bool open(int m) {
        opened[m] = true;
        order[nOpened] = m;
        nOpened++;
        for(int i = 0; i < keyMax; i++) {
            keysCount[i] += c[m].netChange[i];
            keysTot[i] += c[m].netChange[i];
        }
    }
    void close(int m) {
        opened[m] = false;
        nOpened--;
        for(int i = 0; i < keyMax; i++) {
            keysCount[i] -= c[m].netChange[i];
            keysTot[i] -= c[m].netChange[i];
        }
    }
    void printSeq() {
        for(int i = 0; i < nOpened; i++)
            cout << (order[i]+1) << " ";
    }
};

bool dfs(State& s) {
    if(s.nOpened == s.N) {cout << "YEAH!" << endl; return true; }
    if(!s.verifyIndividuallyPossible()) return false;

    bool x = false;
    for(int m = 0; m < s.N && !x; m++) {
        //cout << "Trying chest " << m << " in pos " << s.nOpened << endl;
        if(s.canOpen(m)) {
            //cout << "\t\t\tyep - " << s.keysCount[s.c[m].open] << " of key " << s.c[m].open << endl;
            s.open(m);
            x = x || dfs(s);
            s.close(m);
        }/* else {
            cout << "\t\t\tnope; " << (s.opened[m] ? "opened." : "only have ");
            if(!s.opened[m]) cout << s.keysCount[s.c[m].open] << " of key " << s.c[m].open << endl;
            cout << endl;
        }*/
    }
    return x;
}

string solve(int K, int N, int keys[], Chest c[]) {
    int keysTot[keyMaxConst] = {0};
    int keyCount[keyMaxConst] = {0};

    for(int k = 0; k < K; k++) { keysTot[keys[k]]++; keyCount[keys[k]]++; }

    for(int k = 0; k < keyMax; k++) {
        for(int m = 0; m < N; m++)
            keysTot[k] += c[m].netChange[k];
        if(keysTot[k] < 0) {cout << " - Insufficient copies of key " << k << endl; return "IMPOSSIBLE"; }
    }

    State s(N, keyCount, keysTot, c);
    if(!dfs(s))
        return "IMPOSSIBLE";

    stringstream ss;
    for(int m = 0; m < N; m++)
        ss << (s.order[m]+1) << " ";

    return ss.str();
}

int main() {
    string fn = "in.txt";
    ifstream in(fn.c_str());
    ofstream out("out.txt");

    int n;

    in >> n;

    for(int i = 0; i < n; i++) {
        int K, N;
        in >> K >> N;
        int keys[K];
        Chest c[N];

        cout << K << " / " << N << endl;

        for(int k = 0; k < K; k++) { in >> keys[k]; if(keyMax < keys[k]) keyMax = keys[k]+1; }
        for(int m = 0; m < N; m++) {
            in >> c[m].open; if(keyMax < c[m].open) keyMax = c[m].open+1;
            int myk; in >> myk;
            for(int k = 0; k < myk; k++) { int x; in >> x; c[m].contains[x]++; if(keyMax < x) keyMax = x+1; }
            c[m].calcNet();
            //for(int k = 0; k < keyMax; k++) cout << "Chest " << m << " has net " << c[m].netChange[k] << " of key " << k << endl;
        }

        string ans = solve(K, N, keys, c);

        cout << "Case #" << (i+1) << ": " << ans << endl;
        out << "Case #" << (i+1) << ": " << ans << endl;
    }

    return 0;
}
