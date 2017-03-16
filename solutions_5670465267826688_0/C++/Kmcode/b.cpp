#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<valarray>
using namespace std;
int a[5][5];
#define MAX 100001
bool dp[MAX][3][9];
bool use[MAX][3][9];
string s;
int n = 0;
int en(int num){  //moto
	if (num < 4){
		num = -num;
		num--;
		return num;
	}
	num -= 3;
	return num;
}
int de(int num){
	if (num > 0){
		return num + 3;
	}
	else{
		return abs(num) - 1;
	}
}
inline bool dfs(int aa, int b, int c){
	if (aa == n){
		if (b == 3){
			if (en(c) == b + 1){
				return true;
			}
		}
		return false;
	}
	if (b == 3){
		return false;
	}
	if (use[aa][b][c]){
		return dp[aa][b][c];
	}
	use[aa][b][c] = true;
	int ich = aa%s.size();
	int num;
	if (s[ich] == 'j'){
		num = 3;
	}
	if (s[ich] == 'i'){
		num = 2;
	}
	if (s[ich] == 'k'){
		num = 4;
	}
	if (en(c) == b + 1){
		dp[aa][b][c] |= dfs(aa + 1, b + 1, de(num));
	}
	dp[aa][b][c] |= dfs(aa + 1, b, de(a[en(c)][num]));
	return dp[aa][b][c];
}
int nu(int ich){
	ich %= s.size();
	if (s[ich] == 'j'){
		return 3;
	}
	if (s[ich] == 'i'){
		return 2;
	}
	if (s[ich] == 'k'){
		return 4;
	}
	return 1;
}
int multy(int aa, int b){
	if (aa > 0 && b > 0){
		return a[aa][b];
	}
	int mul = 1;
	if (aa < 0){
		mul *= -1;
	}
	if (b < 0){
		mul *= -1;
	}
	aa = abs(aa);
	b = abs(b);
	return a[aa][b] * mul;
}
int main(){
	a[1][1] = 1;
	a[1][2] = 2;
	a[1][3] = 3;
	a[1][4] = 4;
	a[2][1] = 2;
	a[2][2] = -1;
	a[2][3] = 4;
	a[2][4] = -3;
	a[3][1] = 3;
	a[3][2] = -4;
	a[3][3] = -1;
	a[3][4] = 2;
	a[4][1] = 4;
	a[4][2] = 3;
	a[4][3] = -2;
	a[4][4] = -1;
	int t;
	int r = 0;
	scanf("%d", &t);
	while (t--){
		r++;
		memset(dp, false, sizeof(use));
		int m, k;
		scanf("%d%d", &m, &k);
		n = m*k;
		cin >> s;
		dp[0][0][de(nu(0))] = true;
		for (int i = 0; i + 1 < n; i++){
			for (int j = 0; j < 3; j++){
				for (int k = 0; k < 9; k++){
					if (dp[i][j][k]){
						int nex = nu(i + 1);
						int ge = en(k);
						nex = multy(ge, nex);
						nex = de(nex);
						dp[i + 1][j][nex] = true;
						if (ge == j + 2 && j<2){
							nex = nu(i + 1);
							nex = de(nex);
							dp[i + 1][j + 1][nex] = true;
						}
					}
				}
			}
		}
		printf("Case #%d: ", r);
		if (dp[n - 1][2][de(4)] == true){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}