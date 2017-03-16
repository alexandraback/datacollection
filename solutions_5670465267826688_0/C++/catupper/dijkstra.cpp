#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string str;
int n, t, l, x;
int val[108000];
#define I 2
#define J 3
#define K 4

int mult(int x, int y){
	int res = 1;
	if(x < 0){
		res *= -1;
		x *= -1;
	}
	if(y < 0){
		res *= -1;
		y *= -1;
	}
	if(x == 1 && y == 1)return res * 1;
	if(x == 1 && y == I)return res * I;
	if(x == 1 && y == J)return res * J;
	if(x == 1 && y == K)return res * K;
	if(x == I && y == 1)return res * I;
	if(x == I && y == I)return res * -1;
	if(x == I && y == J)return res * K;
	if(x == I && y == K)return res * -J;
	if(x == J && y == 1)return res * J;
	if(x == J && y == I)return res * -K;
	if(x == J && y == J)return res * -1;
	if(x == J && y == K)return res * I;
	if(x == K && y == 1)return res * K;
	if(x == K && y == I)return res * J;
	if(x == K && y == J)return res * -I;
	if(x == K && y == K)return res * -1;
}

int powe(int x, int p){
	if(p == 0)return 1;
	int res = powe(x, p / 2);
	res = mult(res, res);
	if(p % 2 == 1)res = mult(res, x);
	return res;
}

string solve(){
	cin >> l >> x;
	cin >> str;
	int pro = 1;
	for(int i = 0;i < l;i++){
		if(str[i] == 'i')val[i] = I;
		if(str[i] == 'j')val[i] = J;
		if(str[i] == 'k')val[i] = K;
		pro = mult(pro, val[i]);
	}
	if(powe(pro, x) != mult(I, mult(J, K)))return "NO";
	int lpro = 1, llen = 1 << 29;
	for(int i = 1;i < 5;i++){
		if(powe(pro, i) == I)llen = min(llen, i * l);
	}
	for(int i = 0;i < l;i++){
		lpro = mult(lpro, val[i]);
		for(int j = 0;j < 5;j++){
			if(mult(powe(pro, j), lpro) == I){
				llen = min(llen, i + 1 + j * l);
			}
		}
	}
	int rpro = 1, rlen = 1 << 29;
	for(int i = 1;i < 5;i++){
		if(powe(pro, i) == K)rlen = min(rlen, i * l);
	}
	for(int i = 0;i < l;i++){
		rpro = mult(val[l - 1 - i], rpro);
		for(int j = 0;j < 5;j++){
			if(mult(rpro, powe(pro, j)) == K){
				rlen = min(rlen, i + 1 + j * l);
			}
		}
	}
	if(llen + rlen < l * x)return "YES";
	else return "NO";
}

int main(){
	cin >> t;
	for(int i = 1;i <= t;i++){
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}