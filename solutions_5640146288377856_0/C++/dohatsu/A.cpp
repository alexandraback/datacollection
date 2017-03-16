#include<bits/stdc++.h>
using namespace std;
int R,C,W;

int calc(int a,int b){
  return a/b+(a%b==0?0:1);
}

int solve(){
  int ans=calc(C,W+W-1)*(R-1);
  //cout<<W+W-1<<' '<<C<<' '<<ans<<' ';
  if(C==W)return ans+W;
  if(C%W==0)return ans+C/W+W-1;
  else return ans+C/W+W;
}

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>R>>C>>W;
    cout<<"Case #"<<tc<<": "<<solve()<<endl;
  }
  return 0;
}
