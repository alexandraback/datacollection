#include <iostream>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdlib>

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define X first
#define Y second

using namespace std;

string a[200];
int u[1000];
int it;

int goodd(string &A){
	it++;
	for (int i = 0; i < A.size(); i++){
		if (u[A[i]] != it){
			u[A[i]] = it;
		} else
			if (A[i] != A[i - 1]) return 0; 
	}
	return 1;
}

int good(string A){
	it++;
	for (int i = 0; i < A.size(); i++){
		if (u[A[i]] != it){
			u[A[i]] = it;
		} else
			if (A[i] != A[i - 1]) return 0; 
	}
	return 1;
}

int Q[1000];

const long long md = 1000000007;
int com[100][100];
int IS[100];

void dfs(char v){
	IS[v - 'a'] = 0;
	for (char ch = 'a'; ch <= 'z'; ch++){
		if (com[v - 'a'][ch - 'a'])
			if (IS[ch - 'a']) dfs(ch);
	}
}

int pp[100];

int main(){
	freopen("inputB.in","r",stdin);
	freopen("outputB.out","w",stdout);
	int T;
	cin >> T;
	for (int TT = 1; TT <= T; TT++){
		printf("Case #%d: ", TT);
		
		int n;
		cin >> n;
		long long ans = 1;
		memset(Q, 0, sizeof(Q));
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (!good(a[i])){
				ans = 0;
			}
			if (a[i][0] == a[i][a[i].size() - 1]){
				Q[a[i][0]]++;
				ans = (ans * Q[a[i][0]]) % md;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = i + 1; j < n; j++){
				if ((!good(a[i] + a[j])) && (!good(a[j] + a[i]))){
					ans = 0;
				}
			}
		}

		if (ans != 0){
			memset(com, 0, sizeof(com));
			memset(IS, 0, sizeof(IS));
			for (int i = 0; i < n; i++){
				for (int i1 = 0; i1 < a[i].size(); i1++){
					IS[a[i][i1] - 'a'] = 1;
					for (int i2 = 0; i2 < a[i].size(); i2++){
						com[a[i][i1] - 'a'][a[i][i2] - 'a'] = 1;
					}
				}
			}
			int cc = 0;
			for (char ch = 'a'; ch <= 'z'; ch++){
				if (IS[ch - 'a']) {
					cc++;
					ans = (ans * cc) % md;
					dfs(ch);
				}
			}
		}
		cout << ans << endl;

		/*for (int i = 0; i < n; i++) pp[i] = i;

		int aa = 0;
		int itt = 0;
		while (1){
			string r = "";
			for (int i = 0; i < n; i++) r += a[pp[i]];
			if (goodd(r)) aa++;
			//if (TT == 1) cout << r << " " << goodd(r) << endl;
			//if (TT == 3) cout << r.size() << " " << n << endl;
			itt++;
			//if (itt % 10000 == 0) cout << itt << endl;
			int ok = 1;
			for (int i = 0; i < n; i++){
				if (pp[i] != n - i - 1) ok = 0;
			}
			if (ok) break;

			next_permutation(pp, pp + n);
		}
		cout << aa << endl;*/
	}
    return 0;
}
