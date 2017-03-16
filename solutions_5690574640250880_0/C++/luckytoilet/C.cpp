#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <queue>
#define LL long long
using namespace std;

template<typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
    s << '{';
    for (int i = 0 ;i <  v.size(); ++i) {
        s << (i ? "," : "") << v[i];
    }
    return s << '}';
}

template<typename T, typename U>
ostream& operator<<(ostream& s, const pair<T,U>& p) {
  s << "(" << p.first << "," << p.second << ")";
  return s;
}


int neighbor_mines(vector< vector<char> > &grid, int r, int c){

  if(grid[r][c] == '*') return 9;

  int m = 0;
  int dir1[] = {-1,0,1,-1,1,-1,0,1};
  int dir2[] = {-1,-1,-1,0,0,1,1,1};

  for(int i=0; i<8; i++){
    int rr = r+dir1[i];
    int cc = c+dir2[i];

    if(rr<0 || cc<0) continue;
    if(rr>=grid.size() || cc>=grid[0].size()) continue;
    
    if(grid[rr][cc] == '*') m++;
  }

  return m;

}


int count_all_mines(vector< vector<char> > &grid){
  int mines = 0;
  for(int i=0; i<grid.size(); i++)
    for(int j=0; j<grid[0].size(); j++)
      if(grid[i][j] == '*')
        mines++;
  return mines;
}


bool flood_fill(vector< vector<char> > &grid){

  vector< pair<int,int> > queue;
  queue.push_back(make_pair(grid.size()-1, grid[0].size()-1));

  vector< pair<int,int> > visited;


  while(queue.size() > 0){

    pair<int,int> here = queue.back();
    queue.pop_back();

    int mines = neighbor_mines(grid,here.first,here.second);
    if(mines == 0){

      int dir1[] = {-1,0,1,-1,1,-1,0,1};
      int dir2[] = {-1,-1,-1,0,0,1,1,1};

      for(int i=0; i<8; i++){
        int rr = here.first+dir1[i];
        int cc = here.second+dir2[i];

        if(rr<0 || cc<0) continue;
        if(rr>=grid.size() || cc>=grid[0].size()) continue;
        
        pair<int,int> next = make_pair(rr,cc);
        if(find(visited.begin(),visited.end(),next) == visited.end()){
          if(find(queue.begin(),queue.end(),next) == queue.end()){
            queue.push_back(next);
          }
        }
      }

    }

    visited.push_back(here);

  }


  /*
  for(int i=0; i<grid.size(); i++){
    for(int j=0; j<grid[0].size(); j++){
      //cout<<neighbor_mines(grid,i,j);
      //cout<<grid[i][j];
      if(find(visited.begin(),visited.end(),make_pair(i,j)) != visited.end())
        cout<<"*";
      else
        cout<<".";
    }
    cout<<endl;
  }
  */

  int tot_size = grid.size() * grid[0].size();
  if(visited.size() + count_all_mines(grid) == tot_size) return true;

  return false;
}


vector< vector<char> > soln;
int GOAL;

bool search(vector< vector<char> > &grid, int pos){

  int mines = count_all_mines(grid);
  if(mines == GOAL){
    if(!flood_fill(grid)) return false;
    soln = grid;
    return true;
  }

  if(pos >= grid.size() * grid[0].size()) return false;

  int R = pos / grid[0].size();
  int C = pos % grid[0].size();

  if(grid[R][C] == '*') return search(grid,pos+1);

  grid[R][C] = '*';
  if(search(grid,pos+1)) return true;

  grid[R][C] = '.';
  if(search(grid,pos+1)) return true;

  return false;
}



int main(){

  int ncases; cin>>ncases;

  for(int nc = 1; nc <= ncases; nc++) {

    int ROWS; cin>>ROWS;
    int COLS; cin>>COLS;
    int MINES; cin>>MINES;


    vector< vector<char> > grid(ROWS, vector<char>(COLS,'.'));

    GOAL = MINES;
    bool found = search(grid,0);

    
    cout << "Case #" << nc << ":\n";
    if(!found) cout << "Impossible" << endl;
    else{
      soln[ROWS-1][COLS-1] = 'c';
      for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
          cout<<soln[i][j];
        }
        cout<<endl;
      }
    }

  }



}


