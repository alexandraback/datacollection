#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

int scts[26];
string digs[]{"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int dc[10][26];

string let="ZWXGHRFVOI";
string dig="0268345719";

int r[10];

string s;
int main() {
	int T;
	cin >> T;
	for (int c=0;c<10;c++) for (int d=0;d<digs[c].size();d++) dc[c][digs[c][d]-'A']++;

	for (int cas=1;cas<=T;cas++) {
		cin >> s;
		fill(scts,scts+26,0);
		for (int c=0;c<s.size();c++) scts[s[c]-'A']++;

		fill(r,r+10,0);
		for (int c=0;c<10;c++) {
			int i=dig[c]-'0';
			r[i]=scts[let[c]-'A'];
			for (int d=0;d<26;d++) scts[d]-=r[i]*dc[i][d];
		}

		printf("Case #%d: ",cas);
		for (int c=0;c<10;c++) for (int d=0;d<r[c];d++) printf("%d",c);
		cout << endl;
	}

}
