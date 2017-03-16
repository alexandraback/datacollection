#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz size()
#define INF (int)1e9
 
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector< vector <int> > VVI;
typedef pair<int,int> pii;

int rowCheck(vector <string> grid, char c) {

  for(int i=0; i<4; i++) {
    int count = 0;
    for(int j=0; j<4; j++) {
       if(grid[i][j]==c || grid[i][j]=='T') count++; 
    }
    if(count == 4) return 1;
  }   
  return 0;
}

int colCheck(vector <string> grid, char c) {

  for(int i=0; i<4; i++) {
    int count = 0;
    for(int j=0; j<4; j++) {
       if(grid[j][i]==c || grid[j][i]=='T') count++;
    }
    if(count == 4) return 1;
  }   
  return 0;
}

int diaCheck(vector <string> grid, char c) {
  int count = 0;
  for(int i=0; i<4; i++) {
      if(grid[i][i]==c || grid[i][i]=='T') count++;
  }   
  if(count==4) return 1;
  count =0;
  for(int i=0; i<4; i++) {
      if(grid[i][3-i]==c || grid[i][3-i]=='T') count++;
  }  
  if(count==4) return 1; 
  return 0;
}

int checkDraw(vector <string> grid) {
 
   for(int i=0; i<4; i++) {
      for(int j=0; j<4; j++) {
          if(grid[i][j]=='.') return 0;
      }
   }
   return 1;
}

int checkState(vector <string> grid) {
  
    if(rowCheck(grid,'X') || colCheck(grid,'X') || diaCheck(grid,'X')) return 1;
    if(rowCheck(grid,'O') || colCheck(grid,'O') || diaCheck(grid,'O')) return 2;
    if(checkDraw(grid)) return 0;
    return -1;
}
    
string translate(int x) {
  if(x == 1) return "X won";
  if(x == 2) return "O won";
  if(x == 0) return "Draw";
  return "Game has not completed";
}
int main() {
    
    freopen ("abc.txt", "r", stdin);
    freopen ("myfile.txt","w",stdout);
    int T;
    cin>>T;
    vector <string> res;
    REP(i,T) {
      string row;
      vector <string> grid;
      REP(j,4) {
        cin>>row;
        grid.pb(row);  
      }     
      
  
      cout<< "Case #" << i+1 << ": " <<translate(checkState(grid))<<endl;
      
    }
    //while(1);
}
  
