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
#define MP make_pair
#define PB push_back
#define VI vector<int>
#define VS vector<string>
#define PII pair<int, int>
#define X first
#define Y second

int aabs(int a) { return (a<0)?-a:a; }
int mmax(int a, int b) { return (a>b)?a:b; }
int mmin(int a, int b) { return (a<b)?a:b; }

int A, N;
int sizes[110];


int main()
{
    int T;
    cin >> T;
    REP(caso, T) {
        cin >> A >> N;
        REP(i, N) cin >> sizes[i];
        sort(sizes, sizes+N);
        
        set< pair<int, pair< int, int > > > q;
        q.insert(MP(0, MP(A, 0)));
        int res = -1;
        while(!q.empty()) {
            pair< int, pair<int, int> > p;
            p = *(q.begin());
            q.erase(q.begin());
            
            if(p.Y.Y == N) {
                res = p.X;
                break;
            }
            
            if(p.Y.X > sizes[p.Y.Y]) {
                q.insert(MP(p.X, MP(p.Y.X + sizes[p.Y.Y], p.Y.Y+1)));
            } else {
                q.insert(MP(p.X+1, MP(p.Y.X + (p.Y.X - 1) , p.Y.Y)));
                q.insert(MP(p.X+1, MP(p.Y.X, p.Y.Y + 1)));
            }
            
        }
        
        cout << "Case #" << caso+1 << ": " << res << endl;
        
    }
}
