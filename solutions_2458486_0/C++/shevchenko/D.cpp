#include<stdio.h>

int K,n;
int initk[200],ck[20][200],ct[20],c[2000000],v[2000000];

void revtrace(int x){
	if(c[x]==2) return;
	c[x]=2;
	int i;
	for(i=0;i<n;i++){
		if((v[x]|(1<<i))==v[x]){
			revtrace(x-(1<<i));
		}
	}
}

int process(){
	int i,j,k,pw=1,kcnt;
	for(i=0;i<n;i++) pw=pw+pw;
	for(i=0;i<pw;i++){ c[i]=0; v[i]=0; }
	c[0]=1;
	for(i=0;i<pw;i++){
		if(c[i]==0) continue;
		for(j=0;j<n;j++){
			if( (i|(1<<j))==i ) continue;
			kcnt=initk[ct[j]];
			for(k=0;k<n;k++){
				if( (i|(1<<k))!=i ) continue;
				kcnt+=ck[k][ct[j]];
				if(ct[k]==ct[j]) kcnt--;
			}
			if(kcnt>0){
				c[i|(1<<j)]=1;
				v[i|(1<<j)]=v[i|(1<<j)]|(1<<j);
			}
		}
	}
	if(c[pw-1]==0) return 0;
	revtrace(pw-1);
	int ch[20]={0,},x=0,path[20];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(ch[j]==1) continue;
			if(c[x|(1<<j)]==2 && (v[x|(1<<j)]|(1<<j))==v[x|(1<<j)]){
				path[i]=j;
				x = x | (1<<j);
				ch[j]=1;
				break;
			}
		}
	}
	
	int ks[200];
	for(i=0;i<200;i++) ks[i]=initk[i];
	for(i=0;i<n;i++){
		if(ks[ct[path[i]]]==0){ 
			printf("ERROR\n"); 
			break; 
		}
		for(j=0;j<200;j++) ks[j]+=ck[path[i]][j];
		ks[ct[path[i]]]--;
	}

	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d",path[i]+1);
	}
	printf("\n");
	return 1;
}

int main(){
	freopen("D-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,t,x,y;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		printf("Case #%d: ",k);
		scanf("%d%d",&K,&n);
		for(i=0;i<200;i++) initk[i]=0;
		for(i=0;i<n;i++) for(j=0;j<200;j++) ck[i][j]=0;
		for(i=0;i<K;i++){
			scanf("%d",&x);
			initk[x-1]++;
		}
		for(i=0;i<n;i++){
			scanf("%d",&ct[i]);
			ct[i]--;
			scanf("%d",&x);
			for(j=0;j<x;j++){
				scanf("%d",&y);
				y--;
				ck[i][y]++;
			}
		}
		int ret=process();
		if(ret==0) printf("IMPOSSIBLE\n");
	}
	return 0;
}