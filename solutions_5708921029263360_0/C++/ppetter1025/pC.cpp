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

void shuffle(vector<PII> &v) {
	for(int i=1; i<SZ(v); i++) {
		int k = rand() % i;
		swap(v[i], v[k]);
	}
}

struct Data {
	int a, b, c;
};
vector<Data> ans2, tmp;

int go(int J, int P, int S, int K) {
	vector<PII> v1;
	for(int k=0; k<K; k++) {
		for(int i=1; i<=J; i++)
			for(int j=1; j<=P; j++)	v1.PB(MP(i, j));
	}

	shuffle(v1);

	int c1[20][20], c2[20][20], c3[20][20];
	bool RRR[20][20][20];
	fill(c1[0], c1[20], 0);
	fill(c2[0], c2[20], 0);
	fill(c3[0], c3[20], 0);
	fill(RRR[0][0], RRR[15][15], false);
	
	int cnt = 0, ret = 0;
	for(int i=0; i<SZ(v1); i++) {
		int a = v1[i].F, b = v1[i].S;
		int x;
		while(1) {
			x = rand() % S + 1;
			if(c2[a][x] < K && c3[b][x] < K && !RRR[a][b][x])	break;
			else	cnt++;

			if(cnt > 50)	return ret;
		}

		c1[a][b]++;
		c2[a][x]++;
		c3[b][x]++;
		RRR[a][b][x] = true;
		ret++;
		tmp.PB((Data) {a, b, x});
	}

	return ret;
}

int main() {
	srand(7122);

	int t;
	scanf("%d", &t);
	for(int kase=1; kase<=t; kase++) {
		int j, p, s, k;
		scanf("%d%d%d%d", &j, &p, &s, &k);
		
		int times = 30000, ans = 0;
		while(times--) {
			if(ans < go(j, p, s, k)) {
				ans = SZ(tmp);
				ans2 = tmp;
			}
			tmp.clear();
		}

		printf("Case #%d: %d\n", kase, ans);
		for(int i=0; i<ans; i++)	printf("%d %d %d\n", ans2[i].a, ans2[i].b, ans2[i].c);
		ans2.clear();
	}
    
    return 0;
}
