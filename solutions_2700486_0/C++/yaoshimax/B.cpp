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

bool check( int code, int N , int X , int Y ){
  int top=2;
  vector< pair<int,int> > field;
  for( int i = 0 ; i < N; i++ ){
    int curX = 0;
    int curY = top;
    while( curY > 0 ){
      bool down = true;
      bool left = true;
      bool right = true;
      if( curY - 2 < 0 ) down =false;
      for( int j = 0 ; j < (int)field.size(); j++){
        if( field[j].first == curX && field[j].second == curY-2 ){
          down = false;
        }
        if( field[j].first == curX-1 && field[j].second == curY-1 ){
          left = false;
        }
        if( field[j].first == curX+1 && field[j].second == curY-1 ){
          right = false;
        }
      }
      if( down == false && left == false && right == false ){
        break;
      }
      if( down ){
        curY -=2;
      }
      else if( left && !right ){
         curX-=1;
         curY-=1;
      }
      else if( right && !left ){
        curX+=1;
        curY-=1;
      }
      else if( right && left ){
        if( (code&(1<<i))==0 ){
         curX-=1;
         curY-=1;
        }
        else{
        curX+=1;
        curY-=1;
        }
      }
      else{
        cout<< "ERROR CASE!" << endl;
      }
    }
//    cout << curX << ", " << curY<<endl;
    if( curX ==X && curY==Y ) return true;
    field.push_back(make_pair(curX,curY));
    if( curX == 0) top += 2;
  }
  return  false;

}

int main(){
   int n_case;
   cin >> n_case;
   for( int loop = 0 ; loop < n_case ; loop++ ){
     int N,X,Y;
     cin >>N>>X>>Y;
     int count =0;
     for( int i = 0 ; i < (1LL<<N); i++ ){
      if( check( i ,N,X, Y) ){
        count++;
      }
     }
     double ans = count;
     ans /= (1LL<<N);
  //   cout << count << "/" << (1LL<<N) << endl;
     cout << "Case #" << loop+1 << ": " ;
         cout.setf(ios::fixed, ios::floatfield);
         cout.precision(12);
         cout << ans << endl;
   }
   return 0;
}
