#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for ( int t = 0; t < T; t++ ) {
        int N;
        cin >> N;
        multiset<pair<int,int> > s1, s2;
        multiset<int> ss;
        for ( int i = 0; i < N; i++ ) {
            int a, b;
            cin >> a >> b;
            s2.insert( make_pair(b,a) );
        }

        int c = 0, cnt = 0;
        while ( !s2.empty() || !ss.empty() ) {
            if ( !s2.empty() && s2.begin()->first <= c ) {
                c += 2;
                s2.erase( s2.begin() );
                cnt++;
                continue;
            }

            if ( !ss.empty() && *ss.begin() <= c ) {
                c += 1;//ss.count( *ss.begin() );
                ss.erase( ss.begin() );
                cnt++;
                continue;
            }

            bool ok = false;
            if ( !s2.empty() ) {
            multiset<pair<int,int> >::iterator itr = s2.end();
            for ( --itr; ; --itr ) {
                if ( itr->second <= c ) {
                    c += 1;//s2.count( *itr );
                    ss.insert( itr->first );
                    s2.erase( itr );
                    cnt++;
                    ok = true;
                    break;
                }
                if ( itr == s2.begin() ) break;
            }
            }
            if ( !ok ) {
                cnt = -1;
                break;
            }
        }

        if ( cnt < 0 ) {
            printf( "Case #%d: Too Bad\n", t+1 );
        } else {
            printf( "Case #%d: %d\n", t+1, cnt );
        }
    }
    return 0;
}
