#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int BUF = 10;

int nRepeat;
string keys;
string target;

void read() {
    int K, L;
    cin >> K >> L >> nRepeat;
    cin >> keys;
    cin >> target;
}


void rec(int nPut, char curStr[BUF], double &sum, int &maxCnt) {
    if (nPut == nRepeat) {
        int cnt = 0;
        for (int i = 0; i + target.size() <= nRepeat; ++i) {
            for (int j = 0; j < target.size(); ++j)
                if (curStr[i + j] != target[j])
                    goto _fail;
            ++cnt;
        _fail:;
        }
        
        maxCnt = max(maxCnt, cnt);
        sum += cnt / pow(keys.size(), nRepeat);

        return;
    }
    
    for (int i = 0; i < keys.size(); ++i) {
        curStr[nPut] = keys[i];
        rec(nPut + 1, curStr, sum, maxCnt);
    }
}


void work(int cases) {
    char curStr[BUF];
    double sum = 0;
    int maxCnt = 0;
    
    rec(0, curStr, sum, maxCnt);

    printf("Case #%d: %.10lf\n", cases, maxCnt - sum);
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
