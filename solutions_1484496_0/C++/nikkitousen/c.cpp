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
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define X first
#define Y second

int aabs(int a) { return (a<0)?-a:a; }
int n;
int a[22];
int sum[2100100];

int main()
{
    int T;
    cin >> T;
    
    REP(caso, T) {
        cin >> n;
        REP(i, n) cin >> a[i];
        memset(sum, 0, sizeof(sum));
        int found=0;
        cout << "Case #" << caso+1 << ":\n";
        FOR(msk, 1, (1<<n)) {
            if(found) break;
            int s = 0;
            REP(i, n) if(msk&(1<<i)) s+= a[i];
            if(sum[s] == 0) sum[s] = msk;
            else {
                found = 1;
                REP(i, n) {
                    if(msk&(1<<i)) cout << a[i] << " ";
                }
                cout << endl;
                REP(i, n) {
                    if(sum[s]&(1<<i)) cout << a[i] << " ";
                }
                cout << endl;
            }
        }
        if(!found) cout << "Impossible\n";
    }
}
