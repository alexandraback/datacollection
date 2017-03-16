#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL oo = 1000000000000000000LL; //1e18

string s1, s2;

LL ans, so1, so2, num1, num2;

void duyet(int vt) {
    if (vt >= s1.size()) {
        LL tmp = abs(num1-num2);
        if (ans > tmp || (ans == tmp && (num1 < so1 || (num1 == so1 && num2 < so2)))) {
            ans = tmp;
            so1 = num1;
            so2 = num2;
        }
        return;
    }
    int bd1, bd2, kt1, kt2;
    if (num1 < num2) {
        if (s1[vt] == '?') num1 = num1 * 10 + 9;
        else num1 = num1 * 10 + s1[vt] - '0';
        if (s2[vt] == '?') num2 = num2 * 10;
        else num2 = num2 * 10 + s2[vt] - '0';
        duyet(vt+1);
        num1 /= 10;
        num2 /= 10;
    }
    else if (num1 > num2) {
        if (s1[vt] == '?') num1 = num1 * 10;
        else num1 = num1 * 10 + s1[vt] - '0';
        if (s2[vt] == '?') num2 = num2 * 10 + 9;
        else num2 = num2 * 10 + s2[vt] - '0';
        duyet(vt+1);
        num1 /= 10;
        num2 /= 10;
    }
    else {
        if (s1[vt] == '?') {
            if (s2[vt] == '?') {
                if (num1 == num2) {
                    num1 = num1 * 10;
                    num2 = num2 * 10;
                    duyet(vt+1);
                    num1++;
                    duyet(vt+1);
                    num1--; num2++;
                    duyet(vt+1);
                    num1 /= 10;
                    num2 /= 10;
                }
                else if (num1 < num2){
                    num1 = num1 * 10 + 9;
                    num2 = num2 * 10;
                    duyet(vt+1);
                    num1 /= 10;
                    num2 /= 10;
                }
                else {
                    num1 = num1 * 10;
                    num2 = num2 * 10 + 9;
                    duyet(vt+1);
                    num1 /= 10;
                    num2 /= 10;
                }
            }
            else {
                num2 = num2 * 10 + s2[vt] - '0';
                num1 = num1 * 10 + s2[vt] - '0';
                duyet(vt+1);
                num1 -= s2[vt] - '0';
                if (s2[vt] > '0') {
                    num1 += s2[vt] - '0' - 1;
                    duyet(vt+1);
                    num1 -= s2[vt] - '0' - 1;
                }
                if (s2[vt] < '9') {
                    num1 += s2[vt] - '0' + 1;
                    duyet(vt+1);
                    num1 -= s2[vt] - '0' + 1;
                }
                num1 /= 10;
                num2 /= 10;
            }
        }
        else if (s2[vt] == '?') {
                num1 = num1 * 10 + s1[vt] - '0';
                num2 = num2 * 10 + s1[vt] - '0';
                duyet(vt+1);
                num2 -= s1[vt] - '0';
                if (s1[vt] > '0') {
                    num2 += s1[vt] - '0' - 1;
                    duyet(vt+1);
                    num2 -= s1[vt] - '0' - 1;
                }
                if (s1[vt] < '9') {
                    num2 += s1[vt] - '0' + 1;
                    duyet(vt+1);
                    num2 -= s1[vt] - '0' + 1;
                }
                num1 /= 10;
                num2 /= 10;
        }
        else {
            num1 = num1 * 10 + s1[vt] - '0';
            num2 = num2 * 10 + s2[vt] - '0';
            duyet(vt+1);
            num1 /= 10;
            num2 /= 10;
        }
    }
}

int main() {
    int ct;
    cin >> ct;
    cout << setfill('0');
    for (int nt = 1; nt <= ct; nt++) {
        cin >> s1 >> s2;
        ans = oo;
        num1 = num2 = 0;
        duyet(0);
        cout << "Case #" << setw(0) << nt << ": " << setw(s1.size()) << so1 << ' ' << setw(s1.size()) << so2 << '\n';
    }
    return 0;
}

