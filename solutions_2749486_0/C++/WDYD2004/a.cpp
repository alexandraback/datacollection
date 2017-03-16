#include <stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int T,n,m,t;
char ans[10005];
short x[5000005],y[5000005];
int v[3005][3005],path[3005][3005],cnt;
int main(){
	int i,j;
	x[0]=0; y[0]=0; cnt++;
	int dx[4]={1,0,0,-1},dy[4]={0,1,-1,0};
	char d[5]={"ENSW"};
	v[0+1000][0+1000]=1;
	for(i=0;i<cnt;i++){
		int g=v[x[i]+1000][y[i]+1000];
		for(j=0;j<4;j++){
			int X=x[i]+dx[j]*g,Y=y[i]+dy[j]*g;
			if(X<-500||X>500||Y<-500||Y>500||v[X+1000][Y+1000]) continue;
			v[X+1000][Y+1000]=g+1; path[X+1000][Y+1000]=j;
			x[cnt]=X; y[cnt++]=Y;
		}
	}
	/*
	for(;;){
		scanf("%d%d",&n,&m);
		n+=100; m+=100; int g=v[n][m]-1;
		printf("%d ",g);
		if(v[n][m] == v[n-g][m]+1) printf("a");
		if(v[n][m] == v[n+g][m]+1) printf("b");
		if(v[n][m] == v[n][m-g]+1) printf("c");
		if(v[n][m] == v[n][m+g]+1) printf("d");
		printf("\n");
	}
	for(i=-12;i<=12;i++){
		for(j=-12;j<=12;j++) printf("%2d ",v[i+100][j+100]-1);
		printf("\n");
	}
	return 0;*/
	for(fscanf(in,"%d",&T);T--;){
		fscanf(in,"%d %d",&n,&m);
		cnt=0; ans[cnt]=0; n+=1000; m+=1000;
		for(;;){
			if(n==1000&&m==1000) break;
			ans[cnt++]=d[path[n][m]];
			int g=v[n][m]-1;
			int N=n-dx[path[n][m]]*g;
			int M=m-dy[path[n][m]]*g;
			n=N; m=M;
		}
		fprintf(out,"Case #%d: ",++t);
		for(i=cnt-1;i>=0;i--) fprintf(out,"%c",ans[i]);
		fprintf(out,"\n");
	}
	return 0;
}

/*#include <stdio.h>
#include <string.h>
#define N 1048576
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int T,n,m,t,i;
char a[1000005];

int main(){
	for(fscanf(in,"%d",&T);T--;){
		fscanf(in,"%s %d",a,&m); n=strlen(a);
		long long sum=0,ans=0,w=-1;
		for(i=0;i<n;i++){
			if(a[i]=='a'||a[i]=='e'||a[i]=='o'||a[i]=='i'||a[i]=='u') sum=0;
			else sum++;
			if(sum>=m) w=i;
			if(w!=-1) ans+=w-m+2;
		}
		fprintf(out,"Case #%d: %lld\n",++t,ans);
	}
	return 0;
}*/