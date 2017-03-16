#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000007LL
#define INF 1023123123
#define pb push_back
using namespace std;

int len, maks = 0;
map <string, int> kamus;
map <pii, int> dp;
char st[10005];
vector <string> kata[11];
// char str[4005];

int f(int pos, string str, int cnt) {
	if (((int)str.length()) > maks)
		return INF;
	
	if (st[pos] == '\0') {
		int panjang = str.length();
		int sz = kata[panjang].size();
		int ans = INF;
		
		REP(i, sz) {
			string temp = kata[panjang][i];
			int tambah = 0, last = -5;
			bool bisa = true;
			
			REP(j, panjang) {
				if (str[j] != temp[j]) {
					if ((j - last) >= 5) {
						++tambah;
						last = j;
					}
					else {
						bisa = false;
						break;
					}
				}
			}
			
			if (bisa)
				ans = min(ans, tambah);
		}
		
		return ans;
	}
	
	pii temp = mp(pos, cnt);
	
	if (dp.count(temp) != 0)
		return dp[temp];
	
	dp[temp] = INF;
	
	int ret = INF;
	
	str = str + st[pos];
	int panjang = str.length();
	int sz = kata[panjang].size();
	
	REP(i, sz) {
		string temp = kata[panjang][i];
		int tambah = 0, last = -5;
		bool bisa = true;
		
		REP(j, panjang) {
			if (str[j] != temp[j]) {
				if ((j - last) >= 5) {
					++tambah;
					last = j;
				}
				else {
					bisa = false;
					break;
				}
			}
		}
		
		if (bisa)
			ret = min(ret, tambah + f(pos + 1, "", 0));
	}
	
	ret = min(ret, f(pos + 1, str, cnt + 1));
	
	dp[temp] = ret;
	
	// printf("%s %d\n", str.c_str(), ret);
	
	return ret;
}

int main() {
	int T;
	
	freopen("email_dictionary.txt", "r", stdin);
	
	while (gets(st)) {
		int panjang = strlen(st);
		kata[panjang].pb(st);
		kamus[st] = 1;
		maks = max(maks, panjang);
	}
	
	fclose(stdin);
	
	freopen("C-small-attempt2.in", "r", stdin);
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		printf("Case #%d: ", tc);
		
		scanf("%s", st);
		
		len = strlen(st);
		
		dp.clear();
		
		printf("%d\n", f(0, "", 0));
	}
	
	fclose(stdin);
	
	return 0;
}
