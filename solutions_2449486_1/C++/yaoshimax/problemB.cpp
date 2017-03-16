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

int main(){
   int n_case;
   cin >> n_case;
   for( int loop = 0 ; loop < n_case ; loop++ ){
     int h,w;
     cin >> h>>w;
     int map[h][w];
     for( int i = 0 ; i < h; i++ )for( int j = 0 ; j < w; j++ ){
      cin >> map[i][j];
     }
     int hmax[h];
     int wmax[w];
     memset( hmax , 0 , sizeof(hmax));
     memset( wmax, 0 , sizeof(wmax));
     for( int i = 0 ; i < h; i++ ){
      for( int j = 0 ; j < w; j++ ){
        hmax[i] = max( hmax[i], map[i][j] );
        wmax[j] = max( wmax[j], map[i][j] );
      }
     }
     bool ok = true;
     for( int i = 0 ; i < h; i++ )for( int j = 0 ; j < w; j++){
      if( map[i][j] != min( hmax[i], wmax[j] ) ){
        ok = false;
        break;
      }
     }
     string ans = "YES";
     if( !ok ) ans = "NO";
     cout << "Case #" << loop+1 << ": " <<ans<< endl;
   }
   return 0;
}
