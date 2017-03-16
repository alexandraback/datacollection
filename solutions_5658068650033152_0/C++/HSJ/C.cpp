#include<stdio.h>
#include<algorithm>
using namespace std;

int min(int a,int b){
	if(a<b) return a;
	return b;
}
int main()
{
	freopen("C-small-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,t2;
	int n,m,k,i,j,p,q;
	int ans;
	scanf("%d",&t2);
	for(t=1;t<=t2;t++){
		ans = 10000000;
		scanf("%d%d%d",&n,&m,&k);
		if(n>m) swap(n,m);
		//printf("%d %d %d\n",n,m,k);
		if(k<=2*m && ans>k) ans = k;
		for(i=3;i<=n;i++){
			if(k>i*m) continue;
			p = i;
			for(j=i-2;j>=0;j-=2) p += 2*j;
			if(p>=k){
				if(ans > 2*(i-1)) ans = 2*(i-1);
				continue;
			}
			q = 2*(i-1);
			for(j=(i-1)/2*2;j<=m;j++){
				if(p>=k){
					if(ans > q) ans = q;
					break;
				}
				if(p+(i-1)/2 >= k){
					if(ans > q+1) ans = q+1;
					break;
				}
				if(j==m) break;
				p += i, q += 2;
			}
			if(p>=k) continue;
			for(j=(i-1)/2;j>0;j--){
				p+=j, q++;
				if(p>=k){
					if(ans > q) ans = q;
					break;
				}
				p+=j, q++;
				if(p>=k){
					if(ans > q) ans = q;
					break;
				}
				p+=j, q++;
				if(p>=k){
					if(ans > q) ans = q;
					break;
				}
				p+=j, q++;
				if(p>=k){
					if(ans > q) ans = q;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}