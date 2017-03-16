#include <bits/stdc++.h>

char s[1009];
int d[1009];

using namespace std;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int n;scanf("%d",&n);
		scanf("%s",s);
		for(int i=0;i<=n;i++)d[i]=s[i]-'0';
		int cmax=0;
		int csum=0;
		for(int i=0;i<=n;i++){
			cmax=max(cmax,i-csum);
			csum+=d[i];
		}
		printf("Case #%d: %d\n",tcno,cmax);
	}
}
