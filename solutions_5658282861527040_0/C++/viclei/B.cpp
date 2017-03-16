#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main() {

    int tcN;
    cin >> tcN;

    for( int tc = 1; tc <= tcN; tc++ ) {
        long long A, B, K;
        long long ans = 0;
        cin >> A >> B >> K;
        for( int i=0; i<A; i++ ) {
            for( int j=0; j<B; j++ ) {
                if( (i&j) < K ) ans++;
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
