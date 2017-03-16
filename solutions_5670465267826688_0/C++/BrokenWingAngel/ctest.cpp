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

const int maxn =1000003;

int t,n,m;
int tr[7][7];
int a[maxn],lx[maxn],rx[maxn];
bool rk[maxn];

int calc(int a, int b){
	int sign = 1;
	if (a<0) sign*=-1;
	if (b<0) sign*=-1;
	return sign*tr[abs(a)][abs(b)];
}

bool work(){
	if (n*m < 3) return false;
	int i;
	for1(i,1,n){
		int j;
		for1(j,1,m){
			a[j*n+i]=a[i];
		}
	}
	n*=m;
	lx[1]=a[1];
	rx[n]=a[n];
	rk[n]=(a[n]==4);
	for1(i,2,n){
		lx[i]=calc(lx[i-1],a[i]);
		rx[n-i+1]=calc(a[n-i+1],rx[n-i+2]);
		rk[n-i+1]=rk[n-i+2]|(rx[n-i+1]==4);
	}
	if (lx[n]!=-1) return false;
	for1(i,1,n-2){
		if (lx[i]==2 && rx[i+1]==2 && rk[i+2]) return true;
	}
	return false;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	tr[1][1]=1;	tr[1][2]=2;	tr[1][3]=3;	tr[1][4]=4;
	tr[2][1]=2; tr[2][2]=-1; tr[2][3]=4; tr[2][4]=-3;
	tr[3][1]=3; tr[3][2]=-4; tr[3][3]=-1; tr[3][4]=2;
	tr[4][1]=4; tr[4][2]=3; tr[4][3]=-2; tr[4][4]=-1;

	cin>>t;
	int i;
	for1(i,1,t){
		long long tmp;
		cin>>n>>tmp;
		if (tmp>20) m=tmp%20+20; else m=(int)tmp;
		int j;
		scanf("\n");
		for1(j,1,n){
			char c;
			scanf("%c",&c);
			a[j]=c-'i'+2;
		}
		printf("Case #%d: %s\n",i,work()?"YES":"NO");
	}
	return 0;
}
