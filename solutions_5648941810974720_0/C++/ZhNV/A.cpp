#include <bits/stdc++.h>
using namespace std;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 2e3 + 15;
const int Q = 1e9 + 7;


const int ALP = 300;
int Cnt[M][ALP];
int cnt[ALP];
string tem[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int p[10] = {0, 6, 8, 2, 3, 4, 5, 1, 7, 9};



int main(){
    srand(time(NULL));
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < (int)tem[i].size(); j++)
			Cnt[i][tem[i][j]]++;
	}
	for (int TT = 0; TT < T; TT++) {
		string s;
		cin >> s;
		string ans = "";
		int n = (int)s.size();
		for (char c = 'A'; c <= 'Z'; c++)
			cnt[c] = 0;
		for (int i = 0; i <  n; i++)
			cnt[s[i]]++;
		for (int i1 = 0; i1 < 10; i1++) {
			int i = p[i1];
			
			while(1) {
				bool ok = true;
				for (char c = 'A'; c <= 'Z'; c++) 
					if (cnt[c] < Cnt[i][c])	
						ok = false;
				if (!ok) break;
				for (char c = 'A'; c <= 'Z'; c++)
					cnt[c] -= Cnt[i][c];
				ans += (char)(i + '0');
			}
		}
		for (char c = 'A'; c <= 'Z'; c++)
			assert(cnt[c] == 0);
		sort(ans.begin(), ans.end());	
		

		cout << "Case #" << TT + 1 << ": " << ans << "\n";
		cerr << TT << endl;
	}
		
    return 0;
}   