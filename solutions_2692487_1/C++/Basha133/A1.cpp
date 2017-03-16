#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  long long int i,j,k,l,m,n,o,p,t,r,s;
  long long int res;
  vector<long long int> pole;
  //printf("Hello World!\n");
  
  scanf("%lld",&t);
  
  for(l=0;l<t;l++){
    scanf("%lld",&m);
    scanf("%lld",&n);
    
    pole.clear();
    
    for(i=0;i<n;i++){
      scanf("%lld",&p);
      pole.push_back(p);
    }
    
    k=m;
    
    sort(pole.begin(),pole.end());
    
    for(i=0;i<n;i++){
      if(pole[i]<k){
	k+=pole[i];
	//printf("k: %d %d\n",k,pole[i]);
      }else{
	break;
      }
    }
    
    //printf("i: %d n: %d\n",i,n);
    
    if(i<n){
      if(k<=1){
	printf("Case #%lld: %lld\n",l+1,n-i);
      }else{
	res=n-i;
	p=k;
	r=0;
	for(j=i;j<n;j++){
	  for(;p<=pole[j];r++){
	    p=2*p-1;
	  }
	  p+=pole[j];
	  if((r+n-j-1)<res){
	    res=(r+n-j-1);
	  }
	}
	printf("Case #%lld: %lld\n",l+1,res);
      }
    }else{
      printf("Case #%lld: 0\n",l+1);
    }
    
  }
  
  return 0;
}