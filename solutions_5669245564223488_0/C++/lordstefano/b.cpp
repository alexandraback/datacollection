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

#define N 12
int v[N];
string s[N];
int n;
bool ja[30];
int da (){
	char ant;
	clr (ja, 0);
	f (i, 0, n){
		int q = v[i];
		f (j, 0, s[q].size()){
			if (ja[s[q][j]-'a'] && ant != s[q][j]) return 0;
		   	ant = s[q][j];
			ja[s[q][j]-'a'] = 1;	
		}
	}
	return 1;
}


int main (){
	int t; cin >> t;
	f (tt, 1, t+1){
		printf("Case #%d: ", tt);
		cin >> n;
		f (i, 0, n) v[i] = i;
		f (i, 0, n) cin >> s[i];
		int ans = 0;
		do{
			ans += da();
		}while (next_permutation(v, v+n));
		cout << ans << endl;
	}

	return 0;
}


