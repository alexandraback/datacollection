#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

typedef long long ULL;

ULL reverse(ULL a) {

	ULL b = 0;
	while( a > 0 ) {

		b *= 10;

		ULL r = a % 10;
		b += r;

		a /= 10;

	}
	return b;
}

ULL W[10000000];

//unordered_map<ULL,int> map;
//unordered_map<ULL,bool> vis;

ULL dfs(ULL N) {

	for(ULL a=1;a<=N;a++) {

		ULL ra = reverse(a);
		if(W[a+1] == -1 || W[a] + 1 < W[a+1]) {
			W[a+1] = W[a] + 1;
		}
		if(W[ra] == -1 || W[a] + 1 < W[ra]) {
			W[ra] = W[a] + 1;
		}

	}
	return W[N];
}



int main() {

	//cout<<reverse(100)<<endl;

	freopen("C:\\Users\\weihaoc\\ACM\\a.in", "r", stdin);
	freopen("C:\\Users\\weihaoc\\ACM\\a.out", "w+", stdout);

	int T;
	cin >> T;

	memset(W, -1, sizeof(W));
	W[1] = 1;
	
	for(int t=1;t<=T;t++) {

		ULL N;
		cin >> N;

		ULL ans = dfs(N);

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}

	return 0;

}