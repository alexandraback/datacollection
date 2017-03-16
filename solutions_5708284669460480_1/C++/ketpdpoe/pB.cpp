#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=1;I<=T;I++){
		int K,L,S;
		scanf("%d %d %d",&K,&L,&S);
		char s1[105],s2[105];
		scanf("%s %s",s1,s2);
		printf("Case #%d: ",I);
		double p[30]={};
		int i,j,k;
		for(i=0;i<K;i++){
			p[s1[i]-'A']+=1.0;
		}
		for(i=0;i<26;i++){
			p[i]=1.0*p[i]/K;
		}
		double yp[105]={};
		double np[105]={};
		for(i=0;i<L;i++)np[i]=1.0;
		int tt=1;
		yp[L]=1.0;
		for(i=0;i<L;i++){
			yp[L]*=p[s2[i]-'A'];
			if(p[s2[i]-'A']<1e-10)tt=0;
		}
		if(tt==0){
			printf("0.0\n");
			continue;
		}
		//printf("%lf\n",yp[L]);
		np[L]=1.0-yp[L];
		for(i=L+1;i<=S;i++){
			for(j=0;j<=i-L;j++){
				yp[i]+=(np[j]*yp[L]);
			}
			np[i]=1.0-yp[i];
			//printf("i=%d: p=%lf\n",i,yp[i]);
		}
		double e[105]={};
		e[L]=yp[L];
		for(i=L+1;i<=S;i++){
			for(j=0;j<=i-L;j++){
				e[i]+=np[j]*yp[L]*(1+e[i-j-L]);
			}
		}
		for(i=1;i<L;i++){
			int t=1;
			for(j=0;j<i;j++){
				if(s2[j]!=s2[L-i+j]){
					t=0;
					break;
				}
			}
			if(t==0)break;
		}
		i--;
		//cout<<i<<endl;
		int ta=(S-i)/(L-i);
		//cout<<ta<<endl;
		printf("%.7lf\n",ta-e[S]);
	}
	return 0;
}