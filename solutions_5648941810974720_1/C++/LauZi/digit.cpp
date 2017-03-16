#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int MAXL = 2020;
char str[MAXL];

string jizz() {
    scanf("%s", str);

    int cnt[128] = {};
#define cnts(c) cnt[(int)(c)]

    for (int i = 0; str[i]; ++i)
        cnts(str[i]) += 1;

    vector<char> ans;

    for (int i = 0; i < cnts('Z'); ++i)
        ans.push_back('0');
    cnts('E') -= cnts('Z');
    cnts('R') -= cnts('Z');
    cnts('O') -= cnts('Z');

    for (int i = 0; i < cnts('X'); ++i)
        ans.push_back('6');
    cnts('S') -= cnts('X');
    cnts('I') -= cnts('X');

    for (int i = 0; i < cnts('G'); ++i)
        ans.push_back('8');
    cnts('E') -= cnts('G');
    cnts('I') -= cnts('G');
    cnts('H') -= cnts('G');
    cnts('T') -= cnts('G');

    for (int i = 0; i < cnts('S'); ++i)
        ans.push_back('7');
    cnts('E') -= cnts('S');
    cnts('V') -= cnts('S');
    cnts('E') -= cnts('S');
    cnts('N') -= cnts('S');

    for (int i = 0; i < cnts('V'); ++i)
        ans.push_back('5');
    cnts('F') -= cnts('V');
    cnts('I') -= cnts('V');
    cnts('E') -= cnts('V');

    for (int i = 0; i < cnts('W'); ++i)
        ans.push_back('2');
    cnts('T') -= cnts('W');
    cnts('O') -= cnts('W');

    for (int i = 0; i < cnts('F'); ++i)
        ans.push_back('4');
    cnts('O') -= cnts('F');
    cnts('U') -= cnts('F');
    cnts('R') -= cnts('F');

    for (int i = 0; i < cnts('O'); ++i)
        ans.push_back('1');
    cnts('N') -= cnts('O');
    cnts('E') -= cnts('O');

    for (int i = 0; i < cnts('I'); ++i)
        ans.push_back('9');
    for (int i = 0; i < cnts('R'); ++i)
        ans.push_back('3');

    sort(ans.begin(), ans.end());

    ans.push_back('\0');
    return string(&ans[0]);
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %s\n", t, jizz().c_str());
    }
}
