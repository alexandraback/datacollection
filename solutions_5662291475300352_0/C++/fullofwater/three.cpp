#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int T, D[200], M[200], N;

int main() {
	int T, r, qq, ww, ee;
	scanf("%d",&T);
	for (int C=1;C<=T;C++) {
		scanf("%d", &r);
		N=0;
		for (int i=0;i<r;i++) {
			scanf("%d%d%d", &qq, &ww, &ee);
			for (int j=0;j<ww;j++)
				D[N]=qq, M[N]=ee++, N++;
		}
		if (N>2) {
			puts("NO");
			continue;
		}
		printf("Case #%d: ", C);
		if (N<=1 || M[1]==M[0]) {
			puts("0");
			continue;
		}
		
		if (M[0]<M[1])
			swap(D[0],D[1]), swap(M[0],M[1]);
		long long diff;
		if (D[0]>=D[1])
			diff=D[0]-D[1]+360;
		else
			diff=360-(D[1]-D[0]);
		
		puts(M[1]*(diff)<=((long long)360-D[0])*(M[0]-M[1])?"1":"0");

		/*
		(diff)*M[1] <= (360.0-D[0])*(M[0]-M[1])
		
		double tim=(diff)/(360.0/M[1]-360.0/M[0]);
		double tim2=(360.0-D[0])*M[0]/360.0;
			
		double tim=(diff+360.0)/(360.0/M[0]-360.0/M[1]);
		double tim2=(360.0-D[1])*M[1]/360.0; */

		/*if (M[1]<M[0]) {
			if (D[0]==D[1])
				diff+=360;
			
			
			
			
			//M[1]*(diff)<=(360.0-D[0])*(M[0]-M[1])
			
		} else {
			
			//M[0]*(diff+360.0)<=(360.0-D[1])*(M[1]-M[0])
			
			puts(M[0]*(diff+360.0)<=(360.0-D[1])*(M[1]-M[0])?"1":"0");
		}*/
	}
	return 0;
}

