#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cmath>
using namespace std;

bool check(const vector< pair<string,string> >& topics, const vector<bool>& fake) {
    const int N = (int)topics.size();
    set<string> sheets;
    set<string> first, second;
    for ( int i=0 ; i<N ; ++i ) {
        const string& s1 = topics[i].first;
        const string& s2 = topics[i].second;
        if ( fake[i] ) {
            if ( sheets.find(s1) == sheets.end() || sheets.find(s2) == sheets.end() ) return false;
            if ( second.find(s2) == second.end() && first.find(s2) != first.end() ) return false;
            if ( first.find(s1) == first.end() && second.find(s1) != second.end() ) return false;
        }
        else {
            //if ( sheets.find(s1) != sheets.end() || sheets.find(s2) != sheets.end() ) return false;
            sheets.insert(s1);
            sheets.insert(s2);
        }
        first.insert(s1);
        second.insert(s2);
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        cout << "Case #" << tc << ": ";
        int N;
        cin >> N;
        vector< pair<string,string> > topics(N);
        for ( int i=0 ; i<N ; ++i ) {
            cin >> topics[i].first >> topics[i].second;
        }

        int res = 0;
        for ( int m=0 ; m<(1<<N) ; ++m ) {
            vector<bool> fake(N);
            for ( int i=0 ; i<N ; ++i ) {
                if ( m & (1<<i ) ) {
                    fake[i] = true;
                }
            }
            if ( check(topics, fake) ) {
                res = max(res, __builtin_popcount(m));
            }
        }
        cout << res << endl;
    }
    return 0;
}
