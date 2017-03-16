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
int board[2501][2501];
int column[2501];
int row[2501];
int bitCnt(int num){
   int ans = 0;
   while( num != 0 ){
      ans++;
      num=num&(num-1);
   }
   return ans;
}
int main(){
  int n_case;
  cin >> n_case;
  for( int loop = 0 ; loop < n_case ; loop++ ){
   int N;
   cin >> N;
   vector<vector<int> > v(2*N-1,vector<int>(N,0));
   memset( column, -1, sizeof(column));
   memset( row, -1, sizeof(row));
   for( int i = 0 ; i <2*N-1; i++ ){
      for( int j=0; j < N; j++ ){
         cin >> v[i][j];
      }
   }
   sort( v.begin(),v.end() );
   for( int mask =0 ; mask < (1<<(2*N-1)); mask++ ){
      if( bitCnt(mask)!= N ) continue;
      vector<vector<int> > board(N, vector<int>(N,0));
      int ind=0;
      //create board;
      for( int i=0; i<2*N-1; i++){
         if( (mask&(1<<i)) !=0 ){
           for( int j=0; j<N; j++){
            board[j][ind]=v[i][j];
           }
           ind++;
         }
      }
      //check board;
      int ansInd=-1;
      int curInd=0;
      bool ok = true;
      for( int i=0; i <2*N-1; i++){
         if( (mask&(1<<i)) ==0 ){
            if( board[curInd] == v[i] ){
               //do nothing
            }
            else if( board[curInd+1]==v[i] && ansInd==-1 ){
               ansInd=curInd;
               curInd++;
            }
            else{
               //fault
               ok=false;
               break;
            }
            curInd++;
         }
      }
      if(ok){
         if(ansInd==-1) ansInd=N-1;
         cout << "Case #" << loop+1 << ": ";
         for( int i=0; i <N; i++){
            cout << board[ansInd][i]<<" ";
         }
         cout << endl;
         break;
      }
   }

  }
  return 0;
}
