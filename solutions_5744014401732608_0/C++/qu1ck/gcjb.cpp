#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cases = 0;
	scanf("%d",&cases);
	for(int casenum = 1; casenum <= cases; casenum++) {
		long long E[51]={0};
		E[0]=1;
		int n;
		long long m;
		scanf("%d%lld",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				E[j]+=E[i];
		if(E[n-1]<m){
			printf("Case #%d: IMPOSSIBLE\n", casenum);
			continue;
		} else {
			printf("Case #%d: POSSIBLE\n", casenum);
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n;j++){
				if(i>=j)printf("0");
				else if(j<n-1)printf("1");
				else if(i==0 && j==n-1)printf("1");
				else if(((1LL<<(i-1)) & (m-1)) > 0) printf("1");
				else printf("0");
			}
			puts("");
		}
		for(int i=0;i<n;i++)printf("0");
		puts("");


	}
	return 0;
}