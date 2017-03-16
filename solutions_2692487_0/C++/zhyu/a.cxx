#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 111;
int v[N];

int main() {
	int n,t,a;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		scanf("%d%d",&a,&n);
		for(int i=0;i<n;i++) scanf("%d",v+i);
		printf("Case #%d: ",cas);
		sort(v,v+n);
		int pos=n;
		for(int i=0;i<n;i++) {
			if(a>v[i]) a+=v[i];
			else {
				pos=i;
				break;
			}
		}
		if(pos==n) {
			puts("0");
			continue;
		}
		int res=n;
		for(int ed=pos;ed<=n;ed++) {
			int cnt=n-ed;
			int aa=a;
			for(int i=pos;i<ed&&cnt<n;i++) {
				while(cnt<n&&aa<=v[i]) {
					aa=(aa<<1)-1;
					cnt++;
				}
				aa+=v[i];
			}
			res=min(res,cnt);
		}
		printf("%d\n",res);
	}
	return 0;
}
