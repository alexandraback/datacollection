#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>



using namespace std;

int main(){
  int T; cin>>T;
  for (int tc=1;tc<=T;tc++){
    double D;
    int N, A; cin>>D; cin>>N>>A;
    vector<double> t=vector<double>(N,0);
    vector<double> x=t;
    for (int i=0;i<N;i++){
      cin>>t[i]>>x[i];
    }
    vector<double> a=vector<double>(A,0);
    for (int i=0;i<A;++i){
      cin>>a[i];
    }
    int c=0;
    while (x[c]<D){
      c++;
    }
    t[c]=t[c-1]+(t[c]-t[c-1])*(D-x[c-1])/(x[c]-x[c-1]);
    x[c]=D;
    N=c+1;
    
    cout<<"Case #"<<tc<<": "<<endl;
    for (int i=0;i<A;i++){
      vector<double> t0=vector<double>(N,0);
      for (int j=0;j<N;j++){
	t0[j]=t[j]-sqrt(2*x[j]/a[i]);
      }
      double t00=0;
      for (int j=0;j<N;j++){
	if (t00<t0[j]) t00=t0[j];
      }
      //cout<<t00<<endl;
      double tt=t00+sqrt(2*D/a[i]);
      cout<<setprecision(13)<<tt<<endl;
    }
	
  }


  return 0;
}
