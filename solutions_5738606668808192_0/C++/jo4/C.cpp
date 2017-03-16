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

const int MAXN=50;
const int MAXJ=550;

const int TH=10;

int N,J;
int in[MAXN];
int cnt=0;

void go(int l) {
	if(cnt>=J)
		return;
	if(l>=N-2) {
		for(int i=N-1;i>=0;i--)
			printf("%d",in[i]);
		for(int i=2;i<=10;i++)
			printf(" %d",i+1);
		puts("");
		cnt++;
		return;
	}
	go(l+2);
	in[l]^=1;
	in[l+1]^=1;
	go(l+2);
}

int main() {
	int all_kase;
	scanf("%d",&all_kase);
	for(int num_kase=1;num_kase<=all_kase;num_kase++) {
		scanf("%d%d",&N,&J);
		printf("Case #%d:\n",num_kase);
		cnt=0;
		in[0]=in[N-1]=1;
		go(1);
	}
	return 0;
}
