#include "stdio.h"
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int main() {
	FILE *fp, *fp2;
	int num;
	int X,Y;
	char ans[510];
	fopen_s(&fp, "B-small-attempt0.in", "r");
	fopen_s(&fp2, "B-small-attempt0.out", "w");
	fscanf_s(fp, "%d", &num);

	int dx,dy,step;
	int sx,sy;
	int last;
	for(int i=0; i<num; ++i) {
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf_s(fp, "%d %d", &X,&Y);
		if(X>0) {sx=1;dx=X;}
		else {sx=-1;dx=-X;}

		if(Y>0) {sy=1;dy=Y;}
		else {sy=-1; dy=-Y;}

		step=1;
		last=1;
		
		while(step<510) {
			if(last) {
				dx-=step;
				if(sx==1) ans[step-1]='E';
				else ans[step-1]='W';
			}else {
				dy-=step;
				if(sy==1) ans[step-1]='N';
				else ans[step-1]='S';
			}
			++step;
			if(dx>0 && dy>0) {last=step%2;}
			else if(dx<=0) last=0;
			else last=1;
			if(dx<=0 && dy<=0) break;
		}

		char w1='W',w2='W';
		if(sx==1) w1='E';
		else w2='E';
		for(int j=0; j<-dx;++j) {
			ans[step-1]=w1;
			ans[step]=w2;
			step+=2;
		}

		w1='S',w2='S';
		if(sy==1) w1='N';
		else w2='N';
		for(int j=0; j<-dy;++j) {
			ans[step-1]=w1;
			ans[step]=w2;
			step+=2;
		}

		for(int j=0; j<step-1; ++j) {
			fprintf(fp2,"%c",ans[j]);
		}
		fprintf(fp2,"\n");
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
