#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 1005

int T,n,a[N];
char s[N];

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	scanf("%d",&T);
	rep(tcase,1,T){
		printf("Case #%d: ",tcase);
		scanf("%d",&n);
		scanf("%s",s);
		rep(i,0,n) a[i]=s[i]-'0';
		int cnt=0;
		rep(i,1,n){
			if(a[i-1]<i) cnt+=i-a[i-1],a[i-1]=i;
			a[i]+=a[i-1];
		}
		printf("%d\n",cnt);
	}
}
