#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, T, E;
string S1[10];
int adjm[10][10];
bool used[10][10];
stack<int> S;
vector<int> V;
string ans;

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for ( int tc = 1; tc <= T; tc++ ) {
        ans = "99999999999999999999999999999999999999999999999999999999999999999999999";
        V.clear();
        scanf("%d%d", &N, &E);
        for ( int i = 0; i < N; i++ ) cin >> S1[i];
        for ( int i = 0; i < N; i++ ) V.push_back(i);
        while ( !S.empty() ) S.pop();
        memset(adjm, 0, sizeof(adjm));
        for ( int i = 0; i < E; i++ ) {
            int A, B;
            scanf("%d%d", &A, &B);
            adjm[A-1][B-1] = 1;
            adjm[B-1][A-1] = 1;
        }
        do {
            while ( !S.empty() ) S.pop();
            memset(used, 0, sizeof(used));
            string temp;
            S.push(V[0]);
            for ( int i = 1; i < N; i++ ) {
                if ( S.size() == 0 ) goto cannot;
                while ( adjm[S.top()][V[i]] == 0 && !used[S.top()][V[i]] ) {
                    S.pop();
                    if ( S.size() == 0 ) goto cannot;
                }
                if ( S.size() == 0 ) goto cannot;
                if ( adjm[S.top()][V[i]] > 0 ) {
                    S.push(V[i]);
                    used[S.top()][V[i]] = 1;
                }
            }
            temp = "";
            for ( int i = 0; i < N; i++ ) temp += S1[V[i]];
            if ( temp < ans ) ans = temp;
            cannot:
                0+0;
        } while ( next_permutation(V.begin(), V.end()) );
        printf("Case #%d: %s\n", tc, ans.c_str());
    }
}
