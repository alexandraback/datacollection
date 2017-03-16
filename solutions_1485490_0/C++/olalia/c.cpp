#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>




using namespace std;


typedef long long ll;

int main(){
  int T; cin>>T;
  for (int tc=1;tc<=T;tc++){
    int N,M; cin>>N>>M;
    vector<ll> a, b;
    a=vector<ll>(N,0);
    b=vector<ll>(M,0);
    vector<int> A,B;
    A=vector<int>(N,0);
    B=vector<int>(M,0);
    for (int i=0;i<N;i++){
      cin>>a[i];
      cin>>A[i];
    }
    for (int i=0;i<M;i++){
      cin>>b[i];
      cin>>B[i];
    }
    ll svar=0;
    ll svar2=0;
    ll svar3=0;
    ll svar4=0;
    bool ja=false;
    if (N==3){
      if (A[1]==A[2]){
	a[1]+=a[2];
	N=2;
	if (A[0]==A[1]){
	  a[0]+=a[1];
	  N=1;
	}
      }
      else {
	if (A[0]==A[1]){
	  a[0]+=a[1];
	  a[1]=a[2];
	  A[1]=A[2];
	  N=2;
	}
	else {
	  if (A[0]==A[2]){
	    ja=true;
	  }
	}
      }
    }
	       


    if (N==1){
      for (int i=0;i<M;++i){
	if (B[i]==A[0]) svar+=b[i];
      
      }
      
      if (a[0]<svar){
	svar=a[0];
      }
      
    }
    if (N==2){
        
      for (int i=-1;i<M;++i){
	if (i>=0){
	  if (A[0]==B[i]) svar2+=b[i];
	  if (svar2>a[0]) svar2=a[0];
	}
	svar3=0;
	for (int j=i+1;j<M;++j){
	  if (A[1]==B[j]) svar3+=b[j];
	  if (svar3>a[1]) svar3=a[1];
	}
	if (svar<svar2+svar3) svar=svar2+svar3;
      }
    }
    if (N==3){
      for (int I=0;I<=M;I++){
	for (int J=I;J<=M;J++){
	  svar2=0;
	  svar3=0;
	  svar4=0;
	  for (int i=0;i<I;i++){
	    if (A[0]==B[i]) svar2+=b[i];
	  }
	  if (a[0]<svar2) svar2=a[0];
	  for (int i=I;i<J;i++){
	    if (A[1]==B[i]) svar3+=b[i];
	  }
	  if (a[1]<svar3) svar3=a[1];
	  for (int i=J;i<M;i++){
	    if (A[2]==B[i]) svar4+=b[i];
	  }
	  if (svar4>a[2]) svar4=a[2];
	  if (svar<svar2+svar3+svar4) svar=svar2+svar3+svar4;
	}
      }
    }
    if (ja){
      a[0]+=a[2];
      N=1;
      svar2=0;
      for (int i=0;i<M;i++){
	if (A[0]==B[i]) svar2+=b[i];
      }
      if (a[0]<svar2){
	svar2=a[0];
      }
      if (svar<svar2){
	svar=svar2;
      }
    }


    cout<<"Case #"<<tc<<": "<<svar<<endl;

  }


  return 0;
}
