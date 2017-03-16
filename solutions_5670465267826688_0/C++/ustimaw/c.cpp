#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int L,X;
string s;
char table[999][999];

char mul(char a,char b){
  char la=tolower(a);
  char lb=tolower(b);
  return table[la][lb]^a^la^b^lb;
}

char pow(char c,int x){
  if(x==0)return 'e';
  char t=pow(c,x>>1);
  return mul(mul(t,t),(x&1)?c:'e');
}

bool solve(){
  char p='e';
  for(auto e:s){
    p=mul(p,e);
  }
  p=pow(p,X);
  if(p!='E')return false;
  string t;
  for(int i=0;i<8;i++){
    t+=s;
  }
  char h='e';
  int hx=-1;
  for(int i=0;i<t.size();i++){
    h=mul(h,t[i]);
    if(h=='i'){
      hx=i+1;
      break;
    }
  }
  if(hx<0)return false;
  char tc='e';
  int tx=-1;
  for(int i=0;i<L*t.size();i++){
    tc=mul(t[t.size()-1-i],tc);
    if(tc=='k'){
      tx=i+1;
      break;
    }
  }
  if(tx<0)return false;
  return hx+tx<1ULL*s.size()*X;
}

int main(){
  
  table['e']['e']='e';
  table['e']['i']='i';
  table['e']['j']='j';
  table['e']['k']='k';
  table['i']['e']='i';
  table['i']['i']='E';
  table['i']['j']='k';
  table['i']['k']='J';
  table['j']['e']='j';
  table['j']['i']='K';
  table['j']['j']='E';
  table['j']['k']='i';
  table['k']['e']='k';
  table['k']['i']='j';
  table['k']['j']='I';
  table['k']['k']='E';
  
  int T;
  cin>>T;
  for(int cn=1;cn<=T;cn++){
    cin>>L>>X;
    cin>>s;
    cout<<"Case #"<<cn<<": "<<(solve()?"YES":"NO")<<endl;
  }
}

