#include<cstdio>
#include<iostream>
using namespace std;
const int N = 2000012;

int x[10];
int y[10];
int digit[N];
int e10[10];

void init_digit(){
	int i, n;
	for(i = 0; i < N; i++){
		n = i;
		digit[i] = 1;
		while((n /= 10) > 0){
			digit[i] += 1;
		}
	}
	e10[0] = 1;
	for(i = 1; i < 10; i++)
		e10[i] = e10[i-1] * 10;
}

int test(int n0, int A, int B){
	int k = 0;
	int n = n0;
	int n1;
	int d = digit[n0];
	int ans = 0;
	int anss[7];
	int i;
	n = n0;
	x[0] = 0; y[0] = n;
	for(k = 1; k < d; k++){
		x[k] = (n % 10) * e10[k-1] + x[k-1];
		n /= 10;
		y[k] = n;
		n1 = x[k] * e10[d - k] + y[k];
		if(n1 <= B and n1 > n0 and digit[n1] == d){
			//cout << "match: " << n0 << '\t' << n1 << endl;
			anss[ans++] = n1;
			for(i=0; i+1 < ans; i++)
				if(n1 == anss[i]){
					ans--; break;
				}
		}
		//cout << y[k] << ' ' << x[k] << ':' << n1 << endl;
	}
	return ans;
}
int main(){
	init_digit();
	int tot;
	int n, A, B;
	int ans;
	cin >> tot;
	for(int i = 1; i <= tot; i++){
		cin >> A >> B;
		ans = 0;
		for(n = A; n < B; n++)
			ans += test(n, A, B);
		cout << "Case #" << i << ": " << ans << endl;
	}
}
