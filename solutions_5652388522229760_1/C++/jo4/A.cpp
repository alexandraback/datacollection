#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

bool vis[10];
int cnt;

bool add(int x) {
	while(x) {
		if(!vis[x%10])
			vis[x%10]=1, cnt++;
		x/=10;
	}
	if(cnt==10)
		return true;
	return false;
}

const int tre=1000;

int go(int x) {
	fill(vis,vis+10,0);
	cnt=0;
	for(int t=1;t<=tre;t++) {
		if(add(x*t))
			return x*t;
	}
	assert(x==0);
	return -1;
}

int main() {
	int all_kase,N;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		scanf("%d",&N);
		int ans=go(N);
		printf("Case #%d: ",num_kase);
		if(ans==-1)
			puts("INSOMNIA");
		else
			printf("%d\n",ans);
	}
	return 0;
}
