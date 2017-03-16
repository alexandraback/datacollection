#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>

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

int N,temp;
int num,num2;


for(int t=0;t<T;t++){
   vector<int> v;
   vector<set<int> > inherits;
   set<int>::iterator it,it2;
   v.clear();
   inf>>N;
   inherits.clear();
   inherits.resize(N);


   for(int i=0;i<N;i++){
      inf>>temp;
      v.push_back(temp);

      for(int j=0;j<v[i];j++){
         inf>>temp;

         inherits[i].insert(temp);
         }
      }


   bool found=false;
   bool changed=false;

   for(int i=0;i<N;i++){
      set<int> checked;
      changed=false;
      for(it=inherits[i].begin();it!=inherits[i].end();++it){
         if(changed)
            it=inherits[i].begin();
         changed=false;
         num = *it - 1;
         if(checked.find(num)!=checked.end())
            continue;
         checked.insert(num);

            for(it2=inherits[num].begin();it2!=inherits[num].end();++it2){
               num2 = *it2;
               if(inherits[i].find(num2)!=inherits[i].end()){
                  found=true;
                  }
               inherits[i].insert(num2);
               if(num>i)
                  changed=true;
               else{
                  checked.insert(num2-1);
                  changed=true;
                  }
                  it=inherits[i].begin();
               }
        
         if(found)
            break;
         }

      if(found)
          break;
      }


   if(found)
   fout<<"Case #"<<t+1<<": "<<"Yes"<<endl;
   else
   fout<<"Case #"<<t+1<<": "<<"No"<<endl;  

   }

fout.close();
return 0;
}







