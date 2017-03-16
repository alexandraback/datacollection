#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
int A,B;

//learn
ifstream inf;
ofstream fout;

inf.open("a.in");
fout.open("out.txt");
if(!inf.good()){
   cout<<"no"<<endl;
   return 0;
   }

int T;
inf>>T;
double temp;
double best,test;
double probCorrect;


for(int t=0;t<T;t++){

   inf>>A>>B;
   vector<double> p;
   p.clear();
   for(int i=0;i<A;++i){
      inf>>temp;
         p.push_back(temp);
      }

   best=B+2;
   probCorrect=1;
   test=A+B+1;
      if(test<best) 
         best=test;

   //loop through not deleted
   for(int i=1;i<=A;++i){
      probCorrect*=p[i-1];
      test=probCorrect * ( A-i+B-i+1 ) + (1.0-probCorrect)*( A-i+B-i+B+2);
      if(test<best) 
         best=test;
      }
   fout<<fixed;
   fout.precision(6);
   fout<<"Case #"<<t+1<<": "<<best<<endl;
   }

fout<<endl;
fout.close();
return 0;
}







