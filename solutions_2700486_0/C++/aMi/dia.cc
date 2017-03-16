#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


double c(int in,int r){
  double y = 1;
  if(in*2>r){
    in = r-in;
  }
  for (int i = 0;i<in;i++){
    y *= r-i;
  }
  for (int i = 1;i<=in;i++){
    y /= i;
  }
  return y;
}

double proba(int T,int X,int Y){
  int inner = abs(X)+abs(Y);

  if(inner%2 ==1)
    return 0;

  if(T==0){
    return 0;
  }

  inner = inner/2+1;

  int N1 = (2*inner) * (2*inner-1)/2;

  if (T>=N1){
    return 1;
  }
  
  if(abs(X)==0){
    return 0;
  }

  int N2 = (2*inner-2) * (2*inner-3)/2;

  if(T <= N2){
    return 0;
  }
  
  int R = T-N2;

  if(R > abs(Y)+inner*2-2){
    return 1;
  }

  if(R <= abs(Y)){
    return 0;
  }

  double d = 0;

  //eliminate where i cases are on the other side.
  for(int i=R-abs(Y); i<=R;i++){
    d += double(1)/(1<<R)*c(i,R);
  }

  return 1-d;

}

int main(){

	int i_cases;
	int N_cases;

	cin>>N_cases;


	for(i_cases=0;i_cases<N_cases;i_cases++){

	  int T,X,Y;

	  cin>>T>>X>>Y;

	  double d = proba(T,X,Y);

	  printf("Case #%d: %f\n",i_cases+1,d);
	  //cout<<"Case #"<<i_cases+1<<": "<<d<<endl;

	}
	return 0;

}
