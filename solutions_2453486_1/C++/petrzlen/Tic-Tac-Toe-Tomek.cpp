#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    string M[4];
    REP(i, 4) cin >> M[i];
    
    int P[4][4];
    REP(i, 4) {
      REP(j, 4) {
        if(M[i][j]=='X') P[i][j]=1;
        if(M[i][j]=='O') P[i][j]=-1;
        if(M[i][j]=='T') P[i][j]=0;
        if(M[i][j]=='.') P[i][j]=-1000; 
        //cout << M[i][j];
      }
      //cout << endl;
    }
    
    vector<int> S; 
    int s;
    REP(i, 4){
      s=0;
      REP(j, 4) s+=P[i][j];
      S.push_back(s);
    }
    REP(i, 4){
      s=0;
      REP(j, 4) s+=P[j][i];
      S.push_back(s);
    }
    
    s=0;
    REP(i, 4){
      s+=P[i][i];
    }
    S.push_back(s);
    
    s=0;
    REP(i, 4){
      s+=P[i][3-i];
    }
    S.push_back(s);
    
    cout << "Case #"<<t+1<<": ";
    bool was_result=false;
    bool was_empty=false; 
    REP(i, S.size()){
      if(!was_result){
        if(S[i]>=3) {
          cout << "X won" << endl; 
          was_result = true; 
        }
        else if(-4<=S[i] && S[i]<=-3) {
          cout << "O won" << endl;
          was_result = true; 
        }
      }
      if(S[i]<=-5) {
        was_empty = true; 
      }
    }
    
    if(!was_result){
      if(was_empty) cout << "Game has not completed" << endl;
      else cout << "Draw" << endl;
    }
  }
  
	return 0;
}
