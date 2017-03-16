#include <bits/stdc++.h>

using namespace std;

int d[1009];

int main(){
	freopen("B-small-attempt3.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&d[i]);
		}
		int cbest=1009;
		for(int i=1;i<=1000;i++){
			int cv=0;
			for(int j=0;j<n;j++){
				cv+=(d[j]-1)/i;
			}
			cbest=min(cbest,cv+i);
		}
		printf("Case #%d: %d\n",tcno,cbest);
	}
}
