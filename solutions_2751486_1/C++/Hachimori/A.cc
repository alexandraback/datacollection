#include <iostream>
#include <string>
using namespace std;


string txt;
int K;

void read() {
    cin >> txt >> K;
}


bool isCons(char ch) {
    string vo = "aiueo";
    return vo.find(ch) == string::npos;
}

void work(int cases) {
    long long cnt = 0;
    int lastBgn = -1;

    for (int idx = 0; idx < txt.size(); ) {
        int startIdx = idx, cntCons = 0;
        while (idx < txt.size() && isCons(txt[idx])) {
            idx++;
            cntCons++;
        }
        
        if (cntCons >= K) {
            int nBgn, nEnd;
            nBgn = startIdx - lastBgn - 1;
            nEnd = txt.size() - (startIdx + K - 1);
            cnt += 1LL * nBgn * nEnd; // bgn on the left

            nBgn = cntCons - K + 1;
            nEnd = txt.size() - idx;
            cnt += 1LL * nBgn * nEnd; // end on the right

            cnt += 1LL * (cntCons - K + 2) * (cntCons - K + 1) / 2; // inside

            lastBgn = idx - K;
        }

        idx++;
    }

    cout << "Case #" << cases << ": " << cnt << endl;
}


int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        read();
        work(i + 1);
    }
    return 0;
}
