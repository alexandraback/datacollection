#include<bits/stdc++.h>
using namespace std;
int x,r,c,Tc;

bool solve(){
  int s=r*c;
  if(c<r)swap(c,r);

  if(x==1){
    return true;
  }else if(x==2){
    return (s%2==0);
  }else if(x==3){
    if(s%3==0&&s!=3)return true;
    else return false;
  }else if(x==4){
    if(r<=2)return false;
    else if(r==3&&c==3)return false;
    else return true;
  }
}

int main(){
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>x>>r>>c;
    cout<<"Case #"<<tc<<": "<<(solve()?"GABRIEL":"RICHARD")<<endl;
  }
  return 0;
}
