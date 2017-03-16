#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
using namespace std;


int main() {
	int TC;
	scanf("%d",&TC);
	for(int tc =1; tc<=TC; tc++) {
		printf("Case #%d: ",tc);
		int J,P,S,K;
		int sol[11][11][11]= {0}, cnt=0;
		int m1[11][11]={0};
		int m2[11][11]={0};
		int m3[11][11]={0};
		scanf("%d%d%d%d",&J,&P,&S,&K);
		for(int i=1; i<=J; i++)
			for(int j=1; j<=P; j++)
				for(int k=1; k<=S; k++) {
					if(m1[i][j]+1 > K || m2[i][k]+1 > K || m3[j][k]+1 > K)
						continue;
					m1[i][j]++; m2[i][k]++; m3[j][k]++;
					sol[i][j][k] = 1;
					cnt++;
				}
		printf("%d\n",cnt);
		for(int i=1; i<=J; i++)
			for(int j=1; j<=P; j++)
				for(int k=1; k<=S; k++) 
					if(sol[i][j][k]) printf("%d %d %d\n",i,j,k);
	}
}
