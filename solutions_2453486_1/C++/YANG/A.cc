#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string t[10];
        string r;

        for (int j = 0; j < 4; j++) {
            cin >> t[j];
        }

        string* v = &t[4];
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                v[k].push_back(t[j][k]);
            }
        }

        string* d = &t[8];
        for (int j = 0; j < 4; j++) {
            d[0].push_back(t[j][j]);
        }
        for (int j = 0; j < 4; j++) {
            d[1].push_back(t[j][3 - j]);
        }

        for (int j = 0; j < 10; j++) {
            size_t pos = t[j].find('T');
            if (pos != string::npos) {
                t[j][pos] = t[j][pos == 0 ? 1 : 0];
            }
            if (t[j] == "XXXX") {
                r = "X won";
                break;
            } else if (t[j] == "OOOO") {
                r = "O won";
                break;
            }
        }

        if (r == "") {
            for (int j = 0; j < 4; j++) {
                if (t[j].find('.') != string::npos) {
                    r = "Game has not completed";
                    break;
                }
            }
        }

        if (r == "") r = "Draw";

        cout << "Case #" << i << ": " << r << endl;
    }
}
