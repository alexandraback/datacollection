#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int length(int number){
  int counter =0 ;
  while(number != 0){ 
    counter ++;
    number /= 10;
  }
  return counter;
}

int main(){
  int tc, A, B ;
  long long int ans ;
  int len, temp;
  map<int,int> M;
  vector<int>V ;
  scanf("%d",&tc);
  for(int ks=0; ks<tc; ks++){
    ans = 0;
    scanf("%d%d",&A,&B);
    
    for(int num=A+1; num<=B; num++){
      V.clear();
      len = length(num);  
      temp = num;
      while(temp != 0){
	V.push_back(temp%10);
	temp /= 10;
      }	
      for(int i=0; i<len/2; i++){
	temp = V[i]; 
	V[i] = V[len-1-i];
	V[len-1-i] = temp;
      }
      M.clear();
      for(int start = 1; start < len;  start++){
	temp = 0;
	if(V[start] != 0){
	  for(int j=0; j<len ; j++){
	    temp = temp*10 + V[(start+j)%len] ; 
	  }
	  if(temp < num && temp >= A && M[temp]==0){
	    M[temp] = 1;
	    ans ++;
	 //   cout << num << " " << temp << endl;
	  }
	}
      }
    }
    printf("Case #%d: %lld\n",ks+1, ans);
  }
  return 0;
}
