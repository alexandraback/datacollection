#include<bits/stdc++.h>
using namespace std;
#define MAX 10005

string calc(string &a,string &b){
  char ar=a[0],br=b[0],ch;
  bool flg=(a.size()==b.size());
  string res="";
  if(ar==br){
    ch='1';
    flg^=true;
  }else if(ar=='1'){
    ch=br;
  }else if(br=='1'){
    ch=ar;
  }else if(ar=='i'&&br=='j'){
    ch='k';
  }else if(ar=='i'&&br=='k'){
    ch='j';flg^=true;
  }else if(ar=='j'&&br=='i'){
    ch='k';flg^=true;
  }else if(ar=='j'&&br=='k'){
    ch='i';
  }else if(ar=='k'&&br=='i'){
    ch='j';
  }else if(ar=='k'&&br=='j'){
    ch='i';flg^=true;
  }
  res.push_back(ch);
  if(!flg)res.push_back('-');
  return res;
}

string mem="X";
string f(char ch){
  mem[0]=ch;
  return mem;
}


string L[MAX],R[MAX];
string s,tmp;
int Tc,n,m;

bool solve(){
  string X;
  L[0]=f(s[0]);
  for(int i=1;i<n;i++){
    L[i]=calc(L[i-1],X=f(s[i]));
  }
  
  R[n-1]=f(s[n-1]);
  for(int i=n-2;i>=0;i--){
    R[i]=calc(X=f(s[i]),R[i+1]);
  }
  assert(L[n-1]==R[0]);
  if(R[0]!="1-")return false;
 
  
  int si=n,ti=-1;
  for(int i=0;i<n;i++){
    if(L[i][0]=='i'){
      si=i;
      break;
    }
  }
  for(int i=n-1;i>=0;i--){
    if(R[i][0]=='k'){
      ti=i;
      break;
    }
  }

  if(si<ti)return true;

  
  return false;
}

int main(){
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>n>>m>>tmp;
    s="";
    for(int i=0;i<m;i++)s=s+tmp;
    n=s.size();
    cout<<"Case #"<<tc<<": "<<(solve()?"YES":"NO")<<endl;
  }
  return 0;
}

/*
= = =
abcdef

= =        =
abcdef abcdef abcdef abcdef
 */
