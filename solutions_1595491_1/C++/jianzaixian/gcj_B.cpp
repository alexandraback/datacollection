//============================================================================
// Name        : gcj_A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "fstream"
#include "string.h"
#include "stdio.h"

#define N 108
#define M 40
using namespace std;

int main() {
	//freopen("b.in","r",stdin);
	freopen("b-large.out","w",stdout);
	int T;
	int a[N];
	scanf("%d",&T);
	for (int i = 0; i < T; ++i) {
		int n,s,p;
		scanf("%d%d%d",&n,&s,&p);
		int up=0,mid=0;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&a[j]);
			if(a[j]>=3*p-2) up++;
			else{
				if(p==0) up++;
				else if(p==1){
					if(a[j]>=1) up++;
				}
				else if(a[j]>=3*p-4) mid++;
			}
		}
		int small = s>mid?mid:s;
		printf("Case #%d: %d\n",i+1,up+small);
	}
	//for(int i =0;i<T;i++){

	//}
	return 0;
}
