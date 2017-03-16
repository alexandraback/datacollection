#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <deque>
using namespace std;

typedef long long LL;
typedef pair<int, int> PI;
typedef vector<int> VI;
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define FT first
#define SD second
#define Y first
#define X second

vector<string>token(string a) {
    vector<string>w; a.push_back(' ');
    while (!a.empty()){ w.push_back(a.substr(0, a.find(" "))); a = a.substr(a.find(" ") + 1, a.size() - 1); }return w;
}

map<string, int> mapik;
vector<string> amapik;
int dodaj(string a) { if (mapik.count(a) == 0) { mapik[a] = mapik.size(); amapik.PB(a); }return mapik[a]; }

map<string, int> mapik2;
vector<string> amapik2;
int dodaj2(string a) { if (mapik2.count(a) == 0) { mapik2[a] = mapik2.size(); amapik2.PB(a); }return mapik2[a]; }

const int INF = 1000000000;
const LL INFINF = 1000000000000000000LL;

char tmp_str[1000];
string scanf_string() {
    scanf("%s", tmp_str);
    return tmp_str;
}

inline bool get_bit(int w, int i) {
    return (w >> i) & 1;
}

LL wyznacz_skret(PI pkt1, PI pkt2, PI cel)
{
    // -X na lewo, 0 prosto, +X na prawo
    PI wektorA = MP(pkt2.first - pkt1.first, pkt2.second - pkt1.second);
    PI wektorB = MP(cel.first - pkt1.first, cel.second - pkt1.second);
    return (LL)wektorB.first * wektorA.second - (LL)wektorA.first * wektorB.second;
}


LL binarka(LL a, LL b, LL target, LL map(LL)) // [a,b]
{
    // [mniejsze od target][wieksze rowne target]
    // znajdz i pierwszego elementu [wieksze...]
    while (a < b)
    {
        LL c = (a + b) / 2;
        if (map(c) >= target) {
            b = c;
        }
        else {
            a = c + 1;
        }
    }
    return a;
}

LL wyznacz_skret2(PI &pkt1, PI &pkt2, PI &cel)
{
    // -X na lewo, 0 prosto, +X na prawo
    int WA1 = pkt2.first - pkt1.first;
    int WA2 = pkt2.second - pkt1.second;

    int WB1 = cel.first - pkt1.first;
    int WB2 = cel.second - pkt1.second;
    return (LL)WB1 * WA2 - (LL)WA1 * WB2;
}

// ==========================================================

const int N = 2100;
string slowa[20][2];

VI kraw[10003];int koj[10003];int akoj[10003];int byl[10003];int kol;int c, n, r;int dfs(int g) {    byl[g] = kol;    for (int i = 0; i < kraw[g].size(); i++) {        int t = kraw[g][i];        if (akoj[t] == -1) {            koj[g] = t; akoj[t] = g; return 1;        }        else if (byl[akoj[t]] != kol&&dfs(akoj[t]) == 1) {            koj[g] = t;            akoj[t] = g;            return 1;        }    }    return 0;}int maksmatch() {    int p = 0;    r = mapik.size();    for (int i = 0; i < max(r, (int)mapik2.size()); i++) koj[i] = akoj[i] = -1;    for (int i = 0; i < r; i++) for (int k = 0; k < kraw[i].size(); k++) {        int sas = kraw[i][k];        if (koj[i] == -1 && akoj[sas] == -1) { koj[i] = sas; akoj[sas] = i; p++; }    }    for (int i = 0; i < r; i++) if (koj[i] == -1) {        kol++;        if (dfs(i)) {            p++;        }    }    return p;}void czysc() {    mapik.clear(); mapik2.clear();    for (int i = 0; i < 10001; i++) kraw[i].clear();}

int main() {
    int daa; scanf("%d", &daa);
    for (int ind = 1; ind <= daa; ind++) {
        scanf("%d", &n);
        czysc();
        for (int i = 0; i < n; i++)
        {
            string aa = scanf_string();
            string bb = scanf_string();
            int a = dodaj(aa);
            int b = dodaj2(bb);
            kraw[a].push_back(b);
        }


        printf("Case #%d: %d\n", ind, n - (mapik.size() + mapik2.size() - maksmatch()));
    }
    return 0;
}
