#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a), __ = (b); i < __; i++)
#define inf 0x3f3f3f3f
#define st first
#define nd second
#define eps 1e-9

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main(){
	int t, caso = 1, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int total = 0, ans = 0;
		fr(i, 0, n+1){
			char c;
			scanf(" %c", &c);
			c -= '0';
			if(total < i && c){
				ans += i-total;
				total = i;
			}
			total += c;
		}
		
		printf("Case #%d: %d\n", caso++, ans);
	}

	return 0;
}

