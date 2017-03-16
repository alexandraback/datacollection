#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int debug = 0;

void product(char x, char xsign, char y, char ysign, char &ret, char &retsign){
  retsign = (xsign != ysign);
  if(x=='1') {ret = y; return;}
  else if(y=='1') {ret = x; return;}
  else if(x==y){
    ret = '1';
    retsign = !retsign;
    return;
  }
  else if(x=='i'){
    if(y=='j'){
      ret = 'k';
    }
    else if(y=='k'){
      retsign = !retsign;
      ret = 'j';
    }
  }
  else if(x=='j'){
    if(y=='k'){
      ret = 'i';
    }
    else if(y=='i'){
      retsign = !retsign;
      ret = 'k';
    }
  }
  else if(x=='k'){
    if(y=='i'){
      ret = 'j';
    }
    else if(y=='j'){
      retsign = !retsign;
      ret = 'i';
    }
  }
}

int canmake(char tomake, const string &makefrom){
  char curproduct = '1';
  char cursign = 0;
  for(long i=0; i<makefrom.size(); i++){
    if(debug) cout<<(cursign?'-':' ')<<curproduct<<'*'<<makefrom[i]<<endl;
    product(curproduct, cursign, makefrom[i], 0, curproduct, cursign);
    if(curproduct == tomake && cursign == 0){
      if(debug) cout<<"Made "<<tomake<<" from "<<makefrom.substr(0,i+1)<<endl;
      return i+1;
    }
  }
  return -1;
}

int productis1(const string&makefrom){
  char curproduct = '1';
  char cursign = 0;
  for(long i=0; i<makefrom.size(); i++){
    if(debug) cout<<(cursign?'-':' ')<<curproduct<<'*'<<makefrom[i]<<endl;
    product(curproduct, cursign, makefrom[i], 0, curproduct, cursign);
  }
  return curproduct=='1'&&cursign==0;
}

int main(int argc, char**argv){
  int T;
  cin>>T;
  for(int i=1; i<=T; i++){
    cout<<"Case #"<<i<<": ";
    long long length, repeat;
    cin>>length>>repeat;
    if(debug) cout<<"length"<<length<<"repeat"<<repeat<<endl;
    repeat = repeat%12;
    string quats;
    cin>>quats;
    if(debug) cout<<"Length quats:"<<quats.length()<<endl;
    string newquats;
    for(int i=0; i<repeat; i++){
      newquats+=quats;
    }
    quats = newquats;
    int ipos = canmake('i', quats);
    if(ipos==-1) cout<<"NO"<<endl;
    else{
      int jpos = canmake('j', quats.substr(ipos));
      if(jpos==-1) cout<<"NO"<<endl;
      else{
	int kpos = canmake('k', quats.substr(ipos+jpos));
	if(kpos==-1||!productis1(quats.substr(ipos+jpos+kpos))) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
      }
      
    }
  }
}
