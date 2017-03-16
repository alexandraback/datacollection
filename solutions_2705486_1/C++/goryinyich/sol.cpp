#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

vector<string> dict;
vector<int> len;

void readDict () {
    char buf[100];
    FILE* df = fopen ("garbled_email_dictionary.txt", "r");
    while (fscanf (df, "%s", buf) != EOF) {
        dict.push_back(string(buf));
        len.push_back(string(buf).size());
        //if (dict.size() > 10000) return;
    }
}

int d[5000][5];

bool canBeWord (int wn, string& t, int pos, int& before, int& after, int& changes) {
    if (len[wn] > pos+1) return false;
    int lastCh = -100;
    before = after = -1;
    changes = 0;
    REP(i,len[wn]) {
        if (t[pos-len[wn]+1+i] != dict[wn][i]) {
            if (i - lastCh < 5) return false;
            ++changes;
            if (lastCh == -100) {
                before = i;
            }
            after = len[wn] - i - 1;
            lastCh = i;
        }
    }
    if (lastCh == -100) {
        before = after = len[wn];
    }
    before = min<int>(before, 4);
    after = min<int>(after, 4);
    return true;
}

int ans (string &t) {
    REP(i,t.size()+1) REP(j,5) d[i][j] = INF;
    REP(j,5) d[0][j] = 0;
    for (int i = 1; i <= t.size(); ++i) {
        int before, after, changes;
        for (int dw = 0; dw < dict.size(); ++dw) {
            if (canBeWord (dw, t, i-1, before, after, changes)) {
                REP(j,5) if (before + j >= 4) {
                    d[i][after] = min<int>(d[i][after], d[i-len[dw]][j] + changes);
                }
                if (changes == 0) {
                    REP(j,5) d[i][min<int>(j+before,4)] = min<int>(d[i][min<int>(j+before,4)], d[i-len[dw]][j]);
                }
            }
        }
    }
    int ans = INF;
    REP(i,5) ans = min<int>(ans, d[t.size()][i]);
    return ans;
}

int main(){
    readDict();
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    REP(ic,tc) {
        string t;
        cin >> t;
        cout << "Case #" << ic+1 << ": " << ans (t) << endl;
    }

	return 0;
};