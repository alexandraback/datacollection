#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <set>


using namespace std;

long long int T,N,A;
long long int S[101];
long long int minc = 1000000;
long long int currc = 0;

int main(){

  cin>>T;
  for(int i=0; i<T; i++){

    currc = 0;
    minc = 1000000;

    cin>>A>>N;
    for(int j=0; j<N; j++){
      cin>>S[j];
    }

    sort(S,S+N);

    /*
    for(int j=0; j<N; j++){
      cout<<S[j]<<" ";
    }
    cout<<endl;
    */

    //printf("N %d\n",N);

    bool run = true;

    for(int j=0; j<N && run; j++){
      if(A>S[j]){
	A += S[j];
      }
      else{
	int c = currc + (N-j);
	//cout<<c<<endl;
	if(c<minc){
	  minc = c;
	}
	while(A<=S[j]){
	  //cout<<A<<S[j]<<endl;
	  //cout.flush();
	  if(A-1 == 0){
	    run = false;
	    break;
	  }
	  else{
	    A += (A-1);
	    currc++;
	  }
	}
	//cout<<2<<endl;
	//cout.flush();
	A += S[j];
      }
    }
    
    if(currc<minc && run){
      minc = currc;
    }

    printf("Case #%d: %d\n",i+1,minc);
	  
  }

  return 0;
}
