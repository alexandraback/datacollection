#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 1000010;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int t, n, i, temp, x, cn=1, mask;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n==0){
			printf("Case #%d: INSOMNIA\n", cn++);
			continue;
		}
		mask = 0;
		temp = n;
		i = 1;
		while(mask!=1023){
			i++;
			while(temp){
				x = temp%10;
				temp/=10;
				mask|=(1<<x);
			}
			temp = i*n;
		}
		temp-=n;
		printf("Case #%d: %d\n", cn++, temp);
	}
	
	return 0;
}
