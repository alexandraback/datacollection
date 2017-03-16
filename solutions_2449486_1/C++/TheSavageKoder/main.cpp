#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int des[100][100];
bool final[100][100];
int N, M;


//down, right
int dr[] = {1,0}, dc[] = {0,1};

bool walk(int r, int c, int k, int n) {
    if(r >= N || c >= M)
        return true;

    if(des[r][c] > n)
        return false;
    else if(des[r][c] < n && !final[r][c])
        return false;

    int nr = r+dr[k], nc = c+dc[k];
    if(walk(nr,nc,k,n))
        return final[r][c] = true;

    return false;
}

int main() {
    freopen("blarge.in", "r", stdin);
    freopen("blarge.out", "w", stdout);
    int T;
    cin >> T;
    for(int cse = 1; cse <= T; cse++) {
        cin >> N >> M;
        memset(final, false, sizeof final);
        for(int i =0 ; i < N; i++)
            for(int j = 0; j < M; j++)
                cin >> des[i][j];

        for(int n = 1; n <= 1000; n++) {
            for(int r = 0; r < N; r++)
                walk(r,0,1,n);

            for(int c = 0; c < M; c++)
                walk(0,c,0,n);
        }

        int ok = true;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(!final[i][j])
                    ok = false;

        cout << "Case #" << cse << ": ";
        if(ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
