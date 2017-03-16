#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int arr[101][101];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T; scanf("%d",&T);
	for(int test=1;test<=T;++test) {
		int n,m;
		scanf("%d%d",&n,&m);
		int r[101]={0},c[101]={0};
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j) {
				scanf("%d",&arr[i][j]);
				r[i]=max(r[i],arr[i][j]);
				c[j]=max(c[j],arr[i][j]);
			}
		bool ok=true;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if (arr[i][j]!=min(r[i],c[j])) ok=false;
		printf("Case #%d: ",test);
		puts(ok ? "YES" : "NO");
	}
	return 0;
}