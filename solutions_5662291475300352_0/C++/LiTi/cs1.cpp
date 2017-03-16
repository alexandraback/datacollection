//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define sz(x) ((int)(x).size())    
typedef long long ll;    
typedef long double ld;
typedef pair<int,int> pii; 

vector<pii> a;
bool cmp( pii a , pii b ) { 
    if( a.first == b.first ) 
	return a.second > b.second;
    return a.first < b.first;
}
int solve() { 
    a.clear();
    int n;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) { 
	int d,h,m;
	cin >> d >> h >> m;
	for( int j = 0 ; j < h ; j++ ) 
	    a.push_back( { d , m + j } ) ; 
    }
    if( a.size() == 1 ) 
	return 0;
    sort( a.begin() , a.end() , cmp ) ; 
    ld b1 = (a[0].first + 360)/ld(360) , a1 = 1 / (ld)a[0].second;
    ld b2 = (a[1].first)/ld(360) , a2 = 1 / (ld)a[1].second;
    //cerr << a1 << ' ' << b1 << endl << a2 << ' ' << b2 << endl;

    // b1 + t * a1 = b2 + t * a2 
    // t = ( b2 - b1 ) / ( a1 - a2 ) 
    ld t = ( b2 - b1 ) / (a1 - a2) ; 
   // cerr << t << endl;
    if( t < 0 ) 
	return 0;
    // b1 + t * a1 = ( 360 - a[0].first ) / 360  - b1 / ( a1 )
    ld x = ((360 - a[0].first)/ld(360))  / a1;
  //  cerr << t << ' ' << x << endl;
    if( t > x ) 
	return 0;
    return 1;
}

int main() {
    int t;
    cin >> t; 
    for( int i = 1 ; i <= t ; i++ ) 
	cout << "Case #" << i << ": " << solve() << endl;
}
