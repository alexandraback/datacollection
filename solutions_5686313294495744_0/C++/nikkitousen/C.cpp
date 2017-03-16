#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

int N;
map<string, int> wid;
set<int> fws, sws;
int widlen;
int fw[20], sw[20];

int main()
{
    int T;
    cin >> T;
    REP(caso, T) {
        cin >> N;
        wid.clear();
        widlen=0;
        REP(i, N) {
            string a, b;
            cin >> a >> b;
            if(wid.find(a) == wid.end()) {
                wid[a] = widlen++;
            }
            if(wid.find(b) == wid.end()) {
                wid[b] = widlen++;
            }
            fw[i] = wid[a];
            sw[i] = wid[b];
        }

        int ret = 0;
        REP(mask, (1<<N)) {
            fws.clear();
            sws.clear();
            REP(i, N) {
                if(mask&(1<<i)) {
                    fws.insert(fw[i]);
                    sws.insert(sw[i]);
                }
            }
            bool ok=true;
            int fcount=0;
            REP(i, N) {
                if(!(mask&(1<<i))) {
                    fcount++;
                    if(fws.find(fw[i]) == fws.end() || sws.find(sw[i]) == sws.end()) {
                        ok = false;
                        break;
                    }
                }
            }

            if(ok && fcount > ret) ret = fcount;

        }

        cout << "Case #" << caso+1 << ": " << ret << endl;

    }
}
