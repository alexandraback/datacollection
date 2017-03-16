#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a), __ = (b); i < __; i++)
#define inf 0x3f3f3f3f
#define st first
#define nd second
#define eps 1e-9

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int p[1010], maior;

int main(){
	int t, caso = 1, n;
	scanf("%d", &t);
	while(t--){
		maior = 0;
		scanf("%d", &n);
		fr(i, 0, n){
			scanf("%d", &p[i]);
			maior = max(maior, p[i]);
		}
			
		int ans = inf;
		fr(i, 1, maior+1){
			int at = 0;
			fr(j, 0, n){
				int d;
				if(p[j]%i == 0) d = p[j]/i;
				else d = p[j]/i + 1;
				at += d-1;
			}
			
			at += i;
			ans = min(ans, at);
		}
		
		printf("Case #%d: %d\n", caso++, ans);
	}

	return 0;
}

