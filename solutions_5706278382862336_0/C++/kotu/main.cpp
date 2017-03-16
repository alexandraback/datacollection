#include <cstdio>
#include <iostream>
using namespace std;
int T;
long long int table[41];
long long int  gcd(long long int a,long long int b){
  return a==0? b: gcd(b%a,a);
}
long long int  lsm(long long int a,long long int b){
  return a*b/gcd(a,b);
}
int main(){
  scanf("%d",&T);
  table[0]=1;
  for(int i=1;i<=40;++i){
    table[i]=table[i-1]*2;
    //    printf("%lld\n",table[i]);
  }
  for(int cnt=0;cnt<T;++cnt){
    int K,M;
    long long int P,Q;
    int ans=-1;
    bool div=false;
    scanf("%lld/%lld",&P,&Q);
	long long int S=gcd(P,Q);
	Q/=S;
	P/=S;
       
    
    for(int i=1;i<=40;++i){
      long long  int L=lsm(Q,table[i]);
      long long  int A=P*L/Q,B=1*L/table[i];
      if( A>= B){

	if(ans==-1){
	  ans=i;
	  break;
	}
	if(A==B){
	  div=true;
	  break;
	}
	A-=B;
	Q=L;
	P=A;
	long long int S=gcd(P,Q);
	Q/=S;
	P/=S;


      }
      }
    div=false;
    for(int i=1;i<=40;++i){
      if(table[i]==Q)div=true;
    }
      
    if(ans==-1||div==false){
      printf("Case #%d: impossible\n",cnt+1);
    }else{
      printf("Case #%d: %d\n",cnt+1,ans);
    }
  }

  return 0;
}
