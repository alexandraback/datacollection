#include<iostream>
using namespace std;


/*
  G  EIGHT
  H  THREE 
  W  TWO
  U  FOUR
  Z  ZERO
  X  SIX
  O  ONE
  S  SEVEN
  V  FIVE
  E  NINE
*/

int c[30];
int d[10];
void del(int n, string s){
  while(n--){
    for(int i = 0;i<s.size();i++){
      c[s[i]-'A']--;
    }
  }
}

void p(){
  for(int i = 0;i<10;i++){
    cout<<i<<"="<<d[i]<<", ";
  }
  cout<<endl;
}

void q(){
  for(int i = 0;i<26;i++){
    cout<<(char)(i+'A')<<"="<<c[i]<<", ";
  }
  cout<<endl;
}
int main(void){
  int T;
  cin>>T;
  for(int Ti=1;Ti<=T;Ti++){
    string s;
    cin>>s;
    for(int i = 0;i<30;i++)c[i]=0;
    for(int i = 0;i<10;i++)d[i]=0;
    while(0<s.size()){
      c[s[0]-'A']++;
      s.erase(s.begin());
    }

    if(c['G'-'A']>0){
      d[8]+=c['G'-'A'];
      del(c['G'-'A'],"EIGHT");
    }

    if(c['H'-'A']>0){
      d[3]+=c['H'-'A'];
      del(c['H'-'A'], "THREE ");
    }

    if(c['W'-'A']>0){
      d[2]+=c['W'-'A'];
      del(c['W'-'A'], "TWO");
    }

    if(c['U'-'A']>0){
      d[4]+=c['U'-'A'];
      del(c['U'-'A'], "FOUR");
    }

    if(c['Z'-'A']>0){
      d[0]+=c['Z'-'A'];
      del(c['Z'-'A'], "ZERO");
    }

    if(c['X'-'A']>0){
      d[6]+=c['X'-'A'];
      del(c['X'-'A'], "SIX");
    }

    if(c['O'-'A']>0){
      d[1]+=c['O'-'A'];
      del(c['O'-'A'], "ONE");
    }

    if(c['S'-'A']>0){
      d[7]+=c['S'-'A'];
      del(c['S'-'A'], "SEVEN");
    }
    
    if(c['V'-'A']>0){
      d[5]+=c['V'-'A'];
      del(c['V'-'A'], "FIVE");
    }
    
    if(c['E'-'A']>0){
      d[9]+=c['E'-'A'];
      del(c['E'-'A'], "NINE");
    }
    

    
    
    
    cout<<"Case #"<<Ti<<": ";
    for(int i=0;i<10;i++){
      for(int j = 0;j<d[i];j++){
        cout<<i;
      }
    }
    cout<<endl;
  }
  return 0;
}

