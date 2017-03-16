#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
int a[102][102];
int mxcol[102], mxrow[102];
int main(){
int t, i, j, k, n, m;
cin>>t;
for (k=1; k<=t; ++k){
	cin>>n>>m;
	for (i=0; i<n; ++i){
		for (j=0; j<m; ++j)	cin>>a[i][j];
	}
	for (i=0; i<n; ++i){
		int mx=0;
		for (j=0; j<m; ++j) mx=max(mx, a[i][j]);
		mxrow[i]=mx;
	}
	for (i=0; i<m; ++i){
		int mx=0;
		for (j=0; j<n; ++j) mx=max(mx, a[j][i]);
		mxcol[i]=mx;
	}
	bool cont=1;
	for (i=0; i<n; ++i){
			if (!cont) break;
		for (j=0; j<m; ++j){
			if (!cont) break;
			if (a[i][j]<mxcol[j] && a[i][j]<mxrow[i])
				cont=0;
		} 
	}
	printf("Case #%i: ", k); cout << (cont ? "YES\n" : "NO\n");
}
return 0;
}