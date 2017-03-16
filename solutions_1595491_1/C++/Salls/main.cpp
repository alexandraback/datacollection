#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){

int T,tt,i,j,k;
int N,S,P;

ifstream fin;
ofstream fout;

fout.open("out.txt");
fin.open("b.in");
if(!fin.good()){
cout<<"NO"<<endl;
return 0;
}
fin>>T;



for(tt=1;tt<=T;tt++){
fin>>N>>S>>P;
int num=0;
int s;
for(i=0;i<N;i++){
   fin>>s;
   if(P>10)
      continue;

   if(s/3>=P){
      num++;
      continue;
      }
   if(s%3==0 && (s/3)+1>=P && S>0 && s>0){
      num++;
      S--;
      continue;
      }

   if(s%3>0 && (s/3)+1>=P){
      num++;
      continue;
      }
   if(s%3==2 && (s/3)+2>=P && S>0){
      num++;
      S--;
      continue;
      }

   }



fout<<"Case #"<<tt<<": "<<num<<endl;

}

fin.close();
fout.close();


return 0;
}
