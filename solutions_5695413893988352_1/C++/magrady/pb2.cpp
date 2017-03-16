#include<stdio.h>
#include<algorithm>
#include<string>
long long ans=1000000000000000001LL;
long long ans0=-1,ans1=-1;
void solve(char *s,long long a,char *t,long long b){
	// g = -1: s < t
	if(!*s){
		
		long long diff=a>b?a-b:b-a;
		//printf("%lld %lld %lld\n",a,b,diff);
		if(diff<ans){
			ans=diff;
			ans0=a;
			ans1=b;
		} else if(diff==ans&&ans0>a){
			ans0=a;
			ans1=b;
		} else if(diff==ans&&ans0==a&&ans1>b){
			ans1=b;
		}
		return;
	}
	int g=a<b?-1:a>b?1:0;
	//if(!g){
	if(*s=='?'&&*t=='?'){
		int d,e;
		d=0;
		e=0;
		solve(s+1,a*10+d,t+1,b*10+e);
		if(a>=b){
			d=0;
			e=1;
			solve(s+1,a*10+d,t+1,b*10+e);
			d=0;
			e=9;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
		if(a<=b){
			d=1;
			e=0;
			solve(s+1,a*10+d,t+1,b*10+e);
			d=9;
			e=0;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
	} else if(*s=='?'){
		int d,e=*t-'0';
		d=e;
		solve(s+1,a*10+d,t+1,b*10+e);
		if(a==b&&e!=0){
			d=e-1;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
		if(a==b&&e!=9){
			d=e+1;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
		if(a<b){
			d=9;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
		if(a>b){
			d=0;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
	} else if(*t=='?'){
		int d=*s-'0',e;
		e=d;
		solve(s+1,a*10+d,t+1,b*10+e);
		if(a==b&&d!=0){
			e=d-1;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
		if(a==b&&d!=9){
			e=d+1;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
		if(a<b){
			e=0;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
		if(a>b){
			e=9;
			solve(s+1,a*10+d,t+1,b*10+e);
		}
	} else {
		int d=*s-'0',e=*t-'0';
		solve(s+1,a*10+d,t+1,b*10+e);
	}
}
			
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		ans=1000000000000000001LL;
		ans0=-1,ans1=-1;
		int i,j,k;
		char s[1001],t[1001];
		scanf("%s%s",s,t);
		int n;
		for(n=0;s[n];n++);
		
		solve(s,0,t,0);
		char tt[10001];
		fprintf(stderr,"Case #%d: %s %s\n",T,s,t);
		sprintf(tt,"Case #%%d: %%0%dlld %%0%dlld\n",n,n);
		printf(tt,T,ans0,ans1);
	}
}
