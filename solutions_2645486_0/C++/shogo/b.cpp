#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int E, R, N;
int v[20];
int e[20][20];

int main()
{
    int T;
    cin >> T;
    for(int no = 1; no <= T; ++no) {
        cin >> E >> R >> N;
        for(int i=0; i<N; ++i) cin >> v[i];

        for(int i=0; i<=N; ++i)
            for(int j=0;j<=E;++j)
                e[i][j] = 0;

        for(int i=0; i<N; ++i) {
            int vv = v[i];
            for(int j=0; j<=E; ++j) {
                for(int k=0; k<=j; ++k) {
                    int kk = j-k;
                    if(kk<0) continue;
                    kk += R;
                    if(kk>E) kk=E;
                    e[i+1][kk] = max(e[i+1][kk], e[i][j] + vv * k);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<=E; ++i) {
            ans = max(ans, e[N][i]);
        }
        cout << "Case #" << no << ": " << ans << endl;
    }
}
