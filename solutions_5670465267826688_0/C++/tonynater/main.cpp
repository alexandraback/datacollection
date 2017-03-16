//tonynater

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int MAXL = 40000;

const int QV[4][4] = {
    {0,1,2,3},
    {1,0,3,2},
    {2,3,0,1},
    {3,2,1,0} };

const int QS[4][4] = {
    {0,0,0,0},
    {0,1,0,1},
    {0,1,1,0},
    {0,0,1,1} };

ll L, X;

string S;

int main() {
    freopen("/Users/tonynater/Downloads/C-small-attempt0.in", "r", stdin);
    freopen("/Users/tonynater/Tony/Computer/Xcode_repos/Miscellaneous/GCJ_2015/QC/qc_small.out", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cout << "Case #" << t+1 << ": ";
        
        cin >> L >> X >> S;
        
        int cur = 0, sn = 0;
        for(int i = 0; i < L; i++) {
            int v = S[i]-'h';
            sn += QS[cur][v];
            cur = QV[cur][v];
        }
        int tmp = cur;
        sn *= X%4;
        for(int i = 0; i < X%4-1; i++) {
            sn += QS[cur][tmp];
            cur = QV[cur][tmp];
        }
        
        if(!(cur == 0 && sn%2 == 1)) {
            cout << "NO\n";
            continue;
        }
        
        int front = 0;
        cur = 0, sn = 0;
        while(front < MAXL) {
            int v = S[front%L]-'h';
            sn += QS[cur][v];
            cur = QV[cur][v];
            ++front;
            if(cur == 1 && sn%2 == 0) {
                break;
            }
        }
        
        int back = 0;
        cur = 0, sn = 0;
        while(back < MAXL) {
            int v = S[L-back%L-1]-'h';
            sn += QS[v][cur];
            cur = QV[v][cur];
            ++back;
            if(cur == 3 && sn%2 == 0) {
                break;
            }
        }
        
        if(front == MAXL || back == MAXL || front+back > X*L) {
            cout << "NO\n";
        }else {
            cout << "YES\n";
        }
    }
    
    return 0;
}