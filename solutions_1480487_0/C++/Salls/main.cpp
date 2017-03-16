#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

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
fout<<fixed;
fout.precision(6);



for(int t=0;t<T;t++){

   fout<<"Case #"<<t+1<<": ";
   int N,temp;
   vector<int> scores,copy,sum;

   scores.clear();
   copy.clear();
   inf>>N;
   int tot=0;
   for(int i=0;i<N;i++){
      inf>>temp;
      tot+=temp;
      scores.push_back(temp);
      }

   copy=scores;

   double ans;
   int s;
   int need;

   for(int i=0;i<N;i++){
      s=scores[i];
      copy=scores;
      copy.erase(copy.begin()+i);      
      sort(copy.begin(),copy.end());

      sum.clear();
      temp=0;
      for(int j=0;j<N-1;j++){
         temp+=copy[j];
         sum.push_back(temp);
         }


      need=0;
      int num=0;
      for(num=0; num<N-1 ;num++){
         need=max(s*(num+1)-sum[num], copy[num]*(num+1)-sum[num]+copy[num]-s);
         if(need>tot){
            break;
            }
         }
      need=max(s*(num)-sum[num-1], copy[num-1]*(num)-sum[num-1]+copy[num-1]-s);

      ans=0.000;
      if(copy[num-1]>s)
         ans=double(copy[num-1]-s)/tot;

      int remain=tot-need;
      
      ans+=(double(remain)/double(num+1.0))/double(tot);
      ans*=100.00;

      //fix
      if(num!=N-1)
        if(copy[num]<s)
         ans=0.000;

      fout<<ans<<" ";

      }



   fout<<endl;
   }

fout.close();
return 0;
}







