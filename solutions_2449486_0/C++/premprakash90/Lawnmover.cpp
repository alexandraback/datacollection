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
int N,M;
bool colValidate(vector < vector<int> > grid, int col, int g) {
  
    for(int i=0; i<N; i++) {
       if(grid[i][col] > g) return false;
    }
    return true;
}

 bool rowValidate(vector < vector<int>  > grid, int row, int g) {
  
    for(int i=0; i<M; i++) {
       if(grid[row][i] > g) return false;
    }
    return true;
}

string validate(vector < vector<int> > grid){
     N = grid.sz;
     M = grid[0].sz;
    for(int k=1;k<=2;k++) {
       for(int i=0; i<N; i++) {
          for(int j=0;j<M;j++) {
            if(grid[i][j] == k) {
              int value = rowValidate(grid,i,k) | colValidate(grid,j,k);
              if(!value) return "NO";
            }
          }
       }
    }
    return "YES";
}

int main() {
   freopen("lawin.txt","r",stdin);
   freopen("lawnout.txt","w",stdout);
   int T;
   cin>>T;
   REP(t,T) {
      int N,M;
      cin>>N>>M;
      vector < vector<int> > grid;
      REP(i,N) {
         vector <int> row;
         REP(j,M) {
           int num; cin>>num;
           row.pb(num);
         }
         grid.pb(row);
      }
      cout<<"Case #"<<t+1<<": "<<validate(grid)<<endl;
   }
   //while(1);
}
