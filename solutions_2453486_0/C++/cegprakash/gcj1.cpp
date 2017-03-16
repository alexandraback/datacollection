#include<iostream>
#include<queue>
#include<map>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<string.h>

using namespace std;
vector<string> board;
string temp;

bool isWinner(char ch){
     //checking rows;
     int i,j;
     for(i=0;i<4;i++)
     {
         bool win=true;
         for(j=0;j<4;j++)
           if(board[i][j]!=ch&&board[i][j]!='T'){
              win=false;
              break;
           }
         if(win==true) return true;            
     }
     //checking cols
     for(j=0;j<4;j++)
     {
         bool win=true;
         for(i=0;i<4;i++)
           if(board[i][j]!=ch&&board[i][j]!='T'){
              win=false;
              break;
           }
         if(win==true) return true;            
     }
     //checking diagonals
     int c=i=j=0;
     bool win=true;
     for(;c<4;c++,i++,j++)
       if(board[i][j]!=ch&&board[i][j]!='T')
       {
          win=false; break;
       }
     if(win) return win;
     c=0;i=0;j=3;
     win=true;
     for(;c<4;c++,i++,j--)
       if(board[i][j]!=ch&&board[i][j]!='T')
       {
          win=false; break;
       }
     if(win) return win;
     
     
     return false;
}

int main(){
    int t,i,j,c=1;
    bool full;
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>t;
    while(t--){
           board.clear();
           for(i=0;i<4;i++) {cin>>temp; board.push_back(temp); }
           full=true;
           for(i=0;i<4;i++) for(j=0;j<4;j++) if(board[i][j]=='.') full=false;
           if(isWinner('X')) cout<<"Case #"<<c<<": X won"<<endl;
           else if(isWinner('O')) cout<<"Case #"<<c<<": O won"<<endl;
           else if(full) cout<<"Case #"<<c<<": Draw"<<endl;
           else  cout<<"Case #"<<c<<": Game has not completed"<<endl;
           c++;        
    }
    return 0;
}
