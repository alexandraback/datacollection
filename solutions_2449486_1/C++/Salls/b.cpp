#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <string>
#include <sstream>

using namespace std;

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
   int N,M;
   inf>>N>>M;
   int arr[100][100];
   for(int i=0;i<N;i++)
      for(int j=0;j<M;j++)
         inf>>arr[i][j];


   int rowMax[100];
   int colMax[100];

   //get row maxes
   for(int i=0;i<N;i++){
      rowMax[i] = 0;
      for(int j=0;j<M;j++)
         rowMax[i] = max(rowMax[i],arr[i][j]);
   }

   //get col maxes
   for(int j=0;j<M;j++){
      colMax[j] = 0;
      for(int i=0;i<N;i++)
         colMax[j] = max(colMax[j],arr[i][j]);
   }

   bool possible = true;
   for(int i=0;i<N;i++)
      for(int j=0;j<M;j++)
         if(arr[i][j]<rowMax[i] && arr[i][j]<colMax[j])
            possible = false;

   string ans;
   if(possible)
      ans = "YES";
   else
      ans = "NO";


   fout<<"Case #"<<t+1<<": "<<ans<<endl;
   }

fout.close();
return 0;
}







