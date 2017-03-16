#include<iostream>
#include<set>
using namespace std;
main(){
  set<char>S,T;
  char c[256]={};
  string f[4],t[4];
  f[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  f[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  f[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  f[3] = "yeqz";

  t[0] = "our language is impossible to understand";
  t[1] = "there are twenty six factorial possibilities";
  t[2] = "so it is okay if you want to just give up";
  t[3] = "aozq";


  for(int i=0;i<4;i++){
    for(int j=0;j<f[i].size();j++){
      if (f[i][j] == ' ')continue;
      c[f[i][j]] = t[i][j];
      S.insert(f[i][j]);
      T.insert(t[i][j]);
    }
  }

  for(int i=0;i<26;i++){
    if (S.count('a'+i) == 0)cout <<"f "<< (char)('a'+i) << endl;
    if (T.count('a'+i) == 0)cout <<"t " << (char)('a'+i) << endl;
  }

  int te,tc=1;
  string in;
  cin>>te;
  getline(cin,in);
  while(te--){
    cout <<"Case #" << tc++ <<": ";
    getline(cin,in);
    for(int i=0;i<in.size();i++){
      if (islower(in[i]))cout << c[in[i]] ;
      else cout << in[i] ;
    }
    cout << endl;
  }
  return 0;
}
