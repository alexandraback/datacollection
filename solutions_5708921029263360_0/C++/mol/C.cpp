#include <stdio.h>
#include <string.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int tt=0; tt<T; tt++){
		int J,P,S,K;
		scanf("%d%d%d%d",&J,&P,&S,&K);
		FILE *fp = fopen("Ctemp.txt","r");
		int days=0;
		int flg[J][P][S];
		for(int j=0; j<J; j++)
			for(int p=0; p<P; p++)
				for(int s=0; s<S; s++)
					flg[j][p][s] = 0;
		for(int i=0; i<27; i++){
			int outfit[3];
			fscanf(fp,"%d%d%d",&outfit[0],&outfit[1],&outfit[2]);
			if(outfit[0]>J || outfit[1]>P || outfit[2]>S)
				continue;
			days++;
			flg[outfit[0]-1][outfit[1]-1][outfit[2]-1] = 1;
			int ok=1;
			for(int j=0; j<J; j++){
				for(int p=0; p<P; p++){
					int cnt=0;
					for(int s=0; s<S; s++)
						cnt += flg[j][p][s];
					if(cnt > K)
						ok = 0;
				}
			}
			for(int p=0; p<P; p++){
				for(int s=0; s<S; s++){
					int cnt=0;
					for(int j=0; j<J; j++)
						cnt += flg[j][p][s];
					if(cnt > K)
						ok = 0;
				}
			}
			for(int s=0; s<S; s++){
				for(int j=0; j<J; j++){
					int cnt=0;
					for(int p=0; p<P; p++)
						cnt += flg[j][p][s];
					if(cnt > K)
						ok = 0;
				}
			}
			if(ok == 0){
				days--;
				flg[outfit[0]-1][outfit[1]-1][outfit[2]-1] = 0;
				break;
			}
		}
		fclose(fp);
		printf("Case #%d: %d\n",tt+1,days);
		for(int j=0; j<J; j++)
			for(int p=0; p<P; p++)
				for(int s=0; s<S; s++)
					if(flg[j][p][s])
						printf("%d %d %d\n",j+1,p+1,s+1);
		/*
		int flg[J][P][S],ok;
		int maxd=0,argmax[J][P][S];
		for(int i=0; i<(1<<J*P*S); i++){
			ok = 1;
			for(int j=0; j<J; j++)
				for(int p=0; p<P; p++)
					for(int s=0; s<S; s++)
						flg[j][p][s] = (i>>(j*P*S+p*S+s))%2;
			for(int j=0; j<J; j++){
				for(int p=0; p<P; p++){
					int cnt=0;
					for(int s=0; s<S; s++)
						cnt += flg[j][p][s];
					if(cnt > K)
						ok = 0;
				}
			}
			for(int p=0; p<P; p++){
				for(int s=0; s<S; s++){
					int cnt=0;
					for(int j=0; j<J; j++)
						cnt += flg[j][p][s];
					if(cnt > K)
						ok = 0;
				}
			}
			for(int s=0; s<S; s++){
				for(int j=0; j<J; j++){
					int cnt=0;
					for(int p=0; p<P; p++)
						cnt += flg[j][p][s];
					if(cnt > K)
						ok = 0;
				}
			}
			if(ok){
				int days=0;
				for(int j=0; j<J; j++)
					for(int p=0; p<P; p++)
						for(int s=0; s<S; s++)
							days += flg[j][p][s];
				if(days > maxd){
					maxd = days;
					for(int j=0; j<J; j++)
						for(int p=0; p<P; p++)
							for(int s=0; s<S; s++)
								argmax[j][p][s] = flg[j][p][s];
				}
			}
		}
		printf("Case #%d: %d\n",tt+1,maxd);
		for(int j=0; j<J; j++)
			for(int p=0; p<P; p++)
				for(int s=0; s<S; s++)
					if(argmax[j][p][s])
						printf("%d %d %d\n",j+1,p+1,s+1);
		*/
	}
	return 0;
}
