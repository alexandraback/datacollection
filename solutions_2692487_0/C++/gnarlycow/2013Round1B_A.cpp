//============================================================================
// Name        : 2013Round1B_A.cpp
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
#include <algorithm>
using namespace std;

int n;
int d[111];

int f(int num, int start) {
	if(start>=n) return 0;
	if(num>d[start]) return f(num+d[start],start+1);
	int ans = 1+f(num,start+1);
	if(num<=1) return ans;
	int cnt = 0;
	while(num<=d[start]) {
		++cnt;
		num = num+num-1;
	}
	ans = min(ans, cnt+f(num+d[start],start+1));
	return ans;
}

int main() {
	freopen("output.txt","w",stdout);
	int ncases;
	cin>>ncases;
	for(int cid=1;cid<=ncases;++cid) {
		int orig;
		cin>>orig>>n;
		for(int i=0;i<n;++i) cin>>d[i];
		sort(d,d+n);
		//for(int i=0;i<n;++i) cout<<d[i]<<endl;
		printf("Case #%d: %d\n", cid, f(orig,0));
	}
	return 0;
}
