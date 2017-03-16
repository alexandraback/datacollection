#include <bits/stdc++.h>
#include <unordered_map>
#include <initializer_list>
#include <memory>
#include <vector>
#define mp make_pair
#define pb push_back
#define lo int
#define li long long int
#define db double

#define sz(a) (lo)(a).size()
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
#define DEB(...) fprintf(stderr, __VA_ARGS__)

//=======================
//#define pi 3.14159265358979323
#define eps 1e-9
#define INF 2e9
#define MN 1010
#define SM 2000
//=====================================================


int dp[MN][MN];
void cnt_dp(){
	for(int i = 2; i < MN; i++){
		for(int j = 1; j < i; j++){
			dp[i][j] = INF;
			for(int k = 1; k < i; k++){
				dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
			}
		}
	}
	cout << MN << endl;
	FOR(i, MN) FOR(j, MN){
		printf("%d ", dp[i][j]);
		if(j == MN - 1)
			printf("\n");
	}
}

void read_dp(){
	freopen("help.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	FOR(i, n) FOR(j, n){
		scanf("%d", &dp[i][j]);
	}
	fclose(stdin);
}
int main()
{
read_dp();
#ifdef MYLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("matan.in", "r", stdin);
//    freopen("matan.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T;i++){
    	int n;
    	scanf("%d", &n);
    	vector<int> cake(n);
    	FOR(j, n){
    		scanf("%d", &cake[j]);
    	}
    	sort(all(cake));
    	reverse(all(cake));
    	int ans = INF;
    	for(int j = 1; j <= cake[0]; j++){
    		int with = 0;
    		FOR(k, n){
    			with += dp[cake[k]][j];
    		}
    		ans = min(ans, with + j);
    	}
    	printf("Case #%d: %d\n", i, ans);
    }
};

