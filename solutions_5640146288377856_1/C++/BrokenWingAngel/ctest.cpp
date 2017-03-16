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
#include <cstring>
#include <cstdio>

using namespace std;

#define for1(i,a,b) for(i=a;i<=b;i++)

const int maxn =1000003;

int t,n,m,w;
int f[233][2];

int work(){
	int i,j;
	memset(f,0,sizeof(f));
	for1(i,w,m){
		f[i][0]=f[i][1]=233;
		for1(j,1,i){
			int hit=0;
			if (w==i || j==1 || j==i){
				hit=w;
			}else{
				hit=w+1;
			}
			f[i][1]=min(f[i][1],max(hit,1+min(max(f[j-1][1],f[j-1][0]+f[i-j][1]),max(f[i-j][1],f[j-1][1]+f[i-j][0]))));
			f[i][0]=min(f[i][0],1+f[j-1][0]+f[i-j][0]);
		}
		//cout<<f[i][0]<<' '<<f[i][1]<<' '<<i<<endl;
	}
	//cout<<f[m][0]<<' '<<f[m][1]<<endl;
	return f[m][1];
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	int i;
	for1(i,1,t){
		cin>>n>>m>>w;
		work();
		printf("Case #%d: %d\n",i,f[m][0]*(n-1)+f[m][1]);
	}
	return 0;
}
