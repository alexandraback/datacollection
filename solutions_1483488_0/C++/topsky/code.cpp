#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 2200000;
const int B[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int cnt[MAXN];
int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T; cin >> T;
	
	for(int cas = 0; cas < T; cas++){
		printf("Case #%d: ", cas + 1);
		int l ,r , ans = 0;
		cin >> l >> r;
		int len = (int)(log(1.0 * r) / log(10.0)) + 1;
		//cout << len << endl;
		for(int i = 0; i < MAXN; i++ ){
			cnt[i] = -1;
		}
		for(int i = l; i < r; i++){
			for(int j = 1; j < len; j ++){
				int t = (i / B[j]) + (i % B[j]) * B[len - j];
				//cout << t << endl;
				if(t <= r && t > i && cnt[t] != i){
					++ ans;
					cnt[t] = i;
				}
			}
		}
		printf("%d\n", ans);
	}
}