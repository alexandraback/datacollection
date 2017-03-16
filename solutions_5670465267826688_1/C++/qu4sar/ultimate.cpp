#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
typedef long long ll;
int dp[N * 4];
int idp[N];

int arr[8][N], ai[9];
int dpk[8][9], ki[8];
int dpjk[8][9], jki[8];

int vk[N], vki;
#define I 2
#define J 3
#define K 4
int sign(int i){
	return i < 0 ? -1 : 1;
}
int f(int x, int y){
	if (x < 0 || y < 0)
		return f(abs(x), abs(y))*sign(x)*sign(y);
	if (x == 1) return y;
	if (y == 1) return x;
	if (x == y) return -1;
	switch (x){
	case I:
		if (y == J) return K;
		return -J;
		break;
	case J:
		if (y == I) return -K;
		return I;
	default:
		if (y == I) return J;
		return -I;
	}
}
int val(char x){
	switch (x){
	case 'i':return I;
	case 'j':return J;
	default:return K;
	}
}
int geti(int x){
	if (x < 0) return -x+3;
	else return x - 1;
}
inline void precompute(int i, int val){
	int z=0;
	switch (val){
	case 1:
		z = J;
		break;
	case -1:
		z = -J;
		break;
	case I:
		z = K;
		break;
	case -I:
		z = -K;
		break;
	case J:
		z = 1;
		break;
	case -J:
		z = -1;
		break;
	case K:
		z = -I;
		vk[vki++] = i;
		break;
	case -K:
		z = I;
		break;
	}
	int in = geti(z);
	arr[in][ai[in]++] = i;
}
int main(){
	ll t, l, x;
	char s[N];
	int ends[5];

	
	cin >> t;

	for (int cs = 1; cs <= t; cs++){
		int mx = 0;
		cin >> l >> x;
		cin >> s;

		memset(dp, 0, sizeof(dp));
		memset(idp, 0, sizeof(idp));
		memset(dpk, 0, sizeof(dpk));
		memset(dpjk, 0, sizeof(dpjk));
		fill(ai, ai + 8, 0);
		fill(ki, ki + 8, 0);
		fill(jki, jki + 8, 0);

		
		vki = 0;

		dp[0] = val(s[0]);
		ll di = 1;
		precompute(0, dp[0]);
		
		for (int z = 0; z < 4; z++){
			if (z>0){
				dp[di] = f(dp[di - 1], val(s[0]));
				precompute(di, dp[di]);
				di++;
			}
			for (int i = 1; i < l; i++, di++){
				dp[di] = f(dp[di - 1], val(s[i]));
				precompute(di, dp[di]);
			}
		}
		idp[l] = 1;
		for (int i = l - 1; i >= 0; i--){
			idp[i] = f(val(s[i]), idp[i + 1]);
		}
		
		ends[0] = 1;
		ends[1] = dp[l - 1];
		ends[2] = dp[l + l - 1];
		ends[3] = dp[l + l + l - 1];
		ends[4] = dp[l + l + l + l - 1];
		
		di = min(di, l*x);
		
		int e[] = { 1, I, J, K, -1, -I, -J, -K };
		
		
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 5; j++){
				dpk[i][j] = f(e[i], ends[j])==K;
			}
		}
		
		for (int i = 0; i < 8; i++){
			for (int en = 0; en < 5; en++){
				int C = f(e[i], ends[en]);
				int *a = arr[geti(C)];
				int len = ai[geti(C)];
				for (int jj = 0; jj < len; jj++){
					int j = a[jj];
					if (j >= di)break;
					int used = en + 1 + (j) / l;
					int ri = j%l + 1;
					int r = idp[ri];
					int rii = geti(r);
					for (int w = 0; w < 5; w++){
						if (dpk[rii][w])
						{
							int u = used + w;
							for (; u <= 8; u += 4)
								dpjk[i][u] = true;
						}
					}
				}
			}
		}
		bool ansb = false;
		
		for (int i = 0; i < di; i++){
			if (dp[i] == I){
				int used = i / l+1;

				for (int wi = 0; wi < vki;wi++){
					int w = vk[wi];
					if (w <= i)continue;
					if (w >= l) break;
					int ri = w%l + 1;
					int r = idp[ri];
					int rii = geti(r);
					int X = (x - used) % 4;
					if (X == 0 && x - used>4)X = 4;
					if (dpk[rii][X]){
						ansb = true;
						break;
					}
				}

				int ri = i%l + 1;
				int r = idp[ri];
				int rii = geti(r);
				int X = (x - used) % 8;
				if (X == 0 && x - used>8)X = 8;
				if (dpjk[rii][X])
				{
					ansb = true;
					break;
				}
			}
		}
		string ans = "NO";
		if (ansb) ans = "YES";
		cout << "Case #" << cs << ": " << ans << endl;
	}
}