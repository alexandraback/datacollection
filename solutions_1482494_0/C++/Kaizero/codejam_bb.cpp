#include<stdio.h>
FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");
int t,n,c,i,j,w[1001][2],v[1001][2],mn,y,cc,l,ck,ct,zz;
int main(){
	fscanf(in,"%d",&t);
	while(t){
		t--,c++;
		fprintf(out,"Case #%d: ",c);
		if(c==98){
			c=c;
		}
		fscanf(in,"%d",&n);
		for(i=0;i<n;i++){fscanf(in,"%d%d",&w[i][0],&w[i][1]);v[i][0]=v[i][1]=0;}
		l=0;
		cc=ct=0;
		zz=0;
		while(cc<n){
			ct++;
			ck=0;
			mn=99999999;
			for(i=0;i<n;i++){
				if(v[i][0]==0&&v[i][1]==0){
					if(mn>w[i][1])mn=w[i][1],y=i;}}
			if(mn<=l){
				ck=1;
				v[y][1]=1;
				l+=2;
				cc++;continue;}
			mn=99999999;
			for(i=0;i<n;i++){
				if(v[i][0]==1&&v[i][1]==0){
					if(mn>w[i][1])mn=w[i][1],y=i;}}
			if(mn<=l){
				ck=1;
				v[y][1]=1;
				l++;
				cc++;continue;}
			mn=0;
			y=-1;
			for(i=0;i<n;i++){
				if(v[i][0]==0&&v[i][1]==0){
					if(w[i][0]<=l&&mn<w[i][1])mn=w[i][1],y=i;}}
			if(y>=0){
				ck=1;
				v[y][0]=1;
				l++;
				continue;}
			zz=1;break;}
		if(zz==1)fprintf(out,"Too Bad\n");
		else fprintf(out,"%d\n",ct);
	}
}