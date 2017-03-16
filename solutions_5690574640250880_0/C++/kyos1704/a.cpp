#include<iomanip>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int r,c,m;bool rev;
vector<string> ans;
vector<int> l;
void init(){
  ans.clear();
  l.clear();
  return ;
}
void input(){
  cin>>r>>c>>m;
}
void make(){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(j<l[i]){
        if(rev){
          ans[j][i]='.';
        }else{
          ans[i][j]='.';
        }
      }
    }
  }
  ans[0][0]='c';
}
bool req(int h,int n,int u){
  if(u==0)return true;
  if(u<0)return false;
  if(h==0)return false;
  if(n==r)return false;
  if(h*(r-n)<u)return false;
  for(int i=2;i<=h;i++){
    l[n]=i;
    if(req(i,n+1,u-i)){
      return true;
    }
  }
  l[n]=0;
  return false;
}
void solve(){
  ans.resize(r);
  for(int i=0;i<ans.size();i++){
    ans[i]="";
    for(int j=0;j<c;j++){
      ans[i]+="*";
    }
  }
  rev=(r>c);
  if(rev){
    swap(r,c);
  }
  int un = r*c - m;
  l=vector<int>(r,0);
  if(r==1){
    l[0]=un;
    make();
    return; 
  }
  if(un==1){
    l[0]=1;
    make();
    return;
  }
  for(int i=2;i<=c;i++){
    l[0]=i;l[1]=i;
    if(req(i,2,un-2*(i))){
      make();
      return;
    }
  }
  cerr<<r<<" "<<c<<" "<<un<<endl;
  ans = {"Impossible"};
}

void print(int n){
  cout<<"Case #"<<n<<":"<<endl;
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
}


int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    init();
    input();
    solve();
    print(i+1);
  }
}
