#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int T, N, M;
int lawn[110][110];
int lawned[110][110];

void lawn_it(int level) {
    for(int i = 0; i < N; i++) {
        bool ok = true;
        for(int j = 0; j < M; j++)
            if(lawn[i][j] > level || level > lawned[i][j]) {
                ok = false;
                break;
            }
        if(ok)
            for(int j = 0; j < M; j++)
                lawned[i][j] = level;
    }
    for(int j = 0; j < M; j++) {
        bool ok = true;
        for(int i = 0; i < N; i++)
            if(lawn[i][j] > level || level > lawned[i][j]) {
                ok = false;
                break;
            }
        if(ok)
            for(int i = 0; i < N; i++)
                lawned[i][j] = level;
    }
}

bool all_done() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(lawn[i][j] != lawned[i][j]) return false;
    return true;
}

int main() {
    cin >> T;
    for(int Ti = 1; Ti <= T; Ti++) {
        cin >> N >> M;
        for(int Ni = 0; Ni < N; Ni++) {
            for(int Mi = 0; Mi < M; Mi++) {
                cin >> lawn[Ni][Mi];
                lawned[Ni][Mi] = 100;
            }
        }

        for(int i = 100; i > 0; i--)
            lawn_it(i);

        cout << "Case #" << Ti << ": ";
        if(all_done()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}