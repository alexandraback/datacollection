#include<iostream>
using namespace std;

bool cheak(long long int x,long long int r,long long int t){
  long long int d;
  

  d=(long long int)(2*r+1)*(x+1)+2*x*(x+1);//  cout<<x<<" "<<r<<" "<<t<<" "<<d<<endl;
  if(d<=t)
    return true;
  return false;
}

long long int ans(long long int r0,long long int t){
  if(!cheak(0,r0,t))
    return 0;
 long long int mid,l,r;
  l=0;r=t/r0;
  if(r>1000000000)
    r=1000000000;
  mid=(l+r)/2;
  
  while(r-l>1){
    if(cheak(mid,r0,t)){
      l=mid;
    }else{
      r=mid-1;
    }
    mid=(l+r)/2;
  }
  if(cheak(r,r0,t))
    return r+1;
  return l+1;
}

int main(){
  int T;
  cin>>T;
  for(int testcase=1;testcase<=T;testcase++){
    long long int r,t;
    cin>>r>>t;
    cout<<"Case #"<<testcase<<": "<<ans(r,t)<<endl;
    
  }
  return 0;
}
