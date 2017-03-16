#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <string>
#include <sstream>

using namespace std;

char A[4][4];

string getWinner(){
   //check for win
   bool win = true;
   for(int i=0;i<4;i++)
      if(A[i][i]!='T'&&A[i][i]!='X')
         win = false;

   if(win)
      return "X won";

   win = true;
   for(int i=0;i<4;i++)
      if(A[3-i][i]!='T'&&A[3-i][i]!='X')
         win = false;

   if(win)
      return "X won";

   for(int j=0;j<4;j++){
      win = true;
      for(int i=0;i<4;i++)
         if(A[i][j]!='T'&&A[i][j]!='X')
            win = false;

      if(win)
         return "X won";
      }

   for(int i=0;i<4;i++){
      win = true;
      for(int j=0;j<4;j++)
         if(A[i][j]!='T'&&A[i][j]!='X')
            win = false;

      if(win)
         return "X won";
      }

   //check o
   win = true;
   for(int i=0;i<4;i++)
      if(A[i][i]!='T'&&A[i][i]!='O')
         win = false;

   if(win)
      return "O won";

   win = true;
   for(int i=0;i<4;i++)
      if(A[3-i][i]!='T'&&A[3-i][i]!='O')
         win = false;

   if(win)
      return "O won";

   for(int j=0;j<4;j++){
      win = true;
      for(int i=0;i<4;i++)
         if(A[i][j]!='T'&&A[i][j]!='O')
            win = false;

      if(win)
         return "O won";
      }

   for(int i=0;i<4;i++){
      win = true;
      for(int j=0;j<4;j++)
         if(A[i][j]!='T'&&A[i][j]!='O')
            win = false;

      if(win)
         return "O won";
      }

   bool complete = true;
   for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
         if(A[i][j]=='.')
            complete = false;

   if(complete)
      return "Draw";
   else
      return "Game has not completed";

}

int main(){



ifstream inf;
ofstream fout;



inf.open("a.in");
fout.open("out.txt");
if(!inf.good()){
   cout<<"bad input"<<endl;
   return 0;
   }

int T;
inf>>T;




for(int t=0;t<T;t++){
   for(int i=0;i<4;i++)
      for(int j=0;j<4;j++)
         inf>>A[i][j];

   fout<<"Case #"<<t+1<<": "<<getWinner()<<endl;
   }

fout.close();
return 0;
}







