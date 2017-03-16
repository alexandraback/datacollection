#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long int lli;
using namespace std;
lli f( lli C, lli D, lli V, vector<lli>& den ){
  /*
  cout<<endl;
  cout<<" C="<<C;
  cout<<" D="<<D;
  cout<<" V="<<V<<endl;
  for(int i = 0; i <den.size();i++){
    cout<<den[i]<<" ";
  }
  cout<<endl;
  */


  lli res=0;
  lli upr=0;
  for( lli i = 0;;i++){
    if(upr>=V)break;
    if(den.size()<=i||upr+1<den[i]){
      den.push_back(upr+1);
      //      cout<<"push_"<<upr+1<<endl;
      sort(den.begin(), den.end());
      res++;
    }
    upr+=den[i]*C;
  }
  return res;
  
  
}
int main(void){
  lli T;
  cin>>T;
  for( lli testcase = 1; testcase <= T;testcase++){
    
    lli C,D,V;
    vector<lli> den;
    cin>>C>>D>>V;
    //    while(D--){
    for(int i = 0; i<D;i++){
      lli tmp;
      cin>>tmp;
      den.push_back(tmp);
    }
    
    
    printf("Case #%lld: %lld\n", testcase, f(C,D,V,den) );
  }
  return 0;
}

  
