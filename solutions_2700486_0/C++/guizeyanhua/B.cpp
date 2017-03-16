/*************************************************************************
> File Name: B.cpp
> Author: myf
> Mail: 374684987@qq.com 
> Created Time: Sun 05 May 2013 00:50:07 CST
************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int N=1000;

int t,n;
int a[N];
double c[2*N+1][2*N+1];

void Init(){
	a[0]=1;
	for(int i=1;i!=N;i++) a[i]=a[i-1]+4*i+1;
	c[0][0]=1;
	for(int i=1;i!=N;i++){
		c[i][0]=c[i-1][0]*0.5;
		for(int j=1;j!=i;j++){
			c[i][j]=c[i-1][j]*0.5+c[i-1][j-1]*0.5;
		}
		c[i][i]=c[i-1][i-1]*0.5;
	}
}

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	Init();

	scanf("%d",&t);
	for(int q=1;q!=t+1;q++){
		double ans;
		int x,y;
		scanf("%d%d%d",&n,&x,&y);
		int l=0,r=N,mid;
		while(l+1<r){
			mid=(l+r)/2;
			if (a[mid]<=n) l=mid;
			else r=mid;
		}
		if (a[l]==n){
			if (abs(x)+abs(y)<=l*2) ans=1;
			else ans=0;
		}
		else{
			n-=a[l];
			l++;
			if (abs(x)+abs(y)<2*l) ans=1;
			else 
			if (abs(x)+abs(y)>2*l) ans=0;
			else{
				if (y==2*l+1) ans=0;
				else
				if (n>=y+1+2*l) ans=1;
				else
				if (n<y+1) ans=0;
				else{
					ans=0;
					for(int i=y+1;i!=min(2*l+1,n+1);i++){
						if (i!=2*l) ans+=c[n][i];
						else{
							for(int j=2*l;j!=n+1;j++){
								ans+=c[j-1][2*l-1]*0.5;
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %.8lf\n",q,ans);
	}
	fclose(stdout);
	return 0;
}
