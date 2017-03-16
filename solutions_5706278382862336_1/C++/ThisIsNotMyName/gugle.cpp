#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

long long ggt(long long a, long long b){
  if(b==0){
    return a;
  }
  return ggt(b,a%b);
}

int main(){
long long T;
cin >> T;
  for(long long test=1;test<=T;test++){
    long long P;
    long long Q;
    long long lol=scanf("%lld/%lld",&P,&Q);
    long long sum=0;
    bool flag = true;
    bool flag2=true;
    while(flag){
      if(Q%2!=0){
	long long S = ggt(P,Q);
	P/=S;
	Q/=S;
      }
      if(Q%2!=0&&Q!=1){
	printf("Case #%lld: impossible", test);
	cout << endl;
	flag=false;
	continue;
      }
      if(P-Q>=0){
	long long S =ggt(P,Q);
	P/=S;
	Q/=S;
	while(Q!=1){
	  Q/=2;
	  if(Q%2!=0&&Q!=1){
	    printf("Case #%lld: impossible",test);
	    cout << endl;
	    flag = false;
	    flag2 = false;
	    break;
	  }
	}
	if(!flag2){
	  continue;
	}
	printf("Case #%lld: %lld",test,sum);
	cout << endl;
	flag=false;
	continue;
      }
      sum+=1;
      Q/=2;
    }
  }
return 0;
}