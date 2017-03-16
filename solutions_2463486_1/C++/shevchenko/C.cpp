#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int c[10000001];

void preproc(){
	int i,f,r,ch;
	char str[20];
	for(i=1;i<=10000000;i++){
		ch=0;
		long long x=i;
		sprintf(str,"%lld",x);
		for(f=0,r=strlen(str)-1;f<r;f++,r--){
			if(str[f]!=str[r]){
				ch=1;
				break;
			}
		}

		if(ch==0){
			x*=x;
			sprintf(str,"%lld",x);
			for(f=0,r=strlen(str)-1;f<r;f++,r--){
				if(str[f]!=str[r]){
					ch=1;
					break;
				}
			}
		}

		if(ch==0) c[i]=1;
		else c[i]=0;
	}
}

int main(){
	freopen("C-large-1.in","r",stdin);
	freopen("output.txt","w",stdout);
	preproc();
	int i,j,t,cnt;
	long long s,e,ss,ee;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%lld%lld",&s,&e);

		long long l,u,md;

		ss=s; l=1; u=10000000;
		while(l<=u){
			md=(l+u)/2;
			if(md*md>s){
				if(md<ss) ss=md;
				u=md-1;
			}
			else if(md*md<s) l=md+1;
			else{ ss=md; break; }
		}

		ee=1; l=1; u=10000000;
		while(l<=u){
			md=(l+u)/2;
			if(md*md<e){
				if(md>ee) ee=md;
				l=md+1;
			}
			else if(md*md>e) u=md-1;
			else{ ee=md; break; }
		}

		cnt=0;
		for(j=ss;j<=ee;j++) cnt+=c[j];

		printf("Case #%d: %d\n",i,cnt);
	}
	return 0;
}