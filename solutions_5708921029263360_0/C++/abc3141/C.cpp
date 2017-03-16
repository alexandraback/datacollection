#include<bits/stdc++.h>
using namespace std;
int T;
int J,P,S;
int K;
bool F[10][10][10];
int cou1[10][10];
int cou2[10][10];
int cou3[10][10];
int main()
{
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		scanf("%d%d%d%d",&J,&P,&S,&K);
		
		if(J==3&&P==3&&S==3){
			if(K==1){
				printf("Case #%d: %d\n",cas,9);
				printf("1 1 2\n1 2 1 \n1 3 3\n2 1 1\n2 2 3\n2 3 2\n3 1 3\n3 2 2\n3 3 1\n");
			}
			else if(K==2){
				printf("Case #%d: %d\n",cas,18);
				printf("1 1 1\n1 1 3\n1 2 1\n1 2 2\n1 3 2\n1 3 3\n");
				printf("2 1 1\n2 1 2\n2 2 2\n2 2 3\n2 3 1\n2 3 3\n");
				printf("3 1 2\n3 1 3\n3 2 1\n3 2 3\n3 3 1\n3 3 2\n");
			}
			else{
				printf("Case #%d: %d\n",cas,27);
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						for(int k=1;k<=3;k++){
							printf("%d %d %d\n",i,j,k);
						}
					}
				}
			}
			continue;
			
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				for(int k=0;k<10;k++){
					F[i][j][k]=false;
				}
			}
		}
		int ans=0;int AA=0;
		int X=J*P*S;
		for(int I=0;I<(1<<X);I++){
			
			for(int i=0;i<S;i++){
				for(int j=0;j<S;j++){
					cou1[i][j]=cou2[i][j]=cou3[i][j]=0;
				}
			}
			for(int i=0;i<J;i++){
				for(int j=0;j<P;j++){
					for(int k=0;k<S;k++){
						F[i][j][k]=false;
					}
				}
			}
			int cou=0;
			int JJ=0;int PP=0;int SS=-1;
			for(int j=0;j<X;j++){
				SS++;
				if(SS==S){
					SS=0;
					PP++;
				}
				if(PP==P){
					PP=0;
					JJ++;
				}
				if((I>>j)&1){
					cou++;
					
					F[JJ][PP][SS]++;
					cou1[JJ][PP]++;
					if(cou1[JJ][PP]>K)goto FFFF;
					cou2[JJ][SS]++;
					if(cou2[JJ][SS]>K)goto FFFF;
					cou3[PP][SS]++;
					if(cou3[PP][SS]>K)goto FFFF;
					
				}
			}
			
			if(ans<cou){
				ans=cou;
				AA=I;
			}
			FFFF:;
		}
		printf("Case #%d: %d\n",cas,ans);
		for(int i=0;i<J;i++){
			for(int j=0;j<P;j++){
				for(int k=0;k<S;k++){
					if((AA>>(i*P*S+j*S+k))&1)printf("%d %d %d\n",i+1,j+1,k+1);
				}
			}
		}
	}
	
	
	return 0;
}
