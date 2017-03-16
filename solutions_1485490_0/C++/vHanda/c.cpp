#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

int lcs(vi bc, const vi& bt, vi tc, const vi& tt, int i, int j) {
    if( i == bt.size() || j == tt.size() )
        return 0;

    if( bt[i] == tt[j] ) {
        int amt = min(bc[i], tc[j]);
        bc[i] -= amt;
        tc[j] -= amt;

        if(!bc[i]) i++;
        if(!tc[j]) j++;

        return amt + lcs(bc, bt, tc, tt, i, j);
    }
    else {
        int value = max( lcs(bc, bt, tc, tt, i+1, j),
                         lcs(bc, bt, tc, tt, i, j+1) );
        return value;
    }
}

int main() {
    int T;
    cin >> T;
    for( int t=0; t<T; t++ ) {
        cout << "Case #" << t+1 << ": ";

        int nboxes, ntoys;
        cin >> nboxes >> ntoys;

        vector<int> bc( nboxes+1 );
        vector<int> bt( nboxes+1 );
        for(int i=1; i<=nboxes; i++)
            cin >> bc[i] >> bt[i];

        vector<int> tc( ntoys+1 );
        vector<int> tt( ntoys+1 );
        for(int i=1; i<=ntoys; i++)
            cin >> tc[i] >> tt[i];

        int res = lcs(bc, bt, tc, tt, 0, 0);
        cout << res << endl;
    }

    return 0;
}
