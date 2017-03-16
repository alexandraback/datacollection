#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
using namespace std;
int aabs(int a) {
    if (a < 0)
        return -a;
    return a;
}
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        char pa[100] = "";
        char pb[100] = "";
        char pao[100] = "";
        char pbo[100] = "";
        string ttt[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        cout << "Case #" << t << ": ";
        cin >> pa >> pb;
        int len = strlen(pa);
        map<string, int> a[20], b[20];
        string tmp = "";
        a[0][tmp] = 1;
        b[0][tmp] = 1;
        for (int i = 0; i < len; i++) {
            auto iter = a[i].begin();
            while (iter != a[i].end()) {
                tmp = iter->first;
                if (pa[i] == '?') {
                    for (int j = 0; j < 10; j++) {
                        a[tmp.length()+1][tmp+ttt[j]] = 1;
                    }
                } else {
                    a[tmp.length()+1][tmp+ttt[pa[i]-'0']] = 1;
                }
                iter++;
            }
        }
        for (int i = 0; i < len; i++) {
            auto iter = b[i].begin();
            while (iter != b[i].end()) {
                tmp = iter->first;
                if (pb[i] == '?') {
                    for (int j = 0; j < 10; j++) {
                        b[tmp.length()+1][tmp+ttt[j]] = 1;
                    }
                } else {
                    b[tmp.length()+1][tmp+ttt[pb[i]-'0']] = 1;
                }
                iter++;
            }
        }
        int mmin = 2147483647;
        string cca = "";
        string ccb = "";
        for (auto ai = a[len].begin(); ai != a[len].end(); ai++) {
            std::string::size_type sz;
            int aaa = stoi(ai->first, &sz);
            for (auto bi = b[len].begin(); bi != b[len].end(); bi++) {
                int bbb = stoi(bi->first, &sz);
                if (aabs(aaa-bbb) < mmin) {
                    mmin = aabs(aaa-bbb);
                    cca = ai->first;
                    ccb = bi->first;
                }
            }
        }
        cout << cca << " " << ccb << endl;
    }
    return 0;
}
