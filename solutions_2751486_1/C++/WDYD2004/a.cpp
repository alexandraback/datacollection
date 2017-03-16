#include <stdio.h>
#include <string.h>
#define N 1048576
FILE *in=fopen("A-large.in","r");
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
}