#include <stdio.h>
#include <string.h>

using namespace std;

int t;
int K,L,S,mx;
char keys[200],target[200],w[200];
int F[200];
double mem[200][200];

int prekryv(){
	for(int i=1;i<L;++i){
		if (!strncmp(target,target+i,L-i)) return L-i;
	}
	return 0;
}

int possible(){
	for(int i=0;i<L;++i){
		int ok=0;
		for(int j=0;j<K;++j){
			if (keys[j]==target[i]){
				ok=1;
				break;
			}
		}
		if (!ok) return 0;
	}
	return 1;
}

void buildF(){
	F[0]=F[1]=0;
	for(int i=2;i<=L;++i){
		int j=F[i-1];
		for(;;){
			if (target[j]==target[i-1]){
				F[i]=j+1;
				break;
			}
			if (!j){
				F[i]=0;
				break;
			}
			j=F[j];
		}
	}
}

double go(int rem,int m){
	if (!rem) return 0;
	if (mem[rem][m]>-.5) return mem[rem][m];
	double res=0;
	for(int i=0;i<K;++i){
		if (keys[i]==target[m]){
			if (m+1==L){
				res+=go(rem-1,F[m+1])+1.;
			} else res+=go(rem-1,m+1);
		} else {
			int m2=m;
			while(m2&&keys[i]!=target[m2]) m2=F[m2];
			if (keys[i]==target[m2]) res+=go(rem-1,m2+1);
			else res+=go(rem-1,0);
		}
	}
	//printf("%d %d %lf\n",rem,m,res/K);
	return mem[rem][m]=res/K;
}

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		printf("Case #%d: ",tt);
		scanf("%d%d%d\n%s\n%s",&K,&L,&S,keys,target);
		memset(mem,-1,sizeof(mem));
		mx=1+(S-L)/(L-prekryv());
		if (!possible()){
			printf("%.9lf\n",0.);
			continue;
		}
		buildF();
		double res=mx-go(S,0);
		printf("%.9lf\n",res<0?0:res);
	}
	return 0;
}

