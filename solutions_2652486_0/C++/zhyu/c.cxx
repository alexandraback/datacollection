#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

const int N = 100;

int n,t,r,m,k;
int p[N];
int cnt[N][N];
int val[N];
vector<int> v;

void init(void) {
	memset(cnt,0,sizeof(cnt));
	memset(val,0,sizeof(val));
	v.clear();
}

void deal(int j) {
	for(int i=2;i<=m;i++) {
		if(p[j]%i) continue;
		while(p[j]%i!=0) {
			p[j]/=i;
			cnt[i][j]++;
		}
	}
}

int main(void) {
	srand(time(NULL));
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #%d:\n",cas);
		while(r--) {
			for(int i=0;i<k;i++) scanf("%d",&p[i]);
			for(int i=0;i<k;i++) deal(i);
			for(int i=2;i<=m;i++)
				for(int j=0;j<k;j++) 
					if(cnt[i][j]!=0)
						val[i]+=n-cnt[i][j];
			sort(val,val+m);
			for(int i=m-1;i;i--) {
				if(val[i]==0) break;
				v.push_back(val[i]);
			}
			while(v.size()!=n) {
				v.push_back(rand()%(m-1)+2);
			}
			for(int i=0;i<n;i++)
				printf("%d",v[i]);
			puts("");
		}
	}
	return 0;
}
