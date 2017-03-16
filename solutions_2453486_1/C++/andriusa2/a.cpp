#include <fstream>

using namespace std;

char table[4][4] = {};
void readTable(ifstream & in) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            in >> table[i][j];
}
int win (const char a[]) {
    int ts = 0;
    int os = 0;
    int xs = 0;
    for (int i = 0; i < 4; i++) 
        switch (a[i]) {
        case 'O': os++; break;
        case 'T': ts++; break;
        case 'X': xs++; break;
        default: break;
        }
    if (ts == 0) {
        if (os == 4) return 1;
        if (xs == 4) return 2;
        return 0;
    }
    if (ts > 1) return 0;
    if (xs == 3) return 2;
    if (os == 3) return 1;
    return 0;
}
void parseTable(ofstream & in) {
    char line[4] = {};
    int empty = 0;
    int t = 0;
    for (int i = 0; i < 4; i ++ ) {
        for (int j = 0; j < 4; j++) {
            line[j] = table[i][j];
            if (line[j] == '.') empty++;
        }

        if (t = win(line)) {
            if (t == 1) // 'O' win
                in << "O";
            else in << "X";
            in << " won" << endl;
            return;
        }
    }
    for (int i = 0; i < 4; i ++ ) {
        for (int j = 0; j < 4; j++) {
            line[j] = table[j][i];
        }
        if (t = win(line)) {
            if (t == 1) // 'O' win
                in << "O";
            else in << "X";
            in << " won" << endl;
            return;
        }
    }
    for (int i = 0; i < 4; i++) {
        line[i] = table[i][i];
    }
    if (t = win(line)) {
        if (t == 1) // 'O' win
            in << "O";
        else in << "X";
        in << " won" << endl;
        return;
    } 
    for (int i = 0; i < 4; i++) {
        line[i] = table[i][3-i];
    }
    if (t = win(line)) {
        if (t == 1) // 'O' win
            in << "O";
        else in << "X";
        in << " won" << endl;
        return;
    } 
    if (empty) 
        in << "Game has not completed";
    else in << "Draw";
    in << endl;
}
int main () {
    ifstream file("in.txt");
    ofstream out("out.txt");
    int n = 0;
    file >> n;
    for (int i = 0;i < n; i++) {
        readTable(file);
        out << "Case #" << (i+1) << ": ";
        parseTable(out);
    }
    file.close();
    return 0;
}