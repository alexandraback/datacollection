#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

#define LL long long
using namespace std;

LL calc(int x,int y, LL s, LL xL, LL yL);
int N,M;
   vector<LL> a,b;
   vector<int> A,B;

int main(){



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




for(int t=0;t<T;t++){

   inf>>N>>M;

   a.resize(N);
   b.resize(M);
   A.resize(N);
   B.resize(M);

   for(int i=0;i<N;i++){
      inf>>a[i];
      inf>>A[i];
     }
   for(int i=0;i<M;i++){
      inf>>b[i];
      inf>>B[i];
      }

   int x=0,y=0;
   LL ans=calc(x,y,0,a[x],b[y]);

   fout<<"Case #"<<t+1<<": "<<ans<<endl;
   }

fout.close();
return 0;
}


LL calc(int x,int y, LL s, LL xL, LL yL){

 if(A[x]==B[y]){

   s+=min(xL,yL);

   if(xL<yL){  
      yL-=xL;
      x++; 
      xL=a[x];
      }
   else if(xL>yL){  
      xL-=yL;
      y++; 
      yL=b[y];
      }
   else {
      x++;
      y++;
      xL=a[x];
      yL=b[y];      
      }
   if(x<N && y<M)
      return calc(x,y,s,xL,yL);
   else
      return s;
   }
   else if(x<N-1 && y<M-1)
   {
   return max( calc(x+1,y,s,a[x+1],yL), calc(x,y+1,s,xL,b[y+1]) );
   }
   else if(x<N-1)
      return calc(x+1,y,s,a[x+1],yL);
   else if(y<M-1)
      return calc(x,y+1,s,xL,b[y+1]);
   else 
      return s;

}




