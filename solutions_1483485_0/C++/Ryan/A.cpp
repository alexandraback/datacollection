#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void pre_calc();
void map(int in,int out);
const int I=4,L=256;
char mapping[L];

int main(){
  pre_calc();
  int t;
  string s;
  cin>>t; getline(cin,s);
  for(int i=0;i<t;i++){
    getline(cin,s);
    for(int j=0;j<s.size();j++)
      s[j]=mapping[s[j]];
    cout<<"Case #"<<i+1<<": "<<s<<'\n';
  }
}

const string in[I] ={"y qee","ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
const string out[I]={"a zoo","our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};

void pre_calc(){
  for(int i=0;i<I;i++)
    for(int s=0;s<in[i].size();s++)
      map(in[i][s],out[i][s]);
  map('z','q');
  for(char c='a';c<='z';c++)
    if(mapping[c]==0)
      cout<<c<<" is bad\n";
}

void map(int in,int out){
  assert(mapping[in]==0 || mapping[in]==out);
  mapping[in]=out;
}
