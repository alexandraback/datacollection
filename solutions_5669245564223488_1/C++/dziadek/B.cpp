#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define f first
#define s second

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

ll f[105];
const int MOD = 1000000007;

bool monochrome(string s){
	char c = s[0];
	REP(i,s.length())
		if(s[i] != c) return false;
	return true;
}

bool valid(string s, char c, int mode){
	int prev = -1;

	if(monochrome(s)) return true;

	REP(i,s.length())
		if(s[i] == c){
			if(prev == -1) prev = i;
			else
				if(prev != i-1) return false;
			prev = i;
		}

	if(mode == 0) return true;

	if(s[0] != c && s[s.length()-1] != c) return false;
	return true;
}

void testcase(){
	int N;
	cin >> N;

	string s;
	vector<string> v;

	REP(i,N){
		cin >> s;
		v.PB(s);
	}


	bool ok = true;
	ll res = 1;

	REP(i,26){
		char c = (char)('a' + i);

		vector<string> t,tmp;

		REP(j,v.size())
			if(v[j].find(c) != string::npos){
				t.PB(v[j]);
			}
			else
				tmp.PB(v[j]);

		if(t.size() == 0) continue;

		if(t.size() == 1){
			if(!valid(t[0],c,0)){
				cout << "0";
				return;
			}
			continue;
		}

		REP(j,t.size()) ok &= valid(t[j],c,1);

		if(!ok){
			cout << "0";
			return;
		}

		int mono = 0;
		int pref = 0;
		int suf = 0;

		string M = "";
		string P = "";
		string S = "";

		REP(j,t.size())
			if(monochrome(t[j])){
				++mono;
				M += t[j];
			}
			else
				if(t[j][0] == c){
					++pref;
					P = t[j];
				}
				else
					if(t[j][t[j].length()-1] == c){
						++suf;
						S = t[j];
					}

		if(pref>1 || suf>1){
			cout << "0";
			return;		
		}

		res *= f[mono];
		res %= MOD;

		v.clear();
		REP(j,tmp.size()) v.PB(tmp[j]);
		v.PB(S+M+P);
	}

	res *= f[v.size()];
	res %= MOD;

	cout << res;
}

int main(){

	f[0] = 1;
	FOR(i,1,100){
		f[i] = f[i-1]*i;
		f[i] %= MOD;
	}

	int t;
	cin >> t;

	FOR(i,1,t){
		cout << "Case #" << i << ": ";
		testcase();
		cout << endl;
	}

	return 0;
}

