#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

struct P2{
int n;
int need;

bool operator<(const P2& rhs) const
{
return need<rhs.need;
}


};

struct P1{
int n;
int need;
int need2;

bool operator<(const P1& rhs) const
{
if(need<rhs.need)
   return true;
else if(need>rhs.need)
   return false;
else 
   return need2>rhs.need2;
}


};


int main(){

//learn
ifstream inf;
ofstream fout;

inf.open("a.in");
fout.open("out.txt");
if(!inf.good()){
   cout<<"no"<<endl;
   return 0;
   }

int T,N,temp;
P1 p1;
P2 p2;
inf>>T;

for(int t=0;t<T;t++){
   inf>>N;
   vector<P1> star1;
   vector<P2> star2;
   vector<int> done;
   star1.clear();
   star2.clear();
   done.clear();

   for(int i=0;i<N;i++){
      p1.n=i;
      p2.n=i;
      inf>>p1.need;
      inf>>p1.need2;

      star1.push_back(p1);
      p2.need=p1.need2;
      star2.push_back(p2);
      done.push_back(0);
      }

   sort(star1.begin(),star1.end());
   sort(star2.begin(),star2.end());


   int a=0,b=0;
   int numStars=0;
   int s=0;
   bool failed=false;
   while(numStars<2*N){
      if(star2[b].need<=numStars && b<N){
         s++;
         numStars += 2-done[star2[b].n];
         done[star2[b].n]=2;
         b++;
         continue;
         }

      if(star1[a].need<=numStars && a<N){
         if(done[star1[a].n]!=0){
            a++;
            continue;
            }

         int c=a;
         for(int j=a;j<N&&star1[j].need<=numStars;j++){
            if(done[star1[j].n]!=0)
               continue;
            if(star1[j].need2>star1[c].need2)
               c=j;
            }
            
         s++;
         numStars++;
         done[star1[c].n]=1;
         continue;
         }
      
      else{ //failed
         failed=true;
         break;
            }

      }
 
   if(b!=N && !failed){
      cout<<"BAD"<<endl;
      cout<<t+1<<endl;
      }

   if(failed)
      fout<<"Case #"<<t+1<<": Too Bad"<<endl;      
   else
      fout<<"Case #"<<t+1<<": "<<s<<endl;
   }

fout<<endl;
fout.close();

return 0;
}







