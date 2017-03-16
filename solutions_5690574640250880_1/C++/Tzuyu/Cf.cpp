#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int mp[200][200];

int main(){
	int T,ti,i,j,n,m,r,c,nm,a,b;
	FILE * inf, * outf;
	inf=fopen("C-large.in.txt","r");
	outf=fopen("C-large.out","w");	
	fscanf(inf,"%d",&T);
	for (ti=0;ti<T;ti++){
		fscanf(inf,	"%d%d%d",&r,&c,&m);
		memset(mp,0,sizeof(mp));
		nm=r*c-m;
		fprintf(outf,"Case #%d:\n",ti+1);
		if (r>=3&&c>=3){
			if (m==r*c-2||m==r*c-3||m==r*c-5||m==r*c-7) fprintf(outf,"Impossible\n");
			else {
				if (m==r*c-1){
					for (i=0;i<1;i++){
						for (j=0;j<1;j++) mp[i][j]=1;
					}
				}
				if (m==r*c-4){
					for (i=0;i<2;i++){
						for (j=0;j<2;j++) mp[i][j]=1;
					}
				}
				else if (m==r*c-6){
					for (i=0;i<2;i++){
						for (j=0;j<3;j++) mp[i][j]=1;
					}
				}
				else if (m<=r*c-8){
					if (nm>=(r+c-2)*2){
						a=r;
						b=c;
					}
					else {
						a=(nm/2+2)/2;
						b=nm/2+2-a;
						if (a>r) {
							a=r;
							b=nm/2+2-r;
							if (a*b<nm) b=(nm-a*2)/2+2;
						}
						if (b>c) {
							b=c;
							a=nm/2+2-c;
							if (a*b<nm) a=(nm-b*2)/2+2;
						}
						if (a>r||b>c) fprintf(outf,"Error!\n");
					}
					for (i=0;i<a;i++){
						for (j=0;j<2;j++) mp[i][j]=1;
					}
					for (i=0;i<2;i++){
						for (j=2;j<b;j++) mp[i][j]=1;
					}
					nm-=(a+b-2)*2;
					for (i=2;i<a&&nm>0;i++){
						for (j=2;j<b&&nm>0;j++) {
							mp[i][j]=1;
							nm--;
						}
					}
				}
				for (i=0;i<r;i++){
					for (j=0;j<c;j++){
						if (mp[i][j]==0) fprintf(outf,"*");
						else if (mp[i][j]==1&&i==0&&j==0) fprintf(outf,"c");
						else fprintf(outf,".");
					}
					fprintf(outf,"\n");
				}
			}
		}
		else {
			if (r==1||c==1){
				if (c==1){
					fprintf(outf,"c\n");
					for (i=1;i<r*c-m;i++) fprintf(outf,".\n");
					for (;i<r*c;i++) fprintf(outf,"*\n"); 
				}
				else {
					fprintf(outf,"c");
					for (i=1;i<r*c-m;i++) fprintf(outf,".");
					for (;i<r*c;i++) fprintf(outf,"*"); 
					fprintf(outf,"\n");
				}
			}
			else if (r==2||c==2){
				if (c==2){
					if (m==r*c-1){
						fprintf(outf,"c*\n");
						for (i=1;i<r*c/2;i++) fprintf(outf,"**\n"); 
					}
					else if (m%2==1||r*c-m<4) fprintf(outf,"Impossible\n");
					else {
						fprintf(outf,"c.\n");
						for (i=1;i<(r*c-m)/2;i++) fprintf(outf,"..\n");
						for (;i<r*c/2;i++) fprintf(outf,"**\n"); 
					}
				}
				else {
					if (m==r*c-1){
						fprintf(outf,"c");
						for (i=1;i<c;i++) fprintf(outf,"*"); 
						fprintf(outf,"\n");
						for (i=0;i<c;i++) fprintf(outf,"*"); 
						fprintf(outf,"\n");
					}
					else if (m%2==1||r*c-m<4) fprintf(outf,"Impossible\n");
					else {
						fprintf(outf,"c");
						for (i=1;i<c-m/2;i++) fprintf(outf,".");
						for (;i<c;i++) fprintf(outf,"*"); 
						fprintf(outf,"\n");
						for (i=0;i<c-m/2;i++) fprintf(outf,".");
						for (;i<c;i++) fprintf(outf,"*"); 
						fprintf(outf,"\n");
					}
				}
			}
		}
	}
	fclose(inf);
	fclose(outf);
	return 0;
}
