#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
char s[2100];
int cnt[310];

void read() {
	scanf("%s", s);
}

void solve() {
	for (char c = 'A'; c <= 'Z'; c++) cnt[c]=0;

	string ans = "";
	int l = strlen(s);
	REP(i,l) cnt[s[i]]++;

	while (cnt['W']) {
		cnt['W']--; cnt['O']--; cnt['T']--;
		ans += '2';
	}
	while (cnt['U']) {
		cnt['F']--; cnt['O']--; cnt['U']--; cnt['R']--;
		ans += '4';
	}
	while (cnt['G']) {
		cnt['E']--; cnt['I']--; cnt['G']--; cnt['H']--; cnt['T']--;
		ans += '8';
	}
	while (cnt['X']) {
		cnt['S']--; cnt['I']--; cnt['X']--;
		ans += '6';
	}
	while (cnt['Z']) {
		cnt['Z']--; cnt['E']--; cnt['R']--; cnt['O']--;
		ans += '0';
	}
	while (cnt['H']) {
		cnt['T']--; cnt['H']--; cnt['R']--; cnt['E']-=2;
		ans += '3';
	}
	while (cnt['O']) {
		cnt['O']--; cnt['N']--; cnt['E']--;
		ans += '1';
	}
	while (cnt['F']) {
		cnt['F']--; cnt['I']--; cnt['V']--; cnt['E']--;
		ans += '5';
	}
	REP(i, cnt['V']) {ans+='7'; cnt['N']--;}
	REP(i,cnt['N']/2) ans+='9';

	sort(ans.begin(),ans.end());
	printf("%s\n", ans.c_str());
}


























int myMod = 0;
int howMany = 1;

int main(int argc, char** argv) {
	if (argc > 1) {
		stringstream ss; ss << argv[1]; ss >> myMod;
		ss.str(""); ss.clear();
		ss << argv[2]; ss >> howMany;
	}

	int cases;
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		read();
		if (i % howMany == myMod) {
			printf("Case #%d: ", i+1);
			solve();
		}
	}
}