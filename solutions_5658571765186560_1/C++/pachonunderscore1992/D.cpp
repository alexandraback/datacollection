#include <bits/stdc++.h>

using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 100010;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

bool inside(int r,int c, int n, int m){
   if(r >= 0 && c >= 0 && r < n && c < m){
      return true;
   }
   return false;
}

int bfs(vector<string> figure, ii p, vector<vector<bool>> &vis){
   int n = figure.size();
   int m = figure[0].size();
   queue<ii> q;
   q.push(p);
   vis[p.first][p.second] = true;
   int ans = 1;
   while(!q.empty()){
      ii aux = q.front();
      q.pop();
      int r = aux.first;
      int c = aux.second;
      for(int i = 0 ; i < 4 ; i++){
         int rr = r + dr[i];
         int cc = c + dc[i];
         if(inside(rr,cc,n,m) && figure[rr][cc] == '.' && !vis[rr][cc]){
            q.push(ii(rr,cc));
            vis[rr][cc] = true;
            ans++;
         }
      }
   }
   return ans;
}

bool possible(vector<string> figure, int x){
   int n = figure.size();
   int m = figure[0].size();
   vector<vector<bool>> vis(n, vector<bool>(m, false));
   for(int i = 0 ; i < n ; i++ ){
      for(int j = 0 ; j < m ; j++ ){
         if(figure[i][j] != 'X' && !vis[i][j]){
            int r = bfs(figure, ii(i,j), vis);
            if(r % x != 0) {
               return false;
            }
         }
      }
   }
   return true;
}

