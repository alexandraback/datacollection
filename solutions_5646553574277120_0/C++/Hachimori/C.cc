#include<iostream>
#include<algorithm>
using namespace std;
const int VAL = 10;
const int BUF = 105;

int nUse, nVal, upto;
int val[VAL];

void read() {
    cin >> nUse >> nVal >> upto;
    for (int i = 0; i < nVal; ++i)
        cin >> val[i];
}


void work(int cases) {
    bool avail[BUF] = {};
    
    avail[0] = true;
    for (int i = 0; i < nVal; ++i)
        for (int j = BUF - 1; j >= 0; --j)
            if (avail[j] && j + val[i] < BUF)
                avail[j + val[i]] = true;

    int cnt = 0;
    for (int i = 0; i <= upto; ++i) {
        if (avail[i])
            continue;
        
        ++cnt;
        
        int toUse = i;
        
        val[nVal++] = toUse;
        for (int j = BUF - 1; j >= 0; --j)
            if (avail[j] && j + toUse < BUF)
                avail[j + toUse] = true;
    }
    
    cout << "Case #" << cases << ": " << cnt << endl;
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
