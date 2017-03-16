#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int War( list<double> naomi, list<double> ken )
{
    int win = 0;
    for ( auto n : naomi ) {
        auto it = upper_bound( ken.begin(), ken.end(), n );
        if ( it == ken.end() ) {
            win++;
            ken.erase( ken.begin() );
        } else {
            ken.erase( it );
        }
    }
    return win;
}

int DWar( list<double> naomi, list<double> ken )
{
    int win = 0;
    while ( !naomi.empty() ) {
        if ( naomi.back() < ken.back() || naomi.front() < ken.front() ) {
            ken.pop_back();
            naomi.pop_front();
        } else {
            ken.pop_front();
            naomi.pop_front();
            win++;
        }
    }
    return win;
}

int main()
{
    int T;
    cin >> T;
    for ( int t = 1; t <= T; t++ ) {
        int N;
        cin >> N;
        list<double> naomi, ken;
        for ( int i = 0; i < N; i++ ) {
            naomi.push_back(0.0);
            cin >> naomi.back();
        }
        for ( int i = 0; i < N; i++ ) {
            ken.push_back(0.0);
            cin >> ken.back();
        }
        naomi.sort();
        ken.sort();
        printf( "Case #%d: %d %d\n", t, DWar(naomi,ken), War(naomi,ken) );
    }
    return 0;
}
