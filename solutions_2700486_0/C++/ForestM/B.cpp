#include "stdio.h"
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int main() {
	FILE *fp, *fp2;
	int num;
	int N, X, Y;
	int x;
	fopen_s(&fp, "B-small-attempt0.in", "r");
	fopen_s(&fp2, "B-small-attempt0.out", "w");
	fscanf_s(fp, "%d", &num);

	double ans;
	for(int i=0; i<num; ++i) {
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf_s(fp, "%d %d %d", &N,&X,&Y);
		if(N<=1) x=1;
		else if(N<=6) x=3;
		else if(N<=15) x=5;
		else x=7;

		if(X==0 && Y==0) {
			ans=1;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}
		if(N==1) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(Y==0 && (X==-2||X==2)) {
			if(N>=4) {
				ans=1;
			}else if(N==2) {
				ans=0.5;
			}else if(N==3) {
				ans=0.5+0.5*0.5;
			}
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N==2) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(Y==1 && (X==-1 || X==1)) {
			if(N>=5) ans=1;
			else if(N==3) ans=0.25;
			else if(N==4) ans=0.25+0.25;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N<=5) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N==6) {
			if(X==0 && Y==2) ans=1;
			else ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}


		if(Y==0 && (X==4 || X==-4)) {
			if(N>=9) ans=1;
			else if(N==7) ans=0.5;
			else if(N==8) ans=0.75;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N==7) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}
		if(Y==1 && (X==3|| X==-3)) {
			if(N>=10) ans=1;
			else if(N==8) ans=0.25;
			else if(N==9) ans=0.5;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}
		if(N==8) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}
		if(Y==2 && (X==2 || X==-2)) {
			if(N>=12) ans=1;
			else if(N==9) ans=0.5*0.5*0.5;
			else if(N==10) ans=0.5*0.5*0.5 + 3*0.5*0.5*0.5*0.5;
			else if(N==11) ans=0.5*0.5*0.5 + 3*0.5*0.5*0.5*0.5 + 0.5*0.5*0.5*0.5*0.5*6;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N==9) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(Y==3 && (X==1||X==-1)) {
			if(N>=14) ans=1;
			else if(N==10) ans=0.5*0.5*0.5*0.5;
			else if(N==11) ans=0.5*0.5*0.5*0.5 + 4*0.5*0.5*0.5*0.5*0.5;
			else if(N==12) ans=0.5*0.5*0.5*0.5 + 4*0.5*0.5*0.5*0.5*0.5 + 10*0.5*0.5*0.5*0.5*0.5*0.5;
			else if(N==13) ans=0.5*0.5*0.5*0.5 + 4*0.5*0.5*0.5*0.5*0.5 + 10*0.5*0.5*0.5*0.5*0.5*0.5 +
							0.5*0.5*0.5*0.5*0.5*0.5*0.5 * 20;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N<=14) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N==15) {
			if(Y==4 && X==0) ans=1;
			else ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(Y==0 && (X==7||X==-7)) {
			if(N>=18) ans=1;
			else if(N==16) ans=0.5;
			else if(N==17) ans=0.5+0.25;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N==16) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(Y==1 && (X==6||X==-6)) {
			if(N>=19) ans=1;
			else if(N==17) ans=0.25;
			else if(N==18) ans=0.5;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(N==17) {
			ans=0;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		if(Y==2 && (X==-5 || X==5)) {
			if(N==18) ans=0.5*0.5*0.5;
			else if(N==19) ans=0.5*0.5*0.5 + 3*0.5*0.5*0.5*0.5;
			else if(N==20) ans=0.5*0.5*0.5 + 3*0.5*0.5*0.5*0.5 + 0.5*0.5*0.5*0.5*0.5*6;
			fprintf(fp2, "%lf\n", ans);
			continue;
		}

		ans=0;
		fprintf(fp2, "%lf\n", ans);
		continue;
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
