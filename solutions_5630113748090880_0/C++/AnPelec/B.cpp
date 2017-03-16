#include <bits/stdc++.h>

#define cin fin
#define cout fout

#define MAXR 2510

using namespace std;

int T, N;
int yo;
int cnt[MAXR];

ifstream fin("B-small-attempt0.in");
ofstream fout("B-small-attempt0.out");

int main()
{
    cin >> T;

    for (int t=1; t<=T; t++) {
        for (int i=0; i<MAXR; i++) cnt[i] = 0;
        cin >> N;
        for (int i=0; i<2*N-1; i++) {
            for (int j=0; j<N; j++) {
                cin >> yo;
                cnt[yo] ++;
            }
        }

        cout << "Case #" << t << ":";

        for (int i=0; i<MAXR; i++)
            if (cnt[i]%2 != 0) cout << " " << i;
        cout << endl;
    }

    return 0;
}
