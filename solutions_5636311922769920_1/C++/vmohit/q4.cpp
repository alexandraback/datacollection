#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int ceil(int a,int b){
  int y=a/b;
  if(a%b==0){
    return y;
  }
  else{
    return y+1;
  }
}

int main(){
  int Te;
  cin>>Te;
  for(int te=1;te<=Te;te++){

    ll k,c,s;
    cin>>k>>c>>s;
    cout<<"Case #"<<te<<":";
    if(s<ceil(k,c)){
      cout<<" IMPOSSIBLE\n";
    }
    else{
      vector<int> pos(ceil(k,c)*c+1,1);
      for(int i=0;i<=k;i++)pos[i]=i;
      vector<ll> pows(c,1);
      for(int i=1;i<c;i++)pows[i]=k*pows[i-1];
      int z=1;
      for(int i=0;i<ceil(k,c);i++){
        ll v=0;
        for(int j=c-1;j>=0;z++,j-- ){
          v=v+((pos[z]-1)*pows[j]);
        }
        v=v+1;
        cout<<" "<<v;
      }
      cout<<endl;
    }

  }


  return 0;

}
