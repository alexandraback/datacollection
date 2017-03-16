#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

long long ansa, ansb;

long long getNum(const string &s) {
    long long res = 0;
    for(size_t i = 0; i < s.length(); i++)
        res = res * 10 + (s[i] - '0');
    return res;
}

void getAns(string a, string b, bool le) {
    int n = a.length();
    for(int i = 0; i < n; i++)
        if(a[i] == '?')
            a[i] = (le? '9' : '0');
    for(int i = 0; i < n; i++)
        if(b[i] == '?')
            b[i] = (le? '0' : '9');
    long long aa = getNum(a), bb = getNum(b);
    if(ansa == -1 || llabs(bb - aa) < llabs(ansb - ansa) ||
       (llabs(bb - aa) == llabs(ansb - ansa) &&
        (aa < ansa || (aa == ansa && bb < ansb)))) {
        ansa = aa;
        ansb = bb;
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        string a, b;
        in >> a >> b;
        int n = a.length();
        ansa = -1;
        ansb = -1;
        bool le = true;
        for(int i = 0; i < n; i++)
            if(a[i] == '?') {
                if(b[i] == '?') {
                    a[i] = '0';
                    b[i] = '1';
                    getAns(a, b, true);
                    a[i] = '1';
                    b[i] = '0';
                    getAns(a, b, false);
                    a[i] = '0';
                    b[i] = '0';
                }
                else {
                    if(b[i] > '0') {
                        a[i] = b[i] - 1;
                        getAns(a, b, true);
                    }
                    if(b[i] < '9') {
                        a[i] = b[i] + 1;
                        getAns(a, b, false);
                    }
                    a[i] = b[i];
                }
            }
            else {
                if(b[i] == '?') {
                    if(a[i] > '0') {
                        b[i] = a[i] - 1;
                        getAns(a, b, false);
                    }
                    if(a[i] < '9') {
                        b[i] = a[i] + 1;
                        getAns(a, b, true);
                    }
                    b[i] = a[i];
                }
                else {
                    if(a[i] == b[i])
                        continue;
                    if(a[i] > b[i])
                        le = false;
                    break;
                }
            }
        getAns(a, b, le);
        out << "Case #" << tt + 1 << ": "
            << setfill('0') << setw(n) << ansa << ' '
            << setfill('0') << setw(n) << ansb << '\n';
    }
    return 0;
}
