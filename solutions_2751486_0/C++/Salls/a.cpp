#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int arr[1000001];

int main(){



ifstream inf;
ofstream fout;



inf.open("a.in");
fout.open("out.txt");
if(!inf.good()){
   cout<<"bad input"<<endl;
   return 0;
   }

int T;
inf>>T;




for(int t=0;t<T;t++){
   string str;
   int n;
   inf>>str>>n;
   for(int i=0;i<str.size();i++)
      arr[i] = 0;
      
   int num = 0;
   for(int i=0;i<str.size();i++){
      if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' 
         && str[i] != 'u')
         num++;

      arr[i] = num;
   }

   vector<int> v;
   long long ans = 0;
   int length = 0;
   for(int i=0;i<str.size();i++){
      if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' 
         && str[i] != 'u')
         length++;
      else
         length=0;
      
      if(length>=n)
         v.push_back(i-n+1);
   }

   int index = 0;
   for(int i=0;i<str.size();i++){
      if(v.size()==0)
         break;
      int low = v[index];
      while(i>low && index<v.size()){
         index++;
         low = v[index];
      }
      if(index>=v.size())
         break;      

      int numSub = str.size()-(low+n)+1;
cout<<i<<" "<<numSub<<endl;
      ans+=numSub;

   }


   fout<<"Case #"<<t+1<<": "<<ans<<endl;
   }

fout.close();
return 0;
}







