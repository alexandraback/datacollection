#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define mod 1000000007

#define N 128
#define C 26
#define mod 1000000007
int v[N];
string s[N];
int n;

int M[C+10][C+10];
int meio[C+10];
int ja[C+10];
ll cnt, cic;
int grau[C+10];

int check (int q){
	char ant;
	clr (ja, 0);
	f (j, 0, s[q].size()){
		if (ja[s[q][j]-'a'] && ant != s[q][j]) return 0;
		ant = s[q][j];
		ja[s[q][j]-'a'] = 1;	
	}
	return 1;
}

void dfs (int x){
	ja[x] = 1;
	cnt++;
	f (i, 0, C) if (i != x && M[x][i]){
		//printf("i = %d\n", i);
		if (ja[i]) cic = 1;
	   	else dfs (i);	
	}
}


ll solve (){
	clr (ja, 0);
	ll cmp = 0;
	ll ans = 1;
	f (i, 0, C) f (j, 0, C) if (grau[i] == 0 && M[i][j] && !ja[i]){
		cic = cnt = 0;
		dfs (i);
		cmp++;
		ans %= mod;
	}
	f (i, 0, C) f (j, 0, C) if (M[i][j] && !ja[i]){
		return 0;
	}
	for (ll i = 2; i <= cmp; i++) ans *= i, ans %= mod;
	f (i, 0, C) {
		for (ll j = 2; j <= M[i][i]; j++) ans *= j, ans %= mod;
	}
	return ans;
}


int main (){
	int t; cin >> t;
	f (tt, 1, t+1){
		printf("Case #%d: ", tt);
		cin >> n;
		clr (M, 0); clr (grau, 0);
		int ans = 0;
		f (i, 0, n) {
			cin >> s[i];
			M[s[i][0]-'a'][s[i][s[i].size()-1]-'a']++;
			//printf("%d %d\n", s[i][0]-'a',s[i][s[i].size()-1]-'a');
			if (s[i][0] != s[i][s[i].size()-1]) grau[s[i][s[i].size()-1]-'a']++;
			if (!check(i)) ans = -1;
		}
		//f (i, 0, C){
		//	f (j, 0, C) printf("%d", M[i][j]); printf("\n");
		//}
		f (i, 0, n) f (j, 0, n) if (i != j){
			f (k, 1, s[i].size()-1) f (l, 0, s[j].size()){
				int sz = s[i].size()-1;
				if (s[i][k] == s[j][l] && s[i][k] != s[i][0] && s[i][k] != s[i][sz]) ans = -1;
			}
		}
		
		f (i, 0, C){
			int cnt = 0;
			f (j, 0, C) if (i != j && M[i][j]) cnt+=M[i][j]; 
			if (cnt > 1) ans = -1;
			cnt  = 0;
			f (j, 0, C) if (i != j && M[j][i]) cnt+=M[i][j]; 
			if (cnt > 1) ans = -1;
		}
		if (ans == -1){
			cout << "0" << endl; continue;
		}

		cout << solve() << endl;


	}

	return 0;
}


