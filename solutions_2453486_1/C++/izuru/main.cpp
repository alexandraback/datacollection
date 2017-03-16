#include <iostream>

using namespace std;

string F[4];
string G[4];
string D[2];

string solve() {
    for (int i = 0; i < 4; i++) {
        if (F[i] == "XXXX" || F[i] == "TXXX" || F[i] == "XTXX" || F[i] == "XXTX" || F[i] == "XXXT") 
            return "X won";
        if (F[i] == "OOOO" || F[i] == "TOOO" || F[i] == "OTOO" || F[i] == "OOTO" || F[i] == "OOOT") 
            return "O won";
    }
    for (int i = 0; i < 4; i++) {
        if (G[i] == "XXXX" || G[i] == "TXXX" || G[i] == "XTXX" || G[i] == "XXTX" || G[i] == "XXXT") 
            return "X won";
        if (G[i] == "OOOO" || G[i] == "TOOO" || G[i] == "OTOO" || G[i] == "OOTO" || G[i] == "OOOT") 
            return "O won";
    }
    for (int i = 0; i < 2; i++) {
        if (D[i] == "XXXX" || D[i] == "TXXX" || D[i] == "XTXX" || D[i] == "XXTX" || D[i] == "XXXT") 
            return "X won";
        if (D[i] == "OOOO" || D[i] == "TOOO" || D[i] == "OTOO" || D[i] == "OOTO" || D[i] == "OOOT") 
            return "O won";
    }
 
    // finished?
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (F[i][j] == '.') {
                return "Game has not completed";
            }
        }
    }
    return "Draw";
}

void initGD() {
    for (int i = 0; i < 4; i++) G[i] = "....";
    for (int i = 0; i < 2; i++) D[i] = "....";
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++) 
            G[i][j] = F[j][i];
    for (int i = 0; i < 4; i++) {
        D[0][i] = F[i][i];
        D[1][i] = F[i][3-i];
    }
    //cout << "G: " << endl;
    //for (int i = 0; i < 4; i++) {
    //    for (int j = 0; j < 4; j++) {
    //        cout << G[i][j];
    //    }
    //    cout << endl;
    //}
    //cout << "D: " << endl;
    //for (int i = 0; i < 2; i++) {
    //    for (int j = 0; j < 4; j++) {
    //        cout << D[i][j];
    //    }
    //    cout << endl;
    //}
}

int T;
string s;
int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 0; i < 4; i++) cin >> F[i]; initGD();
        getline(cin, s);
        cout << "Case #" << tc << ": " << solve() << endl;
    }
    return 0;
}
