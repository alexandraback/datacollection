#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 155
#define maxh 3005
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

int tot[maxh];

int T,n;

int a[maxn];

int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	fo(i,1,T) {
		mem(tot,0);
		mem(a,0);
		scanf("%d",&n);
		fo(j,1,2*n-1)
			fo(k,1,n) {
				int x;
				scanf("%d",&x);
				tot[x]++;
			}
		fo(j,0,2500) if (tot[j] % 2==1) a[++a[0]]=j;
		sort(a+1,a+a[0]+1);
		printf("Case #%d: ",i);
		fo(i,1,a[0]) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}
