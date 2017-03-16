#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

int s[300];
double p[300];
int main(void){
	int t, n;
	double sum;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		sum = 0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &s[i]);
			sum += s[i];
		}
		printf("Case #%d:", tt);
		for(int i=0;i<n;i++)
			p[i] = (sum*2/n - s[i])/sum;
		double m = 0;
		for(int i=0;i<n;i++)
			if(p[i] < 0){
				m -= p[i]; p[i] = 0;
			}
		while(1){
			int c=0;
			for(int i=0;i<n;i++)
				if(p[i] > 0) c++;
			bool flag=true;
			for(int i=0;i<n;i++){
				if(p[i] > 0) p[i]-=m/c;
				if(p[i] < 0) flag=false; 
			}
			if(flag) break;
		}
		for(int i=0;i<n;i++)
			printf(" %lf", p[i]*100);
		puts("");
	}

	return 0;
}
