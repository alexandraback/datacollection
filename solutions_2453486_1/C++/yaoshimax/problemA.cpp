#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

char check( char a, char b, char c, char d ){
  if( a == 'T' ) a = b;
  if( b == 'T' ) b = a;
  if( c == 'T' ) c = a;
  if( d == 'T' ) d = a;
  if( a == b && b == c && c == d && c!= '.' ) return a;
  else return 'T';
}
int main(){
   int n_case;
   cin >> n_case;
   for( int loop = 0 ; loop < n_case ; loop++ ){
     string field[4];
     for( int i = 0 ; i < 4 ; i++ ){
      cin >> field[i];
     }
     char winner = 'T';
     bool draw=true;
     for( int i = 0 ; i < 4; i++ )for( int j = 0 ; j < 4; j++ ){
      if( field[i][j] == '.' ){
        draw = false;
        break;
      }
     }
     for( int i =0; i < 4; i++ ){
       if( (winner = check( field[i][0],field[i][1],field[i][2],field[i][3] ))!= 'T' ){
        break;
       }
       if( (winner = check( field[0][i],field[1][i],field[2][i],field[3][i] ))!= 'T' ){
        break;
       }
     }
     if( winner == 'T' ){
       winner = check( field[0][0], field[1][1], field[2][2], field[3][3] );
       if( winner == 'T' ) winner = check( field[0][3], field[1][2], field[2][1], field[3][0] );
     }
     cout << "Case #" << loop+1 << ": " ;
     if( winner != 'T' ){
       cout << winner << " won";
     }
     else{
       if( draw ) cout << "Draw";
       else cout << "Game has not completed";
     }
     cout << endl;
   }
   return 0;
}
