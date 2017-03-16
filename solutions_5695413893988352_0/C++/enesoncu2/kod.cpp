



#include <iostream>
#include <algorithm>
#include <cassert>

/*
 0 Z
 6 X 
 8 G 
 2 W
 1 O 
 3 H 
 4 R
 5 F
 7 S
 9 N
*/

 #define FP( ii,aa,bb )	for( int ii=aa;ii<=bb;ii++ )
 #define FM( ii,aa,bb )	for( int ii=aa;ii>=bb;ii-- )

 using namespace std;

 int main(){
 	int t,id=0;
 	cin >> t;
 	while( t-- ){
 		string s,p;
 		int r1=-1,r2=-1;
 		int k;
 		cin >> s >> p;
 		k = s.size();
 		while( s.size()!=3 )	s = "0"+s , p = "0"+p;
 		FP( a,'0','9' ) if( s[0]=='?' or s[0]==a )
 		FP( b,'0','9' ) if( s[1]=='?' or s[1]==b )
 		FP( c,'0','9' )	if( s[2]=='?' or s[2]==c )
 		FP( d,'0','9' )	if( p[0]=='?' or p[0]==d )
 		FP( e,'0','9' )	if( p[1]=='?' or p[1]==e )
 		FP( f,'0','9' )	if( p[2]=='?' or p[2]==f ){
 			int x = (a-'0')*100+(b-'0')*10+(c-'0');
 			int y = (d-'0')*100+(e-'0')*10+(f-'0');
 			if( r1==-1 ){
 				r1 = x;
 				r2 = y;
 				continue;
 			}
 			if( abs(y-x)<abs(r1-r2) or abs(y-x)==abs(r1-r2) and y+x<r1+r2 or abs(y-x)==abs(r1-r2) and y+x==r1+r2 and y<r2 ){
 				r1 = x;
 				r2 = y;
 			}
 		}
 		++id;
 		cout << "Case #" << id << ": ";


 		int arr[10];
 		arr[1] = r1%10;
 		arr[2] = r1/10%10;
 		arr[3] = r1/100%10;
 		FM( i,k,1 )	cout << arr[i]; cout << " ";
 		arr[1] = r2%10;
 		arr[2] = r2/10%10;
 		arr[3] = r2/100%10;
 		FM( i,k,1 )	cout << arr[i];
 		cout << endl;
 	}
 }

