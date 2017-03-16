#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <utility>
#include <cassert>
using namespace std;

int L;
long long X;
string s;
int dp[10003];
int Lm[5];
int a[5][5] = { {0,0,0,0,0},
				{0,1,2,3,4},
				{0,2,-1,4,-3},
				{0,3,-4,-1,2},
				{0,4,3,-2,-1}
				};

int map(char x) {
	if (x == 'i') return 2;
	if (x == 'j') return 3;
	if (x == 'k') return 4;
	assert(x == 'i');
	assert(x == 'j');
	assert(x == 'k');
}

int mult(int x, int y){
	int sign1 = (x < 0 ? -1 : 1);
	int sign2 = (y < 0 ? -1 : 1);
	x *= sign1;
	y *= sign2;
	assert(x > 0);
	assert(y > 0);
	int z = a[x][y];
	return sign1 * sign2 * z;
}

int main(){
	int TC;
	scanf("%d",&TC);
	for(int tt=1;tt<=TC;++tt){
		printf("Case #%d: ", tt);
		cin >> L;
		cin >> X;
		cin >> s;
		for(int i=0;i<L;++i){
			dp[i] = map(s[i]);
			if (i > 0) {
				dp[i] = mult(dp[i-1], dp[i]);
			}
		}
		for(int i = 0; i <= 4; ++i){
			if (i == 0) Lm[i] = 1;
			if (i > 0) Lm[i] = mult(Lm[i-1], dp[L-1]);
		}
		if (Lm[(X-1)%4LL+1] != -1) {
			printf("NO\n");
			continue;
		}
		bool completed = false;
		for (int m = 0; m <= 4; ++m){
			int Lf = -1 * mult(Lm[m],2);
			if (Lm[m] == 1 || Lm[m] == -1) Lf *= -1;
			int i = -1;
			for (int j = 0; j < L; ++j) {
				if (dp[j] == Lf) {
					i  = j+1;
					break;
				}
			}
			if (Lf == 1 && dp[L-1] == 1) i = 0;
			if (i == -1) continue;
			for(int n = 0; n <= 4; ++n) {
				int prev = -1 * mult( Lf, dp[L-1]);
				if (Lf == 1 || Lf == -1) prev *= -1;
				if (i == 0) prev = 1;
				int temp = mult(prev,Lm[n]);
				int Lr_ = -1 * mult(temp, 3);
				if (temp == 1 || temp == -1) Lr_ *= -1;
				bool ok = false;
				for (int j = 0; j < L; ++j) {
					if (dp[j] == Lr_) {
						ok = true;
						break;
					}
				}
				if (Lr_ == 1 && dp[L-1] == 1) ok = true;
				if (!ok) continue;
				for (int k=0; k <= 4; ++k){
					int Lr = -1 *mult(Lr_, dp[L-1]);
					if (Lr_ == 1 || Lr_ == -1) Lr *= -1;
					if (mult(Lr,Lm[k]) == 4) {
						int p = m + n + k;
						if (i != 0) p++;
						if (Lr != 1 || Lr_ != 1) p++;
						if (i == 0 && m == 0) continue;
						if (i == 0 && n == 0 && dp[L-1] == 1) p++;
						else if (i == 0 && n == 0 && dp[L-1] != 1) continue;
						if (Lr == 1 && Lr_ == 1 && k == 0) {
							if (dp[L-1] == 1) p++;
							else continue;
						}
						if (p <= X) {
							printf("YES\n");
							completed = true;
							break;
						}
					}
				}
				if (completed) break;
			}
			if(completed) break;
		}
		if(completed) continue;
		for(int n=0;n<=4;++n){
			for (int m = 0; m <=4; ++m) {
				int leftmost = 999999;
				int rightmost = -1;
				int left = -1 * mult(Lm[m], 2);
				if (Lm[m] == 1 || Lm[m] == -1) left *= -1;
				int right = -1 * mult(4, Lm[n]);
				if (Lm[n] == 1 || Lm[n] == -1) right *= -1;
				int check = -1 * mult(left, dp[L-1]);
				if (left == 1 || left == -1) check *= -1;
				check = -1 * mult(check, right);
				if (right == 1 || right == -1) check *= -1;
				if (check != 3) continue;
				for(int i = 0; i < L; ++i){
					if (dp[i] == left) {
						leftmost = i;
						break;
					}
				}
				for (int i = L-1; i >=1; --i){
					int tmp = -1 * mult(dp[i-1], dp[L-1]);
					if (dp[i-1] == 1 || dp[i-1] == -1) tmp *= -1;
					if (tmp == right) {
						rightmost = i;
						break;
					}
				}
				if (leftmost+1 < rightmost && m+n+1<=X) {
					printf("YES\n");
					completed = true;
					break;
				}
			}
			if(completed) break;
		}
		if (completed) continue;
		printf("NO\n");
	}
}