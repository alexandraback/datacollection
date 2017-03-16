#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int f_row(string maze[4]){
  int x;
  for(int i=0;i<4;++i){
    int x=0;
    int O=0;
    int t=0;
    for(int j=0;j<4;++j){
      if(maze[i][j]=='O')++O;
      if(maze[i][j]=='X')++x;
      if(maze[i][j]=='T')++t;
    }
    if(x+t==4)
      return 1;
    if(O+t==4)
      return 2;
  }
  return 0;
}

int f_col(string maze[4]){
  int x;
  int min=0;
  for(int i=0;i<4;++i){
    int x=0;
    int O=0;
    int t=0;
    for(int j=0;j<4;++j){
      if(maze[j][i]=='O')++O;
      if(maze[j][i]=='X')++x;
      if(maze[j][i]=='T')++t;
    }
    if(x+t==4)
      return 1;
    if(O+t==4)
      return 2;
    if(x+O+t<4)
      min = 3;
  }
  return min;
}

int f_diag(string maze[4]){
  int x=0;
  int O=0;
  int t=0;
  for(int i=0;i<4;++i){
    if(maze[i][i]=='O')++O;
    if(maze[i][i]=='X')++x;
    if(maze[i][i]=='T')++t;
  }
  if(x+t==4)
    return 1;
  if(O+t==4)
    return 2;
    
    
  x=0;
  O=0;
  t=0;
  for(int i=0;i<4;++i){
    if(maze[i][3-i]=='O')++O;
    if(maze[i][3-i]=='X')++x;
    if(maze[i][3-i]=='T')++t;
  }
  if(x+t==4)
    return 1;
  if(O+t==4)
    return 2;     
  return 0;
}

int main(){
  int T;
  cin >> T;
  string maze[4];
  for(int t=1;t<=T;++t){
      cout << "Case #"<<t<<": ";
      cin >> maze[0];
      cin >> maze[1];
      cin >> maze[2];
      cin >> maze[3];
      int d = f_diag(maze);
      if(d==1)
        cout << "X won"<<endl;
      else if(d==2)
        cout << "O won"<<endl;
      else{  
        int r = f_row(maze);
        if(r==1)
          cout << "X won"<<endl;
        else if(r==2)
          cout << "O won"<<endl;
        else{        
          int c = f_col(maze);
          if(c==1)
            cout << "X won"<<endl;
          else if(c==2)
            cout << "O won"<<endl;
          else if(c==3)
            cout << "Game has not completed"<<endl;
          else
            cout << "Draw"<<endl;
        }
      }
        
      
  }
  return 0;
}
