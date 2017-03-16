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
const int maxn = 100010;

string str, temp, ans;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int t, cn = 1, n, i, j;
	scanf("%d", &t);
	while(t--){
		cin >> str;
		ans = "";
		n = (int)str.size();
		ans+=str[0];
		for(i=1; i<n; i++){
			if(str[i]>=ans[0])
				ans = str[i]+ans;
			else
				ans = ans+str[i];
		}
		printf("Case #%d: ", cn++);
		cout << ans << "\n";
	}
	
	return 0;
}
