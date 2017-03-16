#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

bool __inline is_integer(double f){
    int i = floor(f+.5);
    return ( abs(f - static_cast<double>(i) )<0.0000001);
}

int GCD(int a, int b) 
{ 
  if ( b == 0 )
    return a;
  return GCD ( b,a%b);
} 

int LCM(int a, int b) 
{ 
    return a*(b/GCD(a,b)); 

}

bool isPrime(int number)
{
if (number > 3)
 {
 if (number % 2 == 0) return false;
 if (number % 3 == 0) return false;
 const int MAX = (int)sqrt(number) + 1;
 int i=5;
 while(i<MAX)
   {
   if ( (number % i) == 0) return false;
     i+=2;
   if ( (number % i) == 0) return false;
     i+=4;
   }
 }
else if (number<2)
 {
 return false;
 }
return true;
}


bool A[30][30];


int main(){

int T,tt,i,j,k;
int H,W,D;
double a,b;
char charc;
double div;

ifstream fin;
ofstream fout;
fin.open("d.in");
fout.open("out.txt");
if(!fin.good()){
   cout<<"NO"<<endl;
   return 0;

   }
char temp;
fin>>T;

for(tt=1;tt<=T;tt++){

//load
fin>>H>>W>>D;
for(i=0;i<H;i++)
   for(j=0;j<W;j++){
      fin>>temp;
      if(temp=='X'){
         a=i+.5;
         b=j+.5;
         A[i][j]=false;
         }
      else if(temp=='#')
         A[i][j]=true;
      else
         A[i][j]=false;
      
      }



//run
int n=0;
int D2=D*D;
int pi,pj;
double vi,vj,xi,xj,dDist,dist;

for(i=-D;i<=D;i++)
   for(j=-D;j<=D;j++){
      if( (i==0 && abs(j)!=1) || (j==0 && abs(i)!=1) )
         continue;
      if( i!=0 && j!=0 && GCD(abs(i),abs(j))!=1 )
         continue;

      if( i!=0 && j!=0)
         div=abs(2*i*j);
      else 
         div=2;


      dDist=sqrt((i*i+j*j)/(div*div));
      vi=i/div;
      vj=j/div;
      xi=a;
      xj=b;

      dist=0.0;
      while(dist<D){

         dist+=dDist;
         xi+=vi;
         xj+=vj;

         if(dist>D+.0000001)
            break;

         if( abs(xi-a)<.0000001 && abs(xj-b)<.0000001 ){
            n++;
            break;
            }

         //collision check
         if(is_integer(xi) && is_integer(xj)){
            pi=floor(xi+.5);
            pj=floor(xj+.5);
                     
            if(vi>0 && vj>0){
               if( A[pi][pj] ) {
                  if( A[pi-1][pj] && A[pi][pj-1]){
                     vi=-vi;
                     vj=-vj;
                     }
                  else if( A[pi-1][pj] )
                     vj=-vj;
                  else if( A[pi][pj-1] )
                     vi=-vi;
                  else 
                     break;
                  }}
            else if(vi>0 && vj<0){
               if( A[pi][pj-1] ) {
                  if( A[pi][pj] && A[pi-1][pj-1]){
                     vi=-vi;
                     vj=-vj;
                     }
                  else if( A[pi][pj] )
                     vi=-vi;
                  else if( A[pi-1][pj-1] )
                     vj=-vj;
                  else 
                     break;
                  }}
            else if(vi<0 && vj>0){
               if( A[pi-1][pj] ) {
                  if( A[pi][pj] && A[pi-1][pj-1]){
                     vi=-vi;
                     vj=-vj;
                     }
                  else if( A[pi][pj] )
                     vj=-vj;
                  else if( A[pi-1][pj-1] )
                     vi=-vi;
                  else 
                     break;
                  }}
            else if(vi<0 && vj<0){
               if( A[pi-1][pj-1] ) {
                  if( A[pi-1][pj] && A[pi][pj-1]){
                     vi=-vi;
                     vj=-vj;
                     }
                  else if( A[pi-1][pj] )
                     vi=-vi;
                  else if( A[pi][pj-1] )
                     vj=-vj;
                  else 
                     break;
                  }}
            }
         else if(is_integer(xi)){
         pi=floor(xi+.5);
         pj=floor(xj);
            if( vi > 0 ){
               if( A[pi][pj] )
                  vi=-vi;
               }
            else if( vi < 0 ){
               if( A[pi-1][pj] )
                  vi=-vi;
               }
            }
         else if(is_integer(xj)){
         pi=floor(xi);
         pj=floor(xj+.5);
            if( vj > 0 ){
               if( A[pi][pj] )
                  vj=-vj;
               }
            else if( vj < 0){
               if( A[pi][pj-1] )
                  vj=-vj;
               }
            }
         // end loop
         }

      }

fout<<"Case #"<<tt<<": "<<n<<endl;
}




return 0;
}
