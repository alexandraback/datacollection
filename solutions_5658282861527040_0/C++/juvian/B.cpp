#include <iostream>
#include <vector>
#include <fstream>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;




int main(){
   int cases;
   ifstream in("B-small.in");
   ofstream out("B-small.out");
   in>>cases;
   for (int casen=1;casen<=cases;casen++){
       int a,b,k;
       in>>a>>b>>k;
       int maches=0;
       for(int i=0;i<a;i++){
               for(int j=0;j<b;j++){     
                       if((i&j) <=(k-1)) maches++;  
               }        
               
       }
       out<<"Case #"<<casen<<": "<<maches<<"\n";
         
   }    
    
  system("pause");  
}
