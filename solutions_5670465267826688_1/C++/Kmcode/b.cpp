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
int w(int i, int j){
	//	cout << i * 9 + j << endl;
	return i * 10 + j;
}
int DP[41];
int nex[41];
vector<vector<int> > mul(vector<vector<int> > &a, vector<vector<int> > &b){
	vector<vector<int> > c(a.size(), vector<int>(b[0].size()));
	for (int i = 0; i < a.size(); i++){
		for (int k = 0; k < b.size(); k++){
			for (int j = 0; j < b[0].size(); j++){
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
				c[i][j] = min(c[i][j], 1);
			}
		}
	}
	return c;
}
vector<vector<int> > ppow(vector<vector<int> > a, long long int n){
	vector<vector<int> > b = a;
	n--;
	while (n){
		if ((n & 1LL)){
			b = mul(b, a);
		}
		a = mul(a, a);
		n >>= 1LL;
	}
	return b;
}
vector < vector<int> > ma;
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
		ma.clear();
		ma.assign(31, vector<int>(31));
		r++;
		long long int m, k1;
		scanf("%lld%lld", &m, &k1);
		cin >> s;
		for (int i1 = 0; i1 < 3; i1++){
			for (int jj = 0; jj <9; jj++){
				memset(dp, false, sizeof(dp));
				dp[0][i1][jj] = true;
				for (int i = 0; i < m; i++){
					for (int j = 0; j < 3; j++){
						for (int k = 0; k < 9; k++){
							if (dp[i][j][k]){
								int nex = nu(i);
								int ge = en(k);
								nex = multy(ge, nex);
								nex = de(nex);
								dp[i + 1][j][nex] = true;
								if (ge == j + 2 && j < 2){
									nex = nu(i);
									nex = de(nex);
									dp[i + 1][j + 1][nex] = true;

								}
							}
						}
					}
				}
				for (int j = 0; j < 3; j++){
					for (int k = 0; k < 9; k++){
						ma[w(j, k)][w(i1, jj)] = (int)dp[m][j][k];
					}
				}
			}
		}
		printf("Case #%d: ", r);
		memset(nex, 0, sizeof(nex));
		memset(DP, 0, sizeof(DP));
		DP[w(0, de(1))] = 1;
		ma = ppow(ma, k1);
		for (int j = 0; j < 30; j++){
			for (int k = 0; k < 30; k++){
				nex[j] += DP[k] * ma[j][k];
			}
		}
		for (int j = 0; j < 30; j++){
			DP[j] = nex[j];
		}
		if (DP[w(2, de(4))]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}