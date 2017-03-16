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

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back

int main()
{
    int T, N;
    cin >> T;
    double a[1001], b[1001];
    int mark[1001];
    
    REP(caso, T) {
        cin >> N;
        REP(i, N) cin >> a[i];
        REP(i, N) cin >> b[i];
        sort(a, a+N);
        sort(b, b+N);
        
        // REP(i, N) cout << a[i] << "\t";
        // cout << endl;
        // REP(i, N) cout << b[i] << "\t";
        // cout << endl;
        
        int score1=0;
        CLEAR(mark);
        REP(i, N) {
            bool found=false;
            REP(j, N) {
                if(!mark[j] and b[j] > a[i]) {
                    found = true;
                    mark[j] = 1;
                    break;
                }
            }
            if(!found) {
                score1 = N-i;
                break;
            }
        }
        
        int score2=0;
        CLEAR(mark);
        REP(i, N) {
            bool found=false;
            REP(j, N) {
                if(!mark[j] and a[j]>b[i]) {
                    found = true;
                    mark[j] = 1;
                    break;
                }
            }
            if(!found) break;
            score2++;
        }
        
        
        cout << "Case #" << caso+1 << ": " << score2 << " " << score1 << endl;
        
        
        
    }
}
