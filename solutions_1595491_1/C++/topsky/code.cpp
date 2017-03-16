#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 120;
bool cmp(const int& a, const int& b){
	return a > b;
}

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T; cin >> T;
	for(int cas = 0; cas < T; cas++){
		printf("Case #%d: ", cas + 1);
		int N, S, p, ans = 0, Num = 0, c;
		int score[MAXN];
		cin >> N >> S >> p;
		for(int i = 0; i < N; i++){
			cin >> c;
			if(c < 2 || c > 28){
				if(c >= 3 * p - 2){
					ans ++;
				}
			}else{
				score[Num ++] = c;
			}
		}
		sort(score, score + Num, cmp);
		for(int i = 0; i < Num; i++){
			if(score[i] >= 3 * p - 2){
				++ ans;
			}else{
				if(S > 0){
					-- S;
					if(score[i] >= 3 * p - 4){
						++ ans;
					}else{
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}