#include <bits/stdc++.h> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

template<class T> inline T maxm(T& a, T b){return a = a < b ? b : a;}
template<class T> inline T minm(T& a, T b){return a = a > b ? b : a;}

int cnt[26];
int nD[10];

int main(){

    int T;
    cin >> T;

    for(int i_ = 0; i_ < T; ++i_){

	cout << "Case #" << i_ + 1 << ": ";
	string s;
	cin >> s;
	int N = s.size();

	/*

	   ONE
	   EIGHT
	   NINE


	   */
	for(int i = 0; i < N; ++i){
	    cnt[s[i] - 'A']++;
	}
	if(cnt['Z' - 'A']){
	    nD[0] += cnt['Z' - 'A'];
	    while(cnt['Z' - 'A']){
		cnt['Z' - 'A']--;
		cnt['E' - 'A']--;
		cnt['R' - 'A']--;
		cnt['O' - 'A']--;
	    }
	}
	if(cnt['X' - 'A']){
	    nD[6] += cnt['X' - 'A'];
	    cnt['S' - 'A'] -= cnt['X' - 'A'];
	    cnt['I' - 'A'] -= cnt['X' - 'A'];
	    cnt['X' - 'A'] -= cnt['X' - 'A'];
	}
	if(cnt['S' - 'A']){
	    nD[7] += cnt['S' - 'A'];
	    cnt['E' - 'A'] -= cnt['S' - 'A'];
	    cnt['V' - 'A'] -= cnt['S' - 'A'];
	    cnt['E' - 'A'] -= cnt['S' - 'A'];
	    cnt['N' - 'A'] -= cnt['S' - 'A'];
	    cnt['S' - 'A'] -= cnt['S' - 'A'];
	}
	if(cnt['V' - 'A']){
	    nD[5] += cnt['V' - 'A'];
	    cnt['I' - 'A'] -= cnt['V' - 'A'];
	    cnt['F' - 'A'] -= cnt['V' - 'A'];
	    cnt['E' - 'A'] -= cnt['V' - 'A'];
	    cnt['V' - 'A'] = 0;
	}
	if(cnt['F' - 'A']){
	    nD[4] += cnt['F' - 'A'];
	    cnt['O' - 'A'] -= cnt['F' - 'A'];
	    cnt['U' - 'A'] -= cnt['F' - 'A'];
	    cnt['R' - 'A'] -= cnt['F' - 'A'];
	    cnt['F' - 'A'] -= cnt['F' - 'A'];
	}
	if(cnt['R' - 'A']){
	    nD[3] += cnt['R' - 'A'];
	    cnt['T' - 'A'] -= cnt['R' - 'A'];
	    cnt['H' - 'A'] -= cnt['R' - 'A'];
	    cnt['E' - 'A'] -= cnt['R' - 'A'];
	    cnt['E' - 'A'] -= cnt['R' - 'A'];
	    cnt['R' - 'A'] = 0;
	}
	if(cnt['W' - 'A']){
	    nD[2] += cnt['W' - 'A'];
	    cnt['T' - 'A'] -= cnt['W' - 'A'];
	    cnt['O' - 'A'] -= cnt['W' - 'A'];
	    cnt['W' - 'A'] -= cnt['W' - 'A'];
	}
	nD[1] = cnt['O' - 'A'];
	cnt['N' - 'A'] -= cnt['O' - 'A'];
	nD[8] = cnt['T' - 'A'];
	nD[9] = cnt['N' - 'A'] / 2;

	for(int i = 0; i < 10;++i)
	    for(int j = 0; j < nD[i]; ++j)
		cout << i;
	cout << '\n';

	memset(cnt, 0, sizeof(cnt));
	memset(nD, 0, sizeof(nD));

    }


    return 0;

}
