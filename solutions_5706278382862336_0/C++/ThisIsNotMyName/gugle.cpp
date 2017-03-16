#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
int T;
cin >> T;
  for(int test=1;test<=T;test++){
    int P;
    int Q;
    int lol=scanf("%d/%d",&P,&Q);
    int sum=0;
    bool flag = true;
    bool flag2=true;
    while(flag){//nope
      if(Q%2!=0&&Q!=1){
	printf("Case #%d: impossible", test);
	cout << endl;
	flag=false;
	continue;
      }
      if(P-Q>=0){
	while(Q!=1){
	  Q/=2;
	  if(Q%2!=0&&Q!=1){
	    printf("Case #%d: impossible",test);
	    cout << endl;
	    flag = false;
	    flag2 = false;
	    break;
	  }
	}
	if(!flag2){
	  continue;
	}
	printf("Case #%d: %d",test,sum);
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