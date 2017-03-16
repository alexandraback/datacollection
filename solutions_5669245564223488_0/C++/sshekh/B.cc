// Round 1C 2014 problem B
// saurav shekhar
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7
#define INF 2000000000
#define MOD 1000000009
typedef unsigned int ui;
typedef unsigned long long llu; //I64d
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const ui LIM = 100005; 
ui blen;

bool isvalid(string big)
{
	ui series[26];
	memset(series, 0, sizeof(series) );
	series[ big[0] - 'a' ] = 1;
	for(int i=1; i < blen; i++) {
		if(big[i] == big[i-1]) continue;
		else if( series[ big[i] - 'a' ]) return false;
		else series[ big[i] - 'a' ] = 1;
	}
	return true;
}

int main()
{
  ui T,qq;
  int N;
  ui perm[11];
  for(cin>>T, qq=1; qq<=T; qq++) {
	printf("Case #%u: ",qq);
	cin >> N;
	vector<string> sets;
	blen = 0;
	for(int i=0; i<N; i++) {
		sets.push_back("");
		cin >> sets[i];
		blen += sets[i].size();
	}
	
	ui ans = 0;
	for(ui i=0; i<N; i++) perm[i] = i;

	string bigtr;
	
	do {
		bigtr = "";
		for(ui i=0; i<N; i++) {
			bigtr += sets[ perm[i] ];
		}
		if(isvalid(bigtr)) ans = (ans + 1) % MOD;
	} while(next_permutation(perm,perm+N));
	
	cout << ans << "\n";
  }
	
  return 0;
}
