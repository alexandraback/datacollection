#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

unsigned int xorshift(){
	static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned int t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		int R, N, M, K;
		cin >> R >> N >> M >> K;
		cout << "Case #" << caseNum << ":" << endl;
		for(int i = 0; i < R; ++i){
			vector<ll> v(K);
			for(int j = 0; j < K; ++j){ cin >> v[j]; }
			int m2 = 0, m3 = 0, m5 = 0, m7 = 0;
			int r2 = 0, r4 = 0;
			for(int j = 0; j < K; ++j){
				ll x = v[j];
				int p2 = 0, p3 = 0, p5 = 0, p7 = 0;
				while(x % 7 == 0){ x /= 7; ++p7; }
				while(x % 5 == 0){ x /= 5; ++p5; }
				while(x % 3 == 0){ x /= 3; ++p3; }
				if(x == 2){ r2 = 1; }
				while(x % 2 == 0){ x /= 2; ++p2; }
				m2 = max(m2, p2);
				m3 = max(m3, p3);
				m5 = max(m5, p5);
				m7 = max(m7, p7);
			}
			int r = N - m3 - m5 - m7;
			cout << string(m3, '3');
			cout << string(m5, '5');
			cout << string(m7, '7');
			while(r > 0){ cout << (2 << (xorshift() % 3)); --r; }
			cout << endl;
		}
	}
	return 0;
}

