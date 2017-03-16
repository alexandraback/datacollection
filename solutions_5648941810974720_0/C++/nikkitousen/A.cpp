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

int ccont[256];


int main()
{
    int T;
    cin >> T;
    REP(caso, T) {
        string S;
        cin >> S;
        CLEAR(ccont);
        REP(i, SZ(S)) ccont[S[i]]++;

        vector<int> num;

        // Zero
        while(ccont['Z']) {
            ccont['Z']--;
            ccont['E']--;
            ccont['R']--;
            ccont['O']--;
            num.PB(0);
        }

        // Two
        while(ccont['W']) {
            ccont['T']--;
            ccont['W']--;
            ccont['O']--;
            num.PB(2);
        }

        // Six
        while(ccont['X']) {
            ccont['S']--;
            ccont['I']--;
            ccont['X']--;
            num.PB(6);
        }

        // Eight
        while(ccont['G']) {
            ccont['E']--;
            ccont['I']--;
            ccont['G']--;
            ccont['H']--;
            ccont['T']--;
            num.PB(8);
        }

        // Three
        while(ccont['H']) {
            ccont['T']--;
            ccont['H']--;
            ccont['R']--;
            ccont['E']--;
            ccont['E']--;
            num.PB(3);
        }

        // Four
        while(ccont['R']) {
            ccont['F']--;
            ccont['O']--;
            ccont['U']--;
            ccont['R']--;
            num.PB(4);
        }

        // Five
        while(ccont['F']) {
            ccont['F']--;
            ccont['I']--;
            ccont['V']--;
            ccont['E']--;
            num.PB(5);
        }

        // Seven
        while(ccont['V']) {
            ccont['S']--;
            ccont['E']--;
            ccont['V']--;
            ccont['E']--;
            ccont['N']--;
            num.PB(7);
        }

        // One
        while(ccont['O']) {
            ccont['O']--;
            ccont['N']--;
            ccont['E']--;
            num.PB(1);
        }

        // Nine
        while(ccont['N']) {
            ccont['N']--;
            ccont['I']--;
            ccont['N']--;
            ccont['E']--;
            num.PB(9);
        }

        SORT(num);

        cout << "Case #" << caso+1 << ": ";
        REP(i, SZ(num)) cout << num[i];
        cout << endl;


    }
}