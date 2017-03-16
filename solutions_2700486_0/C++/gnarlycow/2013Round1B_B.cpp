//============================================================================
// Name        : 2013Round1B_B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int layer;

double f(int num, int y, int a, int b) {

	double ans = -1.0;
	if(y<=b) {
		//cout<<num<<' '<<y<<' '<<a<<' '<<b<<' '<<1<<' '<<endl;
		ans = 1.0;
	} else if(num>0) {
		if(a<layer*2-1&&b<layer*2-1) ans = (f(num-1,y,a+1,b)+f(num-1,y,a,b+1))*.5;
		else if(a<layer*2-1) ans = f(num-1,y,a+1,b);
		else if(b<layer*2-1) ans = f(num-1,y,a,b+1);
	} else {
		ans = 0.0;
	}
	//cout<<num<<' '<<y<<' '<<a<<' '<<b<<':'<<ans<<endl;
	return ans;
}

int main() {
	freopen("output.txt","w",stdout);
	int ncases;
	cin>>ncases;
	for(int cid=1;cid<=ncases;++cid) {
		int n,x,y;
		cin>>n>>x>>y;
		if(x<0) x = -x;
		layer = (x+y)/2;
		long long num = 0, cur = 1;
		for(int i=0;i<layer;++i) {
			num += cur;
			cur += 4;
		}
		printf("Case #%d: ", cid);
		if(n<=num) printf("0\n");
		else if(num+cur<=n) printf("1\n");
		else {
			cout<<f(n-num,y,-1,-1)<<endl;
		}
	}
	return 0;
}
