//============================================================================
// Name        : ctest.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cstdio>

using namespace std;

#define for1(i,a,b) for(i=a;i<=b;i++)

int t,n;
int a[1111];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>t;
	int i;
	for1(i,1,t){
		cin>>n;
		int j;
		int x=1,y=1;
		for1(j,1,n){
			int v;
			scanf("%d",&v);
			a[j]=v;
			y=max(y,v);
		}
		int ans=y;
		for1(x,1,y){
			int k;
			int tmp = x;
			for1(k,1,n){
				tmp += (a[k]-1)/x;
				if (tmp > ans) break;
			}
			ans = min(ans,tmp);
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
