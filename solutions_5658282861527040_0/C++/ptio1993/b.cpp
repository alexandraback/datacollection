#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

int comp(int A,int B){
	int res[20];for(int i=0;i<20;++i){res[i]=0;}
	if(A%2==1 && B%2==1)res[0]=1;
	int i=1;
	while(A>0 && B>0){
		A/=2;B/=2;
		if(A%2==1 && B%2==1)res[i]=1;
		++i;
	}
	int R=0;i=1;
	for(int j=0;j<20;++j){
		R+=res[j]*i;
		i*=2;
	}
	return R;
}

int main(){
	int TC;
	cin>>TC;
	for(int T=1;T<=TC;++T){
		printf("Case #%d:",T);
		int A,B,K;int count=0;
		cin>>A>>B>>K;
		for(int i=0;i<A;++i){
			for(int j=0;j<B;++j){
				int c=comp(i,j);
				if (c<K)++count;
			}
		}
		printf(" %d\n",count);
	}
}