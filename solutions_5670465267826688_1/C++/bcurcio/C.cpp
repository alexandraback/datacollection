#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

vector<vector<int> > mat;


int val(char c){
  if (c=='i') return 2;
  if (c=='j') return 3;
  if (c=='k') return 4;
  return 1;
}

int mult(int a,int b){
  int f = 1;
  if(a<0 || b<0) f = -1;
  if(a<0 && b<0) f = 1;
  
  return mat[abs(a)][abs(b)]*f;
}

void solve(){
  long long X,L;
  
  cin >> L >> X;
  
  string str;
  cin >> str;
  
  if(X<=10){
    string all;
    
    int i;
    for(i=0;i<X;i++) all+=str;
    
    
    int pt1 = 0;
    int cur = val(all[pt1]);
    while(cur!=2){
      pt1++;
      if(pt1==(int)all.size()){
        cout << "NO" << endl;
        return;
      }
      
      int v = val(all[pt1]);
      
      cur = mult(cur,v);
    }
    
    
    int pt2 = all.size()-1;
    
    cur = val(all[pt2]);
    
    while(cur!=4){
      pt2--;
      if(pt2==pt1){
        cout << "NO" << endl;
        return;
      }
      
      int v = val(all[pt2]);
      
      cur = mult(v,cur);
    }
    
    
    cur = 1;
    
    
    for(i=pt1+1;i<pt2;i++){
      cur = mult(cur,val(all[i]));
    }
    
    if(cur==3) cout<<"YES" <<endl;
    else cout << "NO" << endl;
    
    
  }else{
    
    string all;
    
    int i;
    for(i=0;i<10;i++) all+=str;
    
    
    int pt1 = 0;
    int cur = val(all[pt1]);
    while(cur!=2){
      pt1++;
      if(pt1==(int)all.size()){
        cout << "NO" << endl;
        return;
      }
      
      int v = val(all[pt1]);
      
      cur = mult(cur,v);
    }
    
    
    int pt2 = all.size()-1;
    cur = val(all[pt2]);
    
    while(cur!=4){
      pt2--;
      if(pt2==-1){
        cout << "NO" << endl;
        return;
      }

      int v = val(all[pt2]);      
      cur = mult(v,cur);
    }
    
    
    int cnt1 = pt1 / L;
    pt1 %= L;
    int cnt2 = (all.size() - pt2) / L;
    pt2 %= L;
    
    
    if(cnt1+cnt2 >= X){
      cout << "NO"<<endl;
      return;
    }
    
    if(cnt1+cnt2 == X-1){
      cur = 1;
      
      if(pt2==0) pt2 = all.size();
      
      for(i=pt1+1;i<pt2;i++){
        cur = mult(cur,val(all[i]));
      }
      
      if(cur==3) cout<<"YES" <<endl;
      else cout << "NO" << endl;
      
    }
    
    if(cnt1+cnt2 <= X-2){
      
      int exc = X- cnt1 - cnt2;
      exc = exc - 1;
      
      if(pt2!=0) exc = exc - 1;
      
      
      exc = exc%4;
      
      cur = 1;
      for(i=0;i<L;i++) cur = mult(cur,val(all[i]));
      
      if(cur!=1){
        if(exc==2) cur = -1; 
        if(exc==3) cur = -cur; 
        if(exc==0) cur = 1; 
      }
      
      int cur2 = 1;
      for(i=pt1+1;i<L;i++) cur2 = mult(cur2,val(all[i]));
      
      int cur3 = 1;
      for(i=0;i<pt2;i++) cur3 = mult(cur3,val(all[i]));
      
      cur = mult(cur2,cur);
      cur = mult(cur,cur3);
      
      
      if(cur==3) cout<<"YES" <<endl;
      else cout << "NO" << endl;
      
    }
    
    
    
    
    
  }
  
}


int main(){
  mat=vector<vector<int> >(5,vector<int>(5));
  mat[1][1] = 1;
  mat[1][2] = 2;
  mat[1][3] = 3;
  mat[1][4] = 4;
  mat[2][1] = 2;
  mat[2][2] = -1;
  mat[2][3] = 4;
  mat[2][4] = -3;
  mat[3][1] = 3;
  mat[3][2] = -4;
  mat[3][3] = -1;
  mat[3][4] = 2;
  mat[4][1] = 4;
  mat[4][2] = 3;
  mat[4][3] = -2;
  mat[4][4] = -1;
  
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<< i+1 << ": ";
      solve();
    }
}
