#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

void solve2(string &st, int pos, string &ans){
  //~ cerr << pos << endl;
  if(pos < 0) return;
  
  string str1 = "";
  string str2 = "";
  
  int i;
  int mx = 0;
  int posmax = -1;
  for(i=0;i<=pos;i++) if(st[i] >= mx){
    mx = st[i];
    posmax = i;
  }
  //~ cerr << "p " << posmax << endl;
  
  
  str1 += st[posmax];
  
  for(i=posmax+1;i<=pos;i++){
    str2 += st[i];
  }
  
  
  solve2(st,posmax-1,ans);
  
  ans = str1 + ans + str2;
  
  //~ cerr << ans << endl;
}

void solve(){
  string st;
  cin >> st;
  
  string ans = "";
  
  solve2(st,st.size()-1,ans);
  
  cout << ans << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1 << ": ";
      solve();
    }
}
