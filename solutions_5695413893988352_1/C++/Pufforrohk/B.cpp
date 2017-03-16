#include<iostream>
#include <map>
#include <vector>
#include <stack>
#include <cassert>
#include <climits>
#include <cstdio>
using namespace std;
#define lint unsigned long long int

string rep(string& a, char c){
  string s = a;
  for(int i=0;i<s.size();i++)
    if(s[i]=='?')
      s[i]=c;
  return s;
}

string top(string& a){
  return rep(a,'9');
}

string bot(string& a){
  return rep(a,'0');
}

char grande(char gr, char pi){
  if(gr!='?')
    return gr;
  if(pi=='?')
    return '1';
  if(pi=='9')
    return '9';
  return pi+1;
}

char piccolo(char gr, char pi){
  if(pi!='?')
    return pi;  
  if(gr=='?')
    return '0';
  if(gr=='0')
    return '0';
  return gr-1;
}


lint delta(string& a, string& b){
  lint i = stoull(a);
  lint j = stoull(b);
  if(i<j)
    return j-i;
  else
    return i-j;
}

tuple<lint,string,string> f(string a, string b){
  if(a.size()==0){
    return make_tuple(0,"","");
  }
  tuple<lint,string,string> best = make_tuple(ULLONG_MAX,"","");
  string na = a.substr(1);
  string nb = b.substr(1);
  if(a[0]=='?' || b[0]=='?' || a[0]==b[0]){
    auto t= f(na,nb);
    char c= a[0];
    if(c=='?'){
      c=b[0];
    }
    if(c=='?'){
      c='0';
    }
    best = make_tuple(get<0>(t), c + get<1>(t),c+get<2>(t));
  }
  

  string Agr = grande(a[0],b[0]) + bot(na);
  string Bpi = piccolo(a[0],b[0]) + top(nb);

  string Api = piccolo(b[0],a[0]) + top(na);
  string Bgr = grande(b[0],a[0]) + bot(nb);

  lint diff = delta(Agr,Bpi);
  if(diff < get<0>(best) || (diff==get<0>(best) && Agr < get<1>(best) ) || (diff==get<0>(best) && Agr == get<1>(best) && Bpi < get<1>(best) )){
    best = make_tuple(diff,Agr,Bpi);
  }


  diff = delta(Api,Bgr);
  if(diff < get<0>(best) || (diff==get<0>(best) && Api < get<1>(best) ) || (diff==get<0>(best) && Api == get<1>(best) && Bgr < get<1>(best) )){
    best = make_tuple(diff,Api,Bgr);
  }

  return best;
}

void solve(string a, string b){
  auto t= f(a,b);
  cout<<get<1>(t)<<" "<<get<2>(t)<<endl;
}

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    // Leggi
    string a,b;
    cin>>a>>b;
    cout<<"Case #"<<i+1<<": ";
    solve(a,b);
  }

  return 0;
}
