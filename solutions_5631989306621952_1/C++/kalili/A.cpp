#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
#define X first
#define Y second

using namespace std;

const int N = 1e3 + 100;

char s[N];
string DP(int L, int R) {
	if(L > R) return "";
	char maxn = 0;
	int pos = 0;
	for(int i = L; i <= R; i ++) 
		if(maxn <= s[i]) maxn = s[i], pos = i;
	string ans = "";
	ans.push_back(maxn);
	ans += DP(L, pos - 1);
	string tmp = "";
	for(int i = pos + 1; i <= R; i ++) tmp += s[i];
	ans += tmp;
	return ans;
}
int main()
{
	freopen("A.in","r",stdin);
    freopen("A.txt","w",stdout);
	int T;
	int cas = 0;
	cin >> T;
	while(T --) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		printf("Case #%d: ", ++ cas);
		cout << DP(1, len) << endl;
	}
}
