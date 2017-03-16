#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int N;
        cin >> N;
        int M = 2 * N - 1;
        int grid[M][N];
        vector<int> cnt(3000);
        for ( int i=0 ; i<M ; ++i ) {
            for ( int j=0 ; j<N ; ++j ) {
                cin >> grid[i][j];
                cnt[grid[i][j]]++;
            }
        }
        vector<int> res;
        for ( int i=1 ; i<=2500 ; ++i ) {
            if ( cnt[i] % 2 == 1 ) {
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());
        cout << "Case #" << tc << ":";
        for ( int i=0 ; i<res.size() ; ++i ) {
            cout << " " << res[i];
        }
        cout << endl;
    }
    return 0;
}