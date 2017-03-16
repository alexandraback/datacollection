#include<cstdio>
#include<cstring>

int a[20];
int t[2000001];
int n;

void print(int mask){
	bool first=true;
	for(int i=0;i<n;++i){
		if((mask>>i)&1){
			if(!first)printf(" ");
			printf("%d",a[i]);
			first=false;
		}
	}
	puts("");
}

void caso(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
	}
	memset(t,0,sizeof(t));
	for(int i=0;i<(1<<n);++i){
		int s=0;
		for(int j=0;j<n;++j){
			if((i>>j)&1)s+=a[j];
		}
		if(t[s]){
			print(i);
			print(t[s]);
			return;	
		}
		else t[s]=i;
	}
	puts("impossible");
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		printf("Case #%d:\n",i);
		caso();
	}
}
