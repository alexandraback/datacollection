#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c=0; c<T; c++) {
        int N,M;
        cin >> N >> M;
        vector < vector<int> > h;
        for (int i=0; i<N; i++) {
            vector<int> r;
            for (int j=0; j<M; j++) {
                int a;
                cin >> a;
                r.push_back(a);
            }
            h.push_back(r);
        }

        bool ok = true;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                bool okr=true,okc=true;
                for (int k=0; k<M; k++) {
                    if (h[i][j]<h[i][k]) okr = false;
                }
                for (int k=0; k<N; k++) {
                    if (h[i][j]<h[k][j]) okc = false;
                }
                if (okr==false && okc==false) {
                    //cout << i << " " << j << endl;
                    ok = false;
                }
            }
        }
        cout << "Case #"<< c+1<<": ";
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

