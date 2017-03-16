#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

typedef long double LD;

const int MAXN = 1023;

int n;
LD naomi[MAXN], ken[MAXN];

int war(){
    set < LD > naomi_availible ( naomi, naomi+n );
    set < LD > ken_availible ( ken, ken+n );

    int score = 0;
    while ( !naomi_availible.empty() ){
        while ( !naomi_availible.empty() && *naomi_availible.rbegin() > *ken_availible.rbegin() ){
            ++score;
            naomi_availible.erase ( *naomi_availible.rbegin() );
            ken_availible.erase ( ken_availible.begin() );
        }

        while ( !naomi_availible.empty() && *naomi_availible.rbegin() < *ken_availible.rbegin() ){
            ken_availible.erase ( ken_availible.upper_bound ( *naomi_availible.begin() ) );
            naomi_availible.erase ( naomi_availible.begin() );
        }
    }

    return score;
}

int deceitful_war(){
    set < LD > naomi_availible ( naomi, naomi+n );
    set < LD > ken_availible ( ken, ken+n );

    while ( !naomi_availible.empty() ){
		set < LD > :: iterator naomi_it = naomi_availible.begin();
		set < LD > :: iterator ken_it = ken_availible.begin();

		while ( naomi_it != naomi_availible.end() && *naomi_it > *ken_it ) {
			++naomi_it;
			++ken_it;
		}

		if ( naomi_it == naomi_availible.end() ) {
			break;
		}

		naomi_availible.erase ( naomi_availible.begin() );
		ken_availible.erase ( *ken_availible.rbegin() );
    }

    return naomi_availible.size();
}

int main(){
	
	freopen ( "D-large.in", "r", stdin );
	freopen ( "D-large.out", "w", stdout );

    int t;
    cin >> t;
    for ( int testcase = 1; testcase <= t; ++testcase ){
        cin >> n;
        for ( int i = 0; i < n; ++i ){
            cin >> naomi[i];
        }
        for ( int i = 0; i < n; ++i ){
            cin >> ken[i];
        }

        cout << "Case #" << testcase << ": " <<
        deceitful_war() << " " <<
        war() << endl;
    }

    return 0;
}
