#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int n,m,t,cur,ans;
int a[105];

int main(){
	int t;
	scanf("%d",&t);
	FOE(T,1,t){
		scanf("%d%d",&cur,&n);
		FOR(i,0,n) scanf("%d",&a[i]);
		sort(a,a+n);

		int count = 0;
		ans = n;
		if (cur != 1){
			int i=0;
			while (i<n){
				if (cur > a[i]){
					cur += a[i];
					++i;
				}
				else{
					if ((count + (n-i)) < ans) ans = count + (n-i);

					cur += (cur-1);
					++count;
				}
			}
			printf("Case #%d: %d\n",T,min(count,ans));
		}
		else printf("Case #%d: %d\n",T,n);
	}
	return 0;
}
