#include<cstdio>
#include<iostream>

using namespace std;
int main(){
	int t,n,s,k,i,j;
	scanf("%d",&t);
	int a[103];
	int smax,nsmax,res;
	for(int T=1;T<=t;++T){
		scanf("%d%d%d",&n,&s,&k);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		res=0;
		for(i=1;i<=n;++i){
			j=a[i]%3;
			switch(j){
				case 2:nsmax=a[i]/3+1;
					smax=nsmax+1;
					break;
				case 0:nsmax=a[i]/3;
					smax=nsmax+1;
					break;
				case 1:nsmax=a[i]/3+1;
					smax=nsmax;
					break;
			}
			if(a[i]==0)
				smax=0;
			if(nsmax>=k){
				res++;}
			else if(smax>=k){
				s--;res++;
			}
			else{
				;
			}
		}
		if(s<0){
			res+=s;
		}
		printf("Case #%d: %d\n",T,res);
	}
	return 0;
}