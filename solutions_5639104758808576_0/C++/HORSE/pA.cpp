#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N_MAX = 1005;
char str[N_MAX];

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("pA_small.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt++){
		int n, ans = 0, aud = 0;
		scanf("%d %s", &n, str);
		for(int i = 0; i <= n; i++){
			int val = str[i] - '0';
			if(val && aud < i){
				ans += i - aud;
				aud += i - aud;
			}
			aud += val;
		}
		printf("Case #%d: %d\n", cnt, ans);
	}
	return 0;
}
