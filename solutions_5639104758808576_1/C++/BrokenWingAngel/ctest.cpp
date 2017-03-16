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

int main() {
	//freopen("A-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>t;
	int i;
	for1(i,1,t){
		cin>>n;
		int j;
		int ans=0,s=0;
		char c;
		scanf("%c",&c);
		for1(j,0,n){
			scanf("%c",&c);
			int v=c-'0';
			if (j>s){
				ans+=j-s;
				s+=j-s;
			}
			s+=v;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
