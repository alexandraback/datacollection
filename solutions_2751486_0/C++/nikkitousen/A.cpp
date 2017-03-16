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
#include <fstream>
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


string L;
int n;

bool vow(char c) {
    return c == 'a' or c=='e' or c=='i' or c=='o' or c=='u';
}

int main()
{
    int T;
    cin >> T;
    vector<int> ends;
    
    
    REP(caso, T) {
        cin >> L >> n;
        ends.clear();
        
        int count=0;
        REP(i, SZ(L)) {
            if(!vow(L[i])) {
                count++;
                if(count >= n) ends.PB(i);
            } else {
                count = 0;
            }
        }
        
        long long res = 0;
        REP(i, SZ(ends)) {
            //cout << ends[i] << endl;
            int lst = SZ(L)-1;
            if(i+1 < SZ(ends)) {
                lst = ends[i+1]-1;
            }
            //cout << lst << endl;
            res += (ends[i]-n+2)*(lst-ends[i]+1);
        }
        
        cout << "Case #" << caso+1 << ": " << res << endl;
    }
    
}
