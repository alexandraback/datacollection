#include<stdio.h>
#include<algorithm>
using namespace std;
FILE *out=fopen("output.txt","w");
FILE *in=fopen("input.txt","r");
int t,c,i,n,w[301],j,cc,v[301];
double q,mm,ssss,s,sss;
int main(){
	fscanf(in,"%d",&t);
	while(t--){
		c++;
		fscanf(in,"%d",&n);
		s=0;
		for(i=0;i<n;i++){fscanf(in,"%d",&w[i]);s+=w[i];}
		sss=s;
		fprintf(out,"Case #%d: ",c);
		for(i=0;i<n;i++)v[i]=0;
		for(i=0;i<n;i++){
			mm=99999999;cc=0;
			for(j=0;j<n;j++){
				if(v[j]==0&&mm>w[j])mm=w[j],cc=j;}
			v[cc]=1;
			if(i==0){
				ssss=mm;
				continue;
			}
			if(i>0){
				if(mm*i-ssss*i>=s){ssss+=s/i;s=0;break;}
				s-=mm*i-ssss*i;
				ssss=mm;
			}
		}
		if(s>0)ssss+=s/n;
		for(i=0;i<n;i++){
			if(ssss<=w[i])fprintf(out,"%lf ",0);
			else fprintf(out,"%lf ",(ssss-w[i])/sss*100);
		}
		fprintf(out,"\n");
	}
}