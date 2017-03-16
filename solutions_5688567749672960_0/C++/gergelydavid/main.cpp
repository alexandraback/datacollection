#include <bits/stdc++.h>
//#include <boost/lexical_cast.hpp>
#include <iostream>

 using namespace std ;
const int NMAX = 1000005 ;
const int INF = 0x3f3f3f3f ;

int D[NMAX];

 void solve() ;


inline void solve() {


	memset(D, 0x3f, sizeof D);

	D[1] = 1;

	for(int i = 1; i < (NMAX - 5); ++ i) {
		string siz = to_string(i) ;
		reverse(siz.begin(), siz.end());
		int rep = stoi(siz);
		D[ i + 1 ] = min(D[ i + 1], D[ i ] + 1);
		D[rep] = min(D[rep], D[i] + 1);
	}
}

 int N, T;

int main() {
	solve() ;

	cin >> T ;

    for(int cs = 1 ; cs <= T ; ++ cs)
    {
        cin >> N ;
    cout << "Case #" << cs << ": " << D[N] << '\n';

    }



    return 0 ;
}
