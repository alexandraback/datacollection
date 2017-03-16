#include<cstdio>
#include<algorithm>
#include<queue>

#define N 10005
using namespace std;

int tc;
int e, r, n;
int ans, ansn;
int data[N], mxt[N];
int t[N][6];
struct ele{
	int x, t;
	bool operator < (ele a) const{
		return t > a.t;
	};
};

int main(){
	//freopen("input.txt", "r", stdin);
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	//freopen("output.txt", "w", stdout);
	int i,j,k,l;
	int tcc = 0;
	scanf("%d", &tc);
	while(tc--){
		memset(t, 0, sizeof(t));
		scanf("%d %d %d", &e, &r, &n);

		if (r > e) {
			r = e;
		}
		for(i = 0; i < n;i++){
			scanf("%d", &data[i]);
		}
		int maxi = 0;
		long long sum = data[0];
		for(i = 1; i < n;i++){
			if (data[maxi] < data[i])
				maxi = i;
			sum+=data[i];
		}
		ans = sum*r + (e-r)*data[maxi];
//		printf("Case #%d: %lld\n", ++tcc, ans);

		for (i = 0; i < n; i++){ // table[i+1]
			for (j = 0; j <= e; j++){ // use j
				for (k = j; k <= e; k++){ // table[i][k] 
					l = k - j + r;
					if (l > e) l = e;
					t[i+1][l] = max(t[i+1][l], t[i][k]+j*data[i]);
				}
			}
		}
		ansn = t[n][0];
		for(i = 1; i <= e; i++)
			ansn = max(ansn, t[n][i]);
		if (ans != ansn){
			ansn = ansn;
		}
		printf("Case #%d: %lld\n", ++tcc, ansn);
	}
	return 0;
}