#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

using namespace std; 

int main(){
  freopen("B-small-attempt0.in","r",stdin);
  long T, S,N, p;

  cin>>T; 
  vector<int> googler; 

  for (int iT=1;iT<=T;iT++){
    cin>>N>>S>>p;
    googler.resize(N);
    for (int i=0;i<N;i++) cin>>googler[i];


    long sum=0;
    long icount =0;

    for (int i=0;i<N; i++){
      int a= googler[i];
      if (a<3*p-4)  continue;
      if (a>3*p-3) {
	sum+=1;
      } 

      if (a==3*p-4 ||( a== 3*p-3 && p>=2)){
	icount++;
      }
      
    }


    if (S<=icount){
      sum += S; 
    }

    if (S>icount) sum+=icount;


    cout<<"Case #"<<iT<<": "<<sum<<endl;

  }
  return 0 ;
}
