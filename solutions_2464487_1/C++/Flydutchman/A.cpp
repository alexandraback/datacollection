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
			long long n,r,t;
		scanf("%I64d%I64d",&r,&t);
		long double S = (r + 1) * (r + 1) - r * r;
		long long L = 1, R = (long long)1e12;
		while (L < R) {
			long long mid = L + R + 1 >> 1;
			long double ts = (S + S + (mid - 1) * 4) * mid / 2.;
			if (t < ts - 1e-12) R = mid - 1; else L = mid;
		}
		cout << L << endl;
	}
	return 0;
}

