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
int getScore(char c){
   if(c=='i') return 2;
   if(c=='j') return 3;
   if(c=='k') return 4;
   else return 0;
}

int main(){
  int n_case;
  cin >> n_case;
  int getTable[5][5];
  getTable[1][1]=1;
  getTable[1][2]=2;
  getTable[1][3]=3;
  getTable[1][4]=4;
  getTable[2][1]=2;
  getTable[2][2]=-1;
  getTable[2][3]=4;
  getTable[2][4]=-3;
  getTable[3][1]=3;
  getTable[3][2]=-4;
  getTable[3][3]=-1;
  getTable[3][4]=2;
  getTable[4][1]=4;
  getTable[4][2]=3;
  getTable[4][3]=-2;
  getTable[4][4]=-1;
  for( int loop = 0 ; loop < n_case ; loop++ ){
    long long L,X;
    cin >> L>>X;
    string S;
    cin >> S;
    string Target="";
    int len=X%4;
    while( len+4 <= min(20LL,X) ){
      len+=4;
    }
    //len=X;
    for( int i = 0 ; i < len; i++ ){
      Target+=S;
    }
    long long size = Target.size();
    int goal=2;
    int cur=1;
    for( long long ti= 0 ; ti <size; ti++){
      int score=getScore(Target[ti]);
      if( cur > 0 ){
         cur=getTable[cur][score];
      }else{
         cur=-getTable[-cur][score];
      }
      if(cur==goal&&goal<4){
         goal++;
         cur=1;
      }
    }
    if( goal==4 && cur==4 ){
      cout << "Case #" << loop+1 << ": " <<"YES"<< endl;
    }
    else{
      cout << "Case #" << loop+1 << ": " <<"NO"<< endl;
    }
  }
  return 0;
}
