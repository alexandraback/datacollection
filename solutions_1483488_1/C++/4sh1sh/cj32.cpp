#include<iostream>
#include<cstdio>
#include<set>

using namespace std;
int isValid(int a,int b){
	int l=0;int pow10=1;
	while(a/pow10){
		l++;
		pow10*=10;
	}
	pow10/=10;
	int pow=10;
	set<int> S;
	for(int i=0;i<l-1;++i){
		int x=(a%pow)*pow10+(a/pow);
		pow*=10;
		pow10/=10;
		if(x<=b&&x>a){
			S.insert(x);
		}
	}
	return S.size();
}
int main(){
	int t,a,b;
	scanf("%d",&t);
	for(int T=1;T<=t;++T){
		scanf("%d %d",&a,&b);
		int res=0;
		for(int i=a;i<=b;++i)
				res+=isValid(i,b);
		printf("Case #%d: %d\n",T,res);
	}
}