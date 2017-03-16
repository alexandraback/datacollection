//============================================================================
// Name        : gcj_A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "cmath"
#define N 300
#define M 40
using namespace std;
int a[N];
int main() {
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("aaaaaaaaaaa.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){

		int n;
		scanf("%d",&n);
		double sum=0;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&a[j]);
			sum+=a[j];
		}
		printf("Case #%d:",i+1);
		double min = sum*2/n;
		double t=sum;
		int tt=n;
		for(int j=0;j<n;j++){
			if(a[j]>min) {
				t-=a[j];
				tt--;
			}
		}
		for (int j = 0; j < n; ++j) {
			if((a[j]-min)>0)
			printf(" %lf",0.0);
			else printf(" %lf",((t+sum)/tt-a[j])/sum*100);

		}
		printf("\n");

	}
	return 0;
}
