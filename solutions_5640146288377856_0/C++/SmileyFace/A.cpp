#include <bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;



int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int r,c,n;scanf("%d%d%d",&r,&c,&n);// ship takes up n columnns
		int ans2=c/n;
		int ans=r*(ans2)+(n-1);
		if(c%n)ans++;
		printf("Case #%d: %d\n",tcno,ans);
	}
}
