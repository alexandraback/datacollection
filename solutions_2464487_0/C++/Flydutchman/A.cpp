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

const flt pi = acos(-1.0);

int main() {
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) { printf("Case #%d: ",TTT); cerr << TTT << endl;
				if(TTT==12){
					int z=TTT;
				}
			long long n,r; flt t;
		scanf("%I64d%lf",&r,&t); t *= pi;
		int ans = 0;
		for (long long i = r + 1; ; i += 2) {
			t -= pi * (flt)((flt)i * i - (flt)(i - 1) * (i - 1));
			if (t < -1e-8) { cout << ans << endl; break ; } else ++ans;
		}
	}
	return 0;
}

