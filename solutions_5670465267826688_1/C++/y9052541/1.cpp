#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100005
#define Long long long
#define For(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
char s[N];
void Trans(int &a,int b){
//	printf("Trans %d %d\n",a,b);
	int va=(a&4);
	int vb=(b&4); int val=va^vb;
	if(a&4) a-=4;
	if(b&4) b-=4;
	if(a==0){
		a=b;
		a^=val; return;
	}
	if(a==1){
		if(b==0) a=1|0;
		if(b==1) a=0|4;
		if(b==2) a=3|0;
		if(b==3) a=2|4;
		a^=val; return;
	}
	if(a==2){
		if(b==0) a=2|0;
		if(b==1) a=3|4;
		if(b==2) a=0|4;
		if(b==3) a=1|0;
		a^=val; return;
	}
	if(a==3){
		if(b==0) a=3|0;
		if(b==1) a=2|0;
		if(b==2) a=1|4;
		if(b==3) a=0|4;
		a^=val; return;
	}
}
int main(){
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int Q_Q,Case=0; scanf("%d",&Q_Q);
	while(Q_Q--){
		int L; Long K;scanf("%d%I64d",&L,&K);
		scanf("%s",s+1);
		
		int now=0,flag0=0,flag1=0;
		For(t,1,min(K,100LL)){
			For(i,1,L){
				Trans(now,s[i]-'i'+1);
				if(now==1) flag0=1;
				if(now==3) flag1|=flag0;
				
//			printf("%d -> ",now); if(now&4) printf("-");
//			if(now%4==1) printf("i");else
//			if(now%4==2) printf("j");else
//			if(now%4==3) 	printf("k");else printf("1");
//			printf("\n");
			
			}
		}
		
		int ret=0;
		now=0;
		For(i,1,L){
			Trans(now,s[i]-'i'+1);
			
		}
		
		while(K){
			if(K&1) Trans(ret,now);
			K>>=1; Trans(now,now);
		}
		
		printf("Case #%d: ",++Case);
		if(ret==4 && flag0 && flag1) printf("YES\n");
		else printf("NO\n");
	}
}
