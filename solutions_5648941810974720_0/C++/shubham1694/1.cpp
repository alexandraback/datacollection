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

int cnt[30], freq[30];
char str[maxn];
string ans;

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int cn = 1, t, i, j, n;
	scanf("%d", &t);
	while(t--){
		scanf("%s", str+1);
		n = strlen(str+1);
		for(i=0; i<26; i++)
			cnt[i] = freq[i] = 0;
		for(i=1; i<=n; i++)
			cnt[str[i]-'A']++;
		freq[0] = cnt['Z'-'A'];
		cnt['Z'-'A']-=freq[0];
		cnt['E'-'A']-=freq[0];
		cnt['R'-'A']-=freq[0];
		cnt['O'-'A']-=freq[0];
		freq[2] = cnt['W'-'A'];
		cnt['T'-'A']-=freq[2];
		cnt['W'-'A']-=freq[2];
		cnt['O'-'A']-=freq[2];
		freq[4] = cnt['U'-'A'];
		cnt['F'-'A']-=freq[4];
		cnt['O'-'A']-=freq[4];
		cnt['U'-'A']-=freq[4];
		cnt['R'-'A']-=freq[4];
		freq[5] = cnt['F'-'A'];
		cnt['F'-'A']-=freq[5];
		cnt['I'-'A']-=freq[5];
		cnt['V'-'A']-=freq[5];
		cnt['E'-'A']-=freq[5];
		freq[6] = cnt['X'-'A'];
		cnt['S'-'A']-=freq[6];
		cnt['I'-'A']-=freq[6];
		cnt['X'-'A']-=freq[6];
		freq[7] = cnt['V'-'A'];
		cnt['S'-'A']-=freq[7];
		cnt['E'-'A']-=freq[7];
		cnt['V'-'A']-=freq[7];
		cnt['E'-'A']-=freq[7];
		cnt['N'-'A']-=freq[7];
		freq[8] = cnt['G'-'A'];
		cnt['E'-'A']-=freq[8];
		cnt['I'-'A']-=freq[8];
		cnt['G'-'A']-=freq[8];
		cnt['H'-'A']-=freq[8];
		cnt['T'-'A']-=freq[8];
		freq[1] = cnt['O'-'A'];
		cnt['O'-'A']-=freq[1];
		cnt['N'-'A']-=freq[1];
		cnt['E'-'A']-=freq[1];
		freq[9] = cnt['I'-'A'];
		cnt['N'-'A']-=freq[9];
		cnt['I'-'A']-=freq[9];
		cnt['N'-'A']-=freq[9];
		cnt['E'-'A']-=freq[9];
		freq[3] = cnt['T'-'A'];
		ans = "";
		for(i=0; i<=9; i++){
			for(j=0; j<freq[i]; j++)
				ans+=(char)('0'+i);
		}
		printf("Case #%d: ", cn++);
		cout << ans << "\n";
	}
	return 0;
}
