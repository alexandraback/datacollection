#include <iostream>
#include <cstring>
using namespace std;

long long a[31], b[31], k[31], arr[31][2][2][2];

void read()
{
	int A, B, K;
	cin >> A >> B >> K;
	A--, B--, K--;
	int s = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(k, 0, sizeof(k));
	s = 0;
	while(A) {
		a[s++] = A & 1;
		A >>= 1;
	}
	s = 0;
	while(B) {
		b[s++] = B & 1;
		B >>= 1;
	}
	s = 0;
	while(K) {
		k[s++] = K & 1;
		K >>= 1;
	}
	memset(arr, -1, sizeof(arr));
}

long long dp(int p, int ba, int bb, int bk)
{
	if(p < 0) return 1;
	if(arr[p][ba][bb][bk] != -1) return arr[p][ba][bb][bk];
	long long ans = 0;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++) {
			int s = i & j;
			if((!ba || (i <= a[p])) && (!bb || (j <= b[p])) && (!bk || (s <= k[p]))) {
				ans += dp(p - 1, 
						(int)(ba && (i >= a[p])),
						(int)(bb && (j >= b[p])),
						(int)(bk && (s >= k[p])));
			}
		}
	arr[p][ba][bb][bk] = ans;
	return ans;
}

int main()
{
	int t;
	cin >> t;
	for(int T = 1; T <= t; T++) {
		read();
		cout << "Case #" << T << ": " << dp(30, 1, 1, 1) << endl;
	}
	return 0;
}

