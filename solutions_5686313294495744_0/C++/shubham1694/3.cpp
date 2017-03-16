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

string arr[maxn][2];
int n;
set<string> fw, sw;

int check(int mask)
{
	int i, j;
	fw.clear();
	sw.clear();
	for(i=0; i<n; i++){
		if(mask&(1<<i)){
			fw.insert(arr[i][0]);
			sw.insert(arr[i][1]);
		}
	}
	for(i=0; i<n; i++){
		if(!(mask&(1<<i))){
			if(fw.find(arr[i][0])==fw.end())
				return 0;
			if(sw.find(arr[i][1])==sw.end())
				return 0;
		}
	}
	return 1;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int cn = 1, t, i, j, ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = 0;
		for(i=0; i<n; i++)
			cin >> arr[i][0] >> arr[i][1];
		for(i=0; i<(1<<n); i++){
			if(check(i))
				ans = max(ans, n-(int)(__builtin_popcount(i)));
		}
		printf("Case #%d: %d\n", cn++, ans);
	}
	return 0;
}
