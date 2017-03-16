#include <bits/stdc++.h>

#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define SIZE(a) ((int)a.size())
#define pb push_back
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

int main(){
	int Z; scanf("%d", &Z); FWD(z,1,Z+1){
		int a, b, k, c = 0;
		scanf("%d %d %d", &a, &b, &k);
		FWD(i,0,a)
			FWD(j,0,b)
				if((i&j) < k)
					++c;
		printf("Case #%d: %d\n", z, c);
	}
	return 0;
}
