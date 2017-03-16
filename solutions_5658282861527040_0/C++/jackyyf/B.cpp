#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

int A,B,K;
/*int dp(int i, int w1, int w2, int w3) {
	if (i == 0) {
		if (K & 1) return (1 + (A & 1)) * (1 + (B & 1));
		else return 0;
	}
}*/

int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) { cerr << TTT << endl;
		cin >> A >> B >> K;
		int ans = 0;
		For(i,0,A - 1) For(j,0,B - 1) if ((i & j) < K) ++ans;
		printf("Case #%d: %d\n",TTT,ans);
	}
	return 0;
}

