#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

long long f[10000001];
int check(long long a){
	int num[20], i, j, len;
	for (len = 0; a; len++){
		num[len] = a % 10;
		a /= 10;
	}
	for (i = 0, j = len - 1; i < j; i++, j--){
		if (num[i] != num[j]) break;
	}
	if (i < j) return 0;
	else return 1;
}

long long calc(long long a){
	long long i, p, ret = 0;
	if (a <= 0) return 0;
	p = sqrt(a);
	return f[p];
}

int main(){
	long long k, a, b, T, ans;
//	freopen("C-large-1.in", "r", stdin);
//	freopen("C-1.out", "w", stdout);
	f[0] = 0;
	for (a = 1; a <= 10000000; a++){
		f[a] = f[a - 1];
		if (check(a) && check(a * a)) f[a]++;
	}
	cin >> T;
	for (k = 1; k <= T; k++){
		cin >> a >> b;
		ans = calc(b) - calc(a - 1);
		cout << "Case #" << k << ": " << ans << endl;
	}
	return 0;
}