int main(){
#ifndef ONLINE_JUDGE
   freopen("D-large.in","r",stdin);
   freopen("D-large.out","w",stdout);
   // freopen("in","r",stdin);
#endif
   vector< vector<string> > xominoes_1;
   vector< vector<string> > xominoes_2;
   vector< vector<string> > xominoes_3;
   vector< vector<string> > xominoes_4;
   vector< vector<string> > xominoes_5;
   vector< vector<string> > xominoes_6;
   vector<string> figure;
   xominoes_1 = {
      {
         "X"
      }
   };
   xominoes_2 = {
      {
         "X",
         "X"
      }
   };
   xominoes_3 = {
      {
         "XX",
         "X."
      } , {
         "X",
         "X",
         "X"
      }
   };
   xominoes_4 = {
      {
         "XX",
         "XX"
      } , {
         "XX",
         "X.",
         "X."
      } , {
         "X.",
         "XX",
         "X."
      } , {
         "X.",
         "XX",
         ".X"
      }, {
         "X",
         "X",
         "X",
         "X"
      }
   };
   xominoes_5 = {
      {//1
         "XXX",
         "X..",
         "X.."
      } , {//2
         ".X",
         "XX",
         "X.",
         "X."
      }, {//3
         "X.",
         "XX",
         "X.",
         "X."
      } , {//4
         "X..",
         "XXX",
         "X.."
      }, {//5
         "X..",
         "XXX",
         ".X."
      }, {//6
         "X..",
         "XXX",
         "..X"
      }, {//7
         "X.",
         "X.",
         "X."
         "XX"
      }, {//8
         "XX",
         "X.",
         "XX"
      }, {//9
         "XX",
         "XX",
         "X."
      }, {//10
         ".X.",
         "XXX",
         ".X."
      }, {//11
         "XX.",
         ".XX",
         "..X"
      }, {//12
         "X",
         "X",
         "X",
         "X",
         "X"
      }
   };
   xominoes_6 = {
      {
         "X",
         "X",
         "X",
         "X",
         "X",
         "X"
      },{
         "XX",
         "X.",
         "X.",
         "X.",
         "X."
      },{
         "X.",
         "XX",
         "X.",
         "X.",
         "X."
      },{
         "X.",
         "X.",
         "XX",
         "X.",
         "X."
      },{
         ".X",
         "XX",
         "X.",
         "X.",
         "X."
      },{
         "XX",
         "XX",
         "X.",
         "X."
      },{
         "XX",
         "X.",
         "XX",
         "X."
      },{
         "XX",
         "X.",
         "X.",
         "XX"
      },{
         "X.",
         "XX",
         "XX",
         "X."
      },{
         "XXX",
         "X..",
         "X..",
         "X.."
      },{
         "X..",
         "XXX",
         "X..",
         "X.."
      },{
         "XXX",
         ".X.",
         ".X.",
         ".X."
      },{
         ".XX",
         "XX.",
         ".X.",
         ".X."
      },{
         ".XX",
         ".X.",
         "XX.",
         ".X."
      },{
         ".XX",
         ".X.",
         ".X.",
         "XX."
      },{
         ".X.",
         ".XX",
         "XX.",
         ".X."
      },{
         ".X.",
         "XXX",
         ".X.",
         ".X."
      },{
         ".X.",
         "XXX",
         "X..",
         "X.."
      },{
         ".X",
         "XX",
         "X.",
         "XX"
      },{
         ".X",
         ".X",
         "XX",
         "X.",
         "X."
      },{
         ".X",
         "XX",
         "XX",
         "X."
      },{
         "XX",
         "XX",
         "XX"
      },{
         "..X",
         "XXX",
         ".X.",
         ".X."
      },{
         "XXX",
         ".XX",
         ".X."
      },{
         "..X",
         ".XX",
         "XX.",
         ".X."
      },{
         "..X",
         "XXX",
         "X..",
         "X.."
      },{
         ".XX",
         "XX.",
         "X..",
         "X.."
      },{
         "XXX",
         "X.X",
         "X.."
      },{
         "X.X",
         "XXX",
         "X.."
      },{
         "X.X",
         "XXX",
         ".X."
      },{
         ".XX",
         ".X.",
         "XX.",
         "X.."
      },{
         "X..",
         "XX.",
         "XXX"
      },{
         ".X.",
         "XXX",
         "XX."
      },{
         "..X",
         "XXX",
         "XX."
      },{
         "..X",
         ".XX",
         "XX.",
         "X.."
      }
   };
   vector< vector< vector<string> > > xominoes {
      xominoes_1,
      xominoes_2,
      xominoes_3,
      xominoes_4,
      xominoes_5,
      xominoes_6
   };

   int casos;
   cin >> casos;
   for(int caso = 1 ; caso <= casos ; caso++){
      int x, r, c;
      cin >> x >> r >> c;
      int n = r*c;
      bool sw = true;
      if(x >= 7) {
         sw = false;
      } else {
         for(vector<string> xomino : xominoes[x-1]) {
            bool can = false;
            int n = xomino.size();
            int m = xomino[0].size();
            for(int i = 0 ; i <= r-n && !can ; i++){
               for(int j = 0 ; j <= c-m && !can ; j++){
                  vector<string> board(r, string(c, '.'));
                  for(int k = 0 ; k < n ; k++){
                     for(int q = 0 ; q < m ; q++){
                        board[i+k][j+q] = xomino[k][q]; 
                     }
                  }
                  if(possible(board,x)) {
                     can = true;
                  }
               }
            }
            swap(r,c);
            for(int i = 0 ; i <= r-n && !can ; i++){
               for(int j = 0 ; j <= c-m && !can ; j++){
                  vector<string> board(r, string(c, '.'));
                  for(int k = 0 ; k < n ; k++){
                     for(int q = 0 ; q < m ; q++){
                        board[i+k][j+q] = xomino[k][q]; 
                     }
                  }
                  if(possible(board,x)) {
                     can = true;
                  }
               }
            }
            swap(r,c);
            sw &= can;
         }
      }
      cout << "Case #"<< caso <<": " << (sw ? "GABRIEL" : "RICHARD") << endl;
   }
   return 0;
}