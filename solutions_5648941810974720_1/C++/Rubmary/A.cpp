#include <bits/stdc++.h>
using namespace std;

#define FOR(i, to, from) for(int i=to; i<from; i++)
#define ri(n) scanf("%d", &n)
#define rii(n, m) scanf("%d %d", &n, &m);
#define ms(obj,val) memset(obj, val, sizeof(obj))
#define pb push_back
typedef long long ll;
typedef vector<int> vi;

int L[27]={};
string S;
int N[10]={};

int T;
int main(){
	cin >>T;
	FOR(t, 1, T+1){
		ms(L, 0);
		ms(N, 0);
		cout <<"Case #"<< t << ": ";
		cin >>S;
		int n=S.length();
		FOR(i, 0, n) L[S[i]-'A']++;
		N[0] = L['Z'-'A'];
		N[2] = L['W'-'A'];
		N[6] = L['X'-'A'];
		N[4] = L['U'-'A'];
		N[8] = L['G'-'A'];
		N[1] = L['O'-'A']-N[0]-N[2]-N[4];
		N[3] = L['H'-'A']-N[8];
		N[5] = L['F'-'A']-N[4];
		N[7] = L['V'-'A']-N[5];
		N[9] = L['I'-'A']-N[5]-N[6]-N[8];
		FOR(i, 0, 10) FOR(j, 0, N[i]) cout << i;
		cout << endl;
	}	
}

