#include<stdio.h>
#include<algorithm>
int a[1001],b[1001],u[1001];
void input(int n){
	int i,j,k;
	double in;
	for(i=0;i<n;i++){
		scanf("%lf",&in);
		a[i]=(int)(in*1000000+1e-4);
	}
	for(i=0;i<n;i++){
		scanf("%lf",&in);
		b[i]=(int)(in*1000000+1e-4);
	}
	std::sort(a,a+n);
	std::sort(b,b+n);
}
int solve2(int n){
	int i,j,k=0;
	for(i=j=n-1;i>=0;i--){
		if(b[j]<a[i])k++;
		else j--;
	}
	return k;
}
int solve1(int n){
	int i,j,k=0;
	for(i=j=n-1;i>=0;i--){
		if(a[j]<b[i])k++;
		else j--;
	}
	return n-k;
}
int main(){
	int T,TN;
	int N;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		scanf("%d",&N);
		input(N);
		printf("Case #%d: %d %d\n",T,solve1(N),solve2(N));
		;
	}
}
