#include<iostream>
#include<utility>
#include <algorithm>
using namespace std;

int h(string s){
  int res=0;
  while(0<s.size()){
    res*=10;
    res+=(s[0]-'0');
    s.erase(s.begin());
  }
  return res;
}
int g(string s, string t){
  return abs(h(s)-h(t));
}

void pp(pair<int,pair<string,string> > p){
  
  cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
  cout<<g(p.second.first, p.second.second)<<endl;
  cout<<h(p.second.first)<<" "<< h(p.second.second)<<endl;
}
pair<int,pair<string,string> > f(string s, string t,int fl, int d){
  if(s.size()<=d){
    return make_pair( g(s,t) , make_pair(s,t) );
  }

  if(fl==1){
    if(s[d]=='?')s[d]='9';
    if(t[d]=='?')t[d]='0';
    return f(s,t,fl,d+1);
  }
  if(fl==-1){
    if(s[d]=='?')s[d]='0';
    if(t[d]=='?')t[d]='9';
    return f(s,t,fl,d+1);
  }
  if(s[d]=='?'&&t[d]=='?'){
    pair<int,pair<string,string> > tmp1,tmp2,tmp3;
    s[d]='0';
    t[d]='0';
    tmp1=f(s,t,0,d+1);
    s[d]='1';
    t[d]='0';
    tmp2=f(s,t,-1,d+1);
    s[d]='0';
    t[d]='1';
    tmp3=f(s,t,1,d+1);
    if(tmp1<tmp2&&tmp1<tmp3)return tmp1;
    if(tmp2<tmp3)return tmp2;
    return tmp3;
  }
  if(s[d]=='?'){
    pair<int,pair<string,string> > tmp1,tmp2,tmp3;
    s[d]=t[d];
    tmp1=f(s,t,fl,d+1);

    s[d]=t[d]+1;
    fl=-1;
    if(s[d]>'9'){
      tmp2=tmp1;
    }else{
      tmp2=f(s,t,fl,d+1);
    }

    s[d]=t[d]-1;
    fl=1;
    if(s[d]<'0'){
      tmp3=tmp1;
    }else{
      tmp3=f(s,t,fl,d+1);
    }
    if(tmp1<tmp2&&tmp1<tmp3)return tmp1;
    if(tmp2<tmp3)return tmp2;
    return tmp3;
  }else if(t[d]=='?'){
    pair<int,pair<string,string> > tmp1,tmp2,tmp3;
    t[d]=s[d];
    tmp1=f(s,t,fl,d+1);

    t[d]=s[d]+1;
    fl=1;
    if(t[d]>'9'){
      tmp2=tmp1;
    }else{
      tmp2=f(s,t,fl,d+1);
    }

    t[d]=s[d]-1;
    fl=-1;
    if(t[d]>'9'){
      tmp3=tmp1;
    }else{
      tmp3=f(s,t,fl,d+1);
    }
    if(tmp1<tmp2&&tmp1<tmp3)return tmp1;
    if(tmp2<tmp3)return tmp2;
    return tmp3;
  }else{
    if(s[d]>t[d]){
      return f(s,t,-1,d+1);
    }else if(s[d]<t[d]){
      return f(s,t,1,d+1);
    }else{
      return f(s,t,0,d+1);

    }
  }
}

int main(void){
  int T;
  cin>>T;
  for(int Ti=1;Ti<=T;Ti++){
    string s,t;
    cin>>s>>t;
    int d = s.size();
    pair<int,pair<string,string> > res =f(s,t,0,0);
    cout<<"Case #"<<Ti<<": "<<res.second.first<<" "<<res.second.second<<endl;

  }
  return 0;
}

