#include<stdio.h>
#include<string.h>

void fun(int S[][4],int index,int K,int i,int m,int n){
	int counter=K-1,j;
	for(j=i+1;j<index;j++){
		if(S[j][0]){
			if((S[j][m]==S[i][m]) && (S[j][n]==S[i][n])){
				if(counter>0)counter--;
				else S[j][0]=0;
			}
		}
	}
}

int main(){
	int testcases,tc;
	scanf("%d",&testcases);
	fprintf(stderr,"Cases: %d\n",testcases);
	for(tc=1;tc<=testcases;++tc){
		
		//input
		int J,P,S1,K;
		scanf("%d %d %d %d",&J,&P,&S1,&K);
		
		int S[1000][4]={0};
		int i,j,k,index=0;
		for(i=1;i<=J;++i){
			for(j=1;j<=P;++j){
				for(k=1;k<=S1;++k){
					S[index][0]=1;
					S[index][1]=i;
					S[index][2]=j;
					S[index][3]=k;
					index++;
				}
			}
		}
		
		if(K<J || K<P || K<S1)
			fprintf(stderr,"\t Case: %d [%d %d %d %d]\n",tc,J,P,S1,K);
		
		for(i=0;i<index;++i){
			if(S[i][0]){
				fun(S,index,K,i,1,2);
				fun(S,index,K,i,1,3);
				fun(S,index,K,i,2,3);
			}
		}
		int ans=0;
		for(i=0;i<index;++i){
			if(S[i][0])ans++;
		}
		//output
		printf("Case #%d: %d\n",tc,ans);
		for(i=0;i<index;++i){
			if(S[i][0]){
				printf("%d %d %d\n",S[i][1],S[i][2],S[i][3]);
			}
		}
	}
	return 0;
}
