#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
int b[MAXN];
void kmpPreprocess(string pattern) {
    int i = 0, j = -1;
    b[0] = -1;
    while(i < pattern.size()) {
        while(j >= 0 && pattern[i] != pattern[j]) {
            j = b[j];
        }
        i ++;
        j ++;
        b[i] = j;
    }
}

string L;
int cnt[26], S, K;

double f[110][110][110];
bool vis[110][110][110];

double F(int idx, int pidx, int seen) {
	if(idx == S)
		return seen;
	else if(vis[idx][pidx][seen])
		return f[idx][pidx][seen];
	vis[idx][pidx][seen] = true;
	double &res = f[idx][pidx][seen] = 0;
	res = 0;

	for(int i = 0; i < 26; i++) {
		if(!cnt[i]) continue;
		char c = 'A'+i;
		int npidx=pidx, nseen = seen;
		if(c == L[pidx]) {
			if(pidx == L.length()-1)
				nseen++, npidx = b[pidx]+1;
			else
				npidx++;
		} else {
			while(npidx >= 0 && L[npidx] != c)
				npidx = b[npidx];
			npidx++;
		}

		res += cnt[i]*F(idx+1, npidx, nseen);
	}

	return res /= K;
}

int main() {
//	freopen("test.in", "r", stdin);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);

	int T;
	cin >> T;
	for(int cse = 1; cse <= T; cse++) {
		cin >> K >> L >> S;
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < K; i++) {
			char c;
			cin >> c;
			cnt[c-'A']++;
		}
		cin >> L;
		kmpPreprocess(L);

		memset(vis, false, sizeof vis);
		double res = F(0, 0, 0);
		int mx = 0;
		for(int i = 0, j = 0; i < S; i++)
			if(j == L.length()-1)
				j = b[j]+1, mx++;
			else
				j++;
		for(int i = 0; i < L.length(); i++)
			if(!cnt[L[i]-'A'])
				mx = 0;
//		cerr << "------> " << mx << ' ' << res << endl;

		cout << setprecision(7) << fixed;
		cout << "Case #" << cse << ": " << mx-res << endl;
	}

	return 0;
}
