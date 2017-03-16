#define _CRT_SECURE_NO_DEPRECATE
#define _ASSERTE

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for(int i = a; i < (int)(b); ++i)
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin,a.end()
#define ll long long

int pal(ll n) {
	char h[50], t[50];
	sprintf(h, "%I64d", n);
	strcpy(t, h);
	reverse(h, h + strlen(h));
	return !strcmp(t, h);
}

ll res[] = 
{
1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 0
};

int k, n;
int k1[223], key_type[213], keys[213][213], p[1 << 22];

int d[1 << 21];

int get(int mask) {
	if (d[mask] >= 0)
		return d[mask];
	if (mask == (1 << n) - 1)return d[mask] = 1;
	d[mask] = 0;
	p[mask] = -1;
	int k2[203];
	forn(i, 203){
		k2[i] = k1[i];
	}
	forn(i, n) {
		if((mask & (1 << i))) {
			k2[key_type[i]]--;
			forn(j, keys[i][0]){
				k2[keys[i][j + 1]]++;
			}
		}
	}
	forn(i, n){
		if ((!(mask & (1 << i))) && k2[key_type[i]] > 0 && get(mask | (1 << i))){
			p[mask] = i;
			return d[mask] = 1;
		}
	}
	return d[mask];
}

void go(int mask) {
	if (mask == (1 << n) - 1)
		return;
	printf(" %d", p[mask] + 1);
	go(mask ^ (1 << p[mask]));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output2.txt", "wt", stdout);
#endif

	int tt;
	cin >> tt;
	forn(t, tt) {
		
		cin >> k >> n;
		memset(d, -1, sizeof d);
		memset(p, -1, sizeof p);
		memset(k1, 0, sizeof k1);
		forn(i, k){
			int x;
			cin >> x;
			k1[x]++;
		}
		forn(i, n) {
			cin >> key_type[i];
			cin >> keys[i][0];
			forn(j, keys[i][0]) {
				cin >> keys[i][j + 1];
			}
		}
		cout << "Case #" << (t + 1) << ":";
		if (!get(0)){
			puts(" IMPOSSIBLE");
		}else{
			go(0);
			puts("");
		}

		/*
		PROB c
		ll a, b, ans = 0;
		cin >> a >> b;
		int i = 0;
		while(res[i]){
			if (a <= res[i] * res[i] && res[i] * res[i] <= b) ++ans;
			i++;
		}
		/*
		ll i = (int)sqrt(a - 0.);
		while (i * i < a)i++;
		while (i * i <= b) {
			if ((i < 10 || i % 10 == 1 || i % 10 == 2) && pal(i) && pal(i * i)){
				cout << i << ", ";
				ans++;
			}
			i++;
		}
		
		cout << "Case #" << (t + 1) << ": " << ans << endl;

*/


		/*
		PROB a
		string s[4];
		bool is_dot = 0;
		forn(i, 4){
			cin >> s[i];
			forn(j, 4)
				is_dot |= s[i][j] == '.';
		}
		string ans = is_dot ? "Game has not completed" : "Draw";
		int xwin = 0;
		forn(i, 4){
			xwin |= (s[i][0] == 'X' || s[i][0] == 'T') && 
					(s[i][1] == 'X' || s[i][1] == 'T') && 
					(s[i][2] == 'X' || s[i][2] == 'T') && 
					(s[i][3] == 'X' || s[i][3] == 'T');
			xwin |= (s[0][i] == 'X' || s[0][i] == 'T') && 
					(s[1][i] == 'X' || s[1][i] == 'T') && 
					(s[2][i] == 'X' || s[2][i] == 'T') && 
					(s[3][i] == 'X' || s[3][i] == 'T');
		}
		xwin |= (s[0][0] == 'X' || s[0][0] == 'T') && 
				(s[1][1] == 'X' || s[1][1] == 'T') && 
				(s[2][2] == 'X' || s[2][2] == 'T') && 
				(s[3][3] == 'X' || s[3][3] == 'T');
		xwin |= (s[0][3] == 'X' || s[0][3] == 'T') && 
				(s[1][2] == 'X' || s[1][2] == 'T') && 
				(s[2][1] == 'X' || s[2][1] == 'T') && 
				(s[3][0] == 'X' || s[3][0] == 'T');
		if (xwin) ans = "X won";

		int owin = 0;
		forn(i, 4){
			owin |= (s[i][0] == 'O' || s[i][0] == 'T') && 
					(s[i][1] == 'O' || s[i][1] == 'T') && 
					(s[i][2] == 'O' || s[i][2] == 'T') && 
					(s[i][3] == 'O' || s[i][3] == 'T');
			owin |= (s[0][i] == 'O' || s[0][i] == 'T') && 
					(s[1][i] == 'O' || s[1][i] == 'T') && 
					(s[2][i] == 'O' || s[2][i] == 'T') && 
					(s[3][i] == 'O' || s[3][i] == 'T');
		}
		owin |= (s[0][0] == 'O' || s[0][0] == 'T') && 
				(s[1][1] == 'O' || s[1][1] == 'T') && 
				(s[2][2] == 'O' || s[2][2] == 'T') && 
				(s[3][3] == 'O' || s[3][3] == 'T');
		owin |= (s[0][3] == 'O' || s[0][3] == 'T') && 
				(s[1][2] == 'O' || s[1][2] == 'T') && 
				(s[2][1] == 'O' || s[2][1] == 'T') && 
				(s[3][0] == 'O' || s[3][0] == 'T');
		if (owin) ans = "O won";

		cout << "Case #" << (t + 1) << ": " << ans << endl;
		/*
		problem B
		int n, m, a[120][120];
		cin >> n >> m;
		forn(i, n)
			forn(j, m)
				cin >> a[i][j];
		string ans = "YES";
		forn(i, n)
			forn(j, m){
				int str_ok = 1;
				forn(k, m)
					if (a[i][k] > a[i][j])
						str_ok = 0;
				int col_ok = 1;
				forn(k, n)
					if (a[k][j] > a[i][j])
						col_ok = 0;
				if (str_ok + col_ok == 0){
					ans = "NO";
					break;
				}
			}

		cout << "Case #" << (t + 1) << ": " << ans << endl;
		*/
	}

	return 0;
}