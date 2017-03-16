#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 521196
int n,print,len[522000],tbl[5002][5];
char mun[5001],dict[522000][11];
void pro(){
	int i,j,a,s,e,ts,te,last,k,cnt;
	n=strlen(mun+1);
	for(i=0;i<=n;i++){
		tbl[i][0]=0x7fffffff;tbl[i][1]=0x7fffffff;tbl[i][2]=0x7fffffff;tbl[i][3]=0x7fffffff;tbl[i][4]=0x7fffffff;
	}
	tbl[0][0]=0;
	for(i=0;i<n;i++){
		s=0;e=N-1;
		for(a=0;a<5;a++){
			if(i+a+1==n+1) break;
			ts=0;
			if(tbl[i][a]==0x7fffffff){
				for(j=ts;j<=te;j++){
					if(dict[j][a]==mun[i+a+1]){
						te=j;
						if(ts==0)
							ts=j;
					}	
				}
				s=ts;e=te;
				continue;
			}
			for(j=s;j<=e;j++){
				last=a;cnt=0;
				if(dict[j][a]==mun[i+a+1]){
					te=j;
					if(ts==0)
						ts=j;
				}
				if(i+len[j]>n) continue;
				for(k=a;k<len[j];k++){
					if(mun[i+k+1]!=dict[j][k]){
						if(last!=0)
							break;
						last=5;
						cnt++;
					}
					last--;
					if(last<0)
						last=0;
				}
				if(k==len[j]){
					if(tbl[i+len[j]][last]>tbl[i][a]+cnt)
						tbl[i+len[j]][last]=tbl[i][a]+cnt;
				}
			}
			s=ts;e=te;
		}
	}
	print=0x7fffffff;
	for(i=0;i<5;i++){
		if(print>tbl[n][i])
			print=tbl[n][i];
	}
}
int main(){
	int testt,test,i;
	FILE *in=fopen("dict.txt","r");
	for(i=0;i<N;i++){
		fscanf(in,"%s",dict[i]);
		len[i]=strlen(dict[i]);
	}
	fclose(in);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%s",mun+1);
		print=0;
		pro();
		printf("Case #%d: %d\n",test,print);
	}
	return 0;
}
