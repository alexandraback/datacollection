#include <bits/stdc++.h>

using namespace std;

#define INP "inp.txt"
#define OUT "out.txt"

int T, N, ans[10], fre[26];
string s;

void check(int N) {
	if(N == 0 && fre['Z' - 'A']) {
		ans[N] += fre['Z' - 'A'];
		fre['E' - 'A'] -= fre['Z' - 'A'];
		fre['R' - 'A'] -= fre['Z' - 'A'];
		fre['O' - 'A'] -= fre['Z' - 'A'];
		fre['Z' - 'A'] = 0;
	}
	if(N == 1 && fre['O' - 'A']) {
		ans[N] += fre['O' - 'A'];
		fre['N' - 'A'] -= fre['O' - 'A'];
		fre['E' - 'A'] -= fre['O' - 'A'];
		fre['O' - 'A'] = 0;		
	}
	if(N == 2 && fre['W' - 'A']) {
		ans[N] += fre['W' - 'A'];
		fre['T' - 'A'] -= fre['W' - 'A'];
		fre['O' - 'A'] -= fre['W' - 'A'];
		fre['W' - 'A'] = 0;		
	}	
	if(N == 3 && fre['T' - 'A']) {
		ans[N] += fre['T' - 'A'];
		fre['H' - 'A'] -= fre['T' - 'A'];
		fre['R' - 'A'] -= fre['T' - 'A'];
		fre['E' - 'A'] -= fre['T' - 'A'] * 2;
		fre['T' - 'A'] = 0;		
	}
	if(N == 4 && fre['U' - 'A']) {
		ans[N] += fre['U' - 'A'];
		fre['F' - 'A'] -= fre['U' - 'A'];
		fre['R' - 'A'] -= fre['U' - 'A'];
		fre['O' - 'A'] -= fre['U' - 'A'];
		fre['U' - 'A'] = 0;		
	}	
	if(N == 5 && fre['F' - 'A']) {
		ans[N] += fre['F' - 'A'];
		fre['I' - 'A'] -= fre['F' - 'A'];
		fre['V' - 'A'] -= fre['F' - 'A'];
		fre['E' - 'A'] -= fre['F' - 'A'];
		fre['F' - 'A'] = 0;		
	}
	if(N == 6 && fre['X' - 'A']) {
		ans[N] += fre['X' - 'A'];
		fre['S' - 'A'] -= fre['X' - 'A'];
		fre['I' - 'A'] -= fre['X' - 'A'];
		fre['X' - 'A'] = 0;		
	}
	if(N == 7 && fre['S' - 'A']) {
		ans[N] += fre['S' - 'A'];
		fre['V' - 'A'] -= fre['S' - 'A'];
		fre['N' - 'A'] -= fre['S' - 'A'];
		fre['E' - 'A'] -= fre['S' - 'A'] * 2;
		fre['S' - 'A'] = 0;		
	}
	if(N == 8 && fre['G' - 'A']) {
		ans[N] += fre['G' - 'A'];
		fre['E' - 'A'] -= fre['G' - 'A'];
		fre['I' - 'A'] -= fre['G' - 'A'];
		fre['H' - 'A'] -= fre['G' - 'A'];
		fre['T' - 'A'] -= fre['G' - 'A'];
		fre['G' - 'A'] = 0;		
	}
	if(N == 9 && fre['I' - 'A']) {
		ans[N] += fre['I' - 'A'];
		fre['E' - 'A'] -= fre['I' - 'A'];
		fre['N' - 'A'] -= fre['I' - 'A'] * 2;
		fre['I' - 'A'] = 0;		
	}
}

void solve() {
	for (int i = 0; i < 10; ++i)
	{
		ans[i] = 0;
	}
	for (int i = 0; i < 26; ++i)
	{
		fre[i] = 0;
	}
	for (int i = 0; i < s.length(); ++i)
	{
		fre[s[i] - 'A']++;
	}

	for (int i = 0; i <= 8; i += 2)
	{
		check(i);
	}
	for (int i = 1; i <= 7; i += 2)
	{
		check(i);
	}
	check(9);
}

void printAns(){
	for (int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < ans[i]; j++) cout << i;
	}
	cout << endl;
}

int main () {
	freopen(INP, "r", stdin);
	freopen(OUT, "w", stdout);

	scanf(" %d ", &T);
	for(int tt = 1; tt <= T; tt++) {
		cin >> s;
		solve();
		cout << "Case #" << tt << ": ";
		printAns();
	}
	return 0;
}