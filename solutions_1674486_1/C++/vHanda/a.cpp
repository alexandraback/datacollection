#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for( int cas=0; cas<cases; cas++ ) {
        cout << "Case #" << cas+1 << ": ";

        int n;
        cin >> n;

        vector<vector<int>> ed( n );
        for( int j=0; j<n; j++ ) {
            int m;
            cin >> m;

            ed[j].resize( m );
            for( int i=0; i<m; i++ ) {
                int k;
                cin >> k;
                ed[j][i] = k-1;
            }
        }
        
        bool found = false;

        for( int i=0; i<n; i++ ) {

            vector<int> state( n, 0 );
            queue<int> q;
            found = false;

            for( int j=0; j<ed[i].size(); j++) {
                int vec = ed[i][j];
                q.push( vec );
                state[vec] = j+10;
            }

            while( !q.empty() ) {
                int vec = q.front();
                q.pop();

                for( int j=0; j<ed[vec].size(); j++) {
                    int v = ed[vec][j];

                    if( state[v] ) {
                        found = true;
                        goto end;
                    }
                        
                    q.push( v );
                    state[v] = state[vec];
                }
            }
        }

        end:
        if( found )
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }


    return 0;
}


