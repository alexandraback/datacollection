#include <iostream>

#define N 100010
#define X 4

using namespace std;

int Si[2 * X + 10], Sj[2 * X + 10], Sk[2 * X + 10];
int tmpi[2 * X + 10], tmpj[2 * X + 10], tmpk[2 * X + 10];

int T[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

int Mul(int i, int j) {
	if(i > 0 && j > 0) {
		return T[i][j];
	}else if(i < 0 && j < 0) {
		return T[-i][-j];
	}else if(i < 0) {
		return -T[-i][j];
	}else {
		return -T[i][-j];
	}
}
int val(char ch) {
	if(ch == 'i') return 2;
	if(ch == 'j') return 3;
	if(ch == 'k') return 4;
	return -1;
}
int main() {
	
	freopen("Csmall.in", "r", stdin);
	freopen("Csmall.out", "w", stdout);
	
	int t;
	cin >> t;
	for(int C = 1;C <= t;C++) {
		int l;
		long long x;
		string str;
		cin >> l >> x >> str;
		if(x > 12ll) {
			x %= 12ll;
			x += 12ll;
		}
		
		for(int i = -X;i <= X;i++) {
			Si[i + X] = Sj[i + X] = Sk[i + X] = 0;
		}
		Si[1 + X] = 1;
		for(int i = 0;i < x*l;i++) {
			for(int j = -X;j <= X;j++) {
				tmpi[j + X] = tmpj[j + X] = tmpk[j + X] = 0;
			}
			for(int j = -X;j <= X;j++) {
				if(Si[j + X]) {
					int y = Mul(j, val(str[i%l]));
					tmpi[Mul(j, val(str[i%l])) + X] = 1;
				}
				if(Sj[j + X]) {
					tmpj[Mul(j, val(str[i%l])) + X] = 1;
				}
				if(Sk[j + X]) {
					tmpk[Mul(j, val(str[i%l])) + X] = 1;
				}
			}
			for(int j = 0;j <= 2*X;j++) {
				Si[j] = tmpi[j];
				Sj[j] = tmpj[j];
				Sk[j] = tmpk[j];
			}
			if(Si[val('i') + X] == 1) {
				Sj[1 + X] = 1;
			}
			if(Sj[val('j') + X] == 1) {
				Sk[1 + X] = 1;
			}
		}
		cout << "Case #" << C << ": " << (Sk[val('k') + X] ? "YES" : "NO") << endl;
	}
}
