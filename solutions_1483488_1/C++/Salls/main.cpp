#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream> 


using namespace std;
int cycle(int a,int n);
int numDigits(int a);

//runs worst case in <15 secs with -O2

int main(){

int T,tt,i,j,k;

bool *data;

ifstream fin;
ofstream fout;

fout.open("out.txt");
fin.open("c.in");
if(!fin.good()){
cout<<"NO"<<endl;
//return 0;
}

fin>>T;


int A,B;
int r,p;
bool isC;
for(tt=1;tt<=T;tt++){
fin>>A>>B;
int n=0;
int nn;

data=new bool[B-A+1];
for(i=0;i<B-A+1;i++)
   data[i]=true;

for(i=A;i<B;i++){

   //check if done already
   if(!data[i-A])
      continue;
   data[i-A]=false;

   //else find all rotations
   p=numDigits(i);
   nn=1;
   for(k=1;k<p;k++){
      r=cycle(i,k);
      if(r<A || r>B)
         continue;
      if(!data[r-A])
         continue;

      data[r-A]=false;      
      nn++;
      }
   n += nn*(nn-1)/2;

   }



delete[] data;
fout<<"Case #"<<tt<<": "<<n<<endl;

}

fin.close();
fout.close();


return 0;
}

int cycle(int a,int n){
char arr[100];
stringstream s;
s<<a;
string b=s.str();
if(b.size()<n)
   return -2;

for(int i=0;i<n;i++)
   arr[i]=b[i];

for(int i=0;i<b.size()-n;i++)
   b[i]=b[i+n];

for(int i=0;i<n;i++)
   b[b.size()-n+i]=arr[i];

if(b[0]=='0')
   return -1;

int result;
stringstream s2(b);
s2>>result;
return result;

}

int numDigits(int a){
stringstream s;
s<<a;
return (s.str()).size();
}

