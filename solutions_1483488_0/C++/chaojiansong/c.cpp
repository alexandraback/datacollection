#include <map>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

int cnt = 0;
int T, A, B;
int g[2000001];

void gao()
{
    memset(g, -1, sizeof g);
    for (int i = 1; i <= 2000000; ++i) {
        if (g[i] == -1) {
            g[i] = cnt;
            char buf[16];
            sprintf(buf, "%d", i);
            string s(buf);
            for (int pos = 0; pos < s.length(); ++pos) {
                if (s[pos] == '0') continue;
                string ss = s.substr(pos, s.length() - pos) + s.substr(0, pos);
                int cur;
                sscanf(ss.c_str(), "%d", &cur);
                if (cur >= 2000000) continue;
                g[cur] = cnt;
            }
            ++cnt;
        }
    }
}

long long gao2()
{
    long long ans = 0;
    map<int, long long> rec;
    for (int i = A; i <= B; ++i) ++rec[g[i]];
    for (map<int, long long>::iterator p = rec.begin(); p != rec.end(); ++p) {
        ans += p->second * (p->second - 1) / 2;
    }
    return ans;
}

int main(int argc, const char *argv[])
{
    gao();
    cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        cin >> A >> B;
        cout << "Case #" << cas << ": " << gao2() << endl;   
    }
    return 0;
}
