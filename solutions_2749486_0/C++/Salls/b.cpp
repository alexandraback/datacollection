#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct S{
int x,y,n;
};


int main(){



ifstream inf;
ofstream fout;



inf.open("b.in");
fout.open("out.txt");
if(!inf.good()){
   cout<<"bad input"<<endl;
   return 0;
   }

int T;
inf>>T;




for(int t=0;t<T;t++){
   int x,y;
   inf>>x>>y;
   int cx=0,cy=0;
   int n=0;
   string moves;
   queue<S> q;
   vector<S> v;
   //handle x
   while(cx!=x){
   if(cx<x){
      cx++;
      moves.push_back('W');
      moves.push_back('E');
      }
   else{
      cx--;
      moves.push_back('E');
      moves.push_back('W');
      }
   } 

   while(cy!=y){
   if(cy<y){
      cy++;
      moves.push_back('S');
      moves.push_back('N');
      }
   else{
      cy--;
      moves.push_back('N');
      moves.push_back('S');
      }
   } 

 
   fout<<"Case #"<<t+1<<": "<<moves<<endl;
   }

fout.close();
return 0;
}







