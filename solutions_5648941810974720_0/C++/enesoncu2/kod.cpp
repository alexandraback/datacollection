



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

 using namespace std;

 int main(){
 	int t;
 	cin >> t;
 	int id=0;
 	while( t-- ){
 		int s[200],res[20];
 		memset( s,0,sizeof s );
 		memset( res,0,sizeof res );
 		string str;
 		cin >> str;
 		for( int i=0;i<str.size();i++ )
 			s[str[i]]++;
 		res[0] = s['Z'];
 		s['Z'] -= res[0];
 		s['E'] -= res[0];
 		s['R'] -= res[0];
 		s['O'] -= res[0];
 		res[6] = s['X'];
 		s['S'] -= res[6];
 		s['I'] -= res[6];
 		s['X'] -= res[6];
 		res[8] = s['G'];
 		s['E'] -= res[8];
 		s['I'] -= res[8];
 		s['G'] -= res[8];
 		s['H'] -= res[8];
 		s['T'] -= res[8];
 		res[2] = s['W'];
 		s['T'] -= res[2];
 		s['W'] -= res[2];
 		s['O'] -= res[2];
 		res[3] = s['H'];
 		s['T'] -= res[3];
 		s['H'] -= res[3];
 		s['R'] -= res[3];
 		s['E'] -= res[3];
 		s['E'] -= res[3];
 		res[4] = s['R'];
 		s['F'] -= res[4];
 		s['O'] -= res[4];
 		s['U'] -= res[4];
 		s['R'] -= res[4];
 		res[1] = s['O'];
 		s['O'] -= res[1];
 		s['N'] -= res[1];
 		s['E'] -= res[1];
 		res[5] = s['F'];
 		s['F'] -= res[5];
 		s['I'] -= res[5];
 		s['V'] -= res[5];
 		s['E'] -= res[5];
 		res[7] = s['S'];
 		s['S'] -= res[7];
 		s['E'] -= res[7];
 		s['V'] -= res[7];
 		s['E'] -= res[7];
 		s['N'] -= res[7];
 		res[9] = s['N']/2;
 		s['N'] -= res[9];
 		s['I'] -= res[9];
 		s['N'] -= res[9];
 		s['E'] -= res[9];
 		//for( int i='A';i<='Z';i++ )	cout << s[i] << " ";
 		//	cout << endl << endl;
 		assert( *max_element(s,s+150)==0 );
 		++id;
 		cout << "Case #" << id << ": ";
 		for( int i=0;i<=9;i++ )
 			while( res[i]-- )	cout << i;
 		cout << endl;
 	}
 }

