#include<cstdio>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
long long int f(long long int a,long long int b,long long int k){//less or equal
	if(k<0) return 0;
	if(a<0) return 0;
	if(b<0) return 0;
	if(a<=k && b<=k) return (a+1)*(b+1);
	long long int abase,bbase;
	for(abase=1;abase<=a;abase*=2);
	abase/=2;
	for(bbase=1;bbase<=b;bbase*=2);
	bbase/=2;
	if(abase==bbase){
		return f(abase-1,bbase-1,k)+f(a-abase,bbase-1,k)+f(abase-1,b-bbase,k)+f(a-abase,b-bbase,k-abase);
	}
	if(abase>bbase){
		return f(a-abase,b,k)+f(abase-1,b,k);
	}
	if(bbase>abase){
		return f(a,b-bbase,k)+f(a,bbase-1,k);
	}
	return 0;
}
int main(){
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt",stdout);
	int t;
	scanf("%d",&t);
	for(int _=1;_<=t;_++){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		printf("Case #%d: %lld\n",_,f(a-1,b-1,k-1));
	}	
}