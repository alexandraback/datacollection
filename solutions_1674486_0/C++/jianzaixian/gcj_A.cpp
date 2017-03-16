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
#include "queue"
#define N 1005
#define M 40
using namespace std;
int a[N][N];
int visit[N];

int main() {
	freopen("b.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ii=0;ii<T;ii++){

		int n;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		bool flag =false;
		for(int i=0;i<n;i++){
			int t;
			scanf("%d",&t);
			int tt;
			for(int k=0;k<t;k++){
				scanf("%d",&tt);
				a[i+1][tt]=1;
			}

			for(int k=1;k<=n;k++){
				memset(visit,0,sizeof(visit));
				queue<int> q;
				q.push(k);
				visit[k]=1;
				while(!q.empty()){
					int now=q.front();
					q.pop();
					for(int x=1;x<=n;x++){
						if(a[now][x]){
							if(visit[x]){
								flag=true;
								break;
							}else{
								q.push(x);
								visit[x]=1;
							}
						}
					}
				}
				if(flag)break;

			}
		}
		if(flag)
		printf("Case #%d: Yes\n",ii+1);
		else{
			printf("Case #%d: No\n",ii+1);
		}


	}
	return 0;
}
