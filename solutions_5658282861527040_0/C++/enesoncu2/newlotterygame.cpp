#include<bits/stdc++.h>

#define lli long long int
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define all(gg)	gg.begin(),gg.end()
#define foreach( gg,it )	for( typeof(gg.begin())	it=gg.begin();it!=gg.end();it++ )
#define FP( ii,aa,bb )	for( int ii=aa;ii<=bb;ii++ )
#define FM( ii,aa,bb )	for( int ii=aa;ii>=bb;ii-- )

using namespace std;

lli a,b,k;

int main(){
	int t;
	cin >> t;
	int r;
	FP( CASE,1,t ){
		r = 0;
		cin >> a >> b >> k;
		FP( i,0,a-1 )
			FP( j,0,b-1 )
				if( (i&j)<k )	r++;
		cout << "Case #" << CASE << ": " << r << endl;
	}
}
