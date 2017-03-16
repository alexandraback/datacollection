#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){

//learn
ifstream inf;
ofstream fout;
vector<char> translations;
translations.resize(26);
for(int i=0;i<26;i++)
translations[i]='!';


string in,out;
for(int t=0;t<4;t++){
switch(t){
case 0:
in="ejp mysljylc kd kxveddknmc re jsicpdrysi";
out="our language is impossible to understand";

break;
case 1:
in="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
out="there are twenty six factorial possibilities";

break;
case 2:
in="de kr kd eoya kw aej tysr re ujdr lkgc jv";
out="so it is okay if you want to just give up";

break;

case 3:
in="yeqz ";
out="aozq ";
break;

}

for(int i=0;i<in.size();i++){
   if(in[i]==' ')
      continue;
   translations[in[i]-'a']=out[i];

   }
}

/*fout.open("t.txt");
for(int i=0;i<26;i++){
fout<<char('a'+i)<<" "<<translations[i]<<endl;
}

fout.close();*/


inf.open("a.in");
fout.open("out.txt");
if(!inf.good()){
cout<<"no"<<endl;
return 0;
}

int T;
inf>>T;
getline(inf,in);
for(int t=0;t<T;t++){
   getline(inf,in);
   for(int i=0;i<in.size();i++){
      if(in[i]==' ')
         continue;
      in[i]=translations[in[i]-'a'];
      }
   fout<<"Case #"<<t+1<<": "<<in<<endl;
   }

return 0;
}
