#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1000002];
long long a[1000002];

int main(){freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for(int r=1; r<=T; r++){
		memset(a, 0, sizeof(a));
		long long ans = 0, m;
		scanf("%s %lld", s, &m);
		int l = strlen( s );
		long long n = l, i;

		for(i=0; i<n; i++)
			if( s[i]!='a' && s[i]!='e' && s[i]!='o' && s[i]!='u' && s[i]!='i' )
				a[i] = 1;
			else
				a[i] = 0;
		
		long long c = 0, q = 0;
		for(i=0; i<n; i++){
			long long re = -1;
			if(a[i]) c++;
			else c = 0;
			if( c>=m ){
				re = i-m+2-q;
				q = i-m+2;
			}
			if(re != -1){
				ans += re*(n - i);
			}
		}
		printf("Case #%d: %lld\n", r, ans);
	}

}