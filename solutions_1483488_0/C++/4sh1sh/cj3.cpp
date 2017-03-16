#include<iostream>
#include<cstdio>

using namespace std;
int isValid(int a,int b){
	int l=0;int pow10=1;
	while(a/pow10){
		l++;
		pow10*=10;
	}
	pow10/=10;
	int pow=10;
	for(int i=0;i<l-1;++i){
		int x=(a%pow)*pow10+(a/pow);
		pow*=10;
		pow10/=10;
		if(x==b)
			return 1;
	}
	return 0;
}
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(int T=1;T<=t;++T){
		scanf("%d %d",&a,&b);
		int res=0;
		for(int i=a;i<=b;++i)
			for( int j=i+1;j<=b;++j)
				res+=isValid(i,j);
		printf("Case #%d: %d\n",T,res);
	}
}