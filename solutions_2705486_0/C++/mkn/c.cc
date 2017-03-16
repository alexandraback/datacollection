#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<cstdlib>
#include<cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;

#define mp make_pair
#define pb push_back

#define repp(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define rep(i,n) repp(i,0,(n)-1)

#define DN 521196

string s;
string di[DN+10];

char buf[10000000];
int memo[5000][10];
int depth;

int sol(int x, int dame){
	if(memo[x][dame] != -1) return memo[x][dame];
	if(x == s.size()) {
		return 0;
	}
	++depth;
	int res = 4000;
	rep(i,DN){
		int j=0;
		int dam=0, sc=0;
		if((int)di[i].size() + x > s.size()) goto tugi;
		for(; j < min(dame,(int)di[i].size()); ++j) if(s[x+j] != di[i][j]) goto tugi;
		while(j < (int)di[i].length()){
			if(s[x+j] != di[i][j]){
				if(dam) goto tugi;
				else dam = 4;
				++sc;
			}else{
				if(dam) --dam;
			}
			++j;
		}
//rep(forr,depth) cout<<"   ";
//cout << di[i] << " " << dam << endl;
		res = min(res, sc + sol(x+di[i].length(), max(dam,dame-(int)di[i].size())));
tugi:;
	}
	--depth;
	return (memo[x][dame] = res);
}

int solve(){
	depth=0;
	rep(i,4500) rep(j,9) memo[i][j] = -1;
	return sol(0,0);
}

int main(){
	FILE *fp;
	if((fp = fopen("garbled_email_dictionary.txt","r")) == NULL) exit(EXIT_FAILURE);
	rep(i,DN){
		fscanf(fp, " %s", buf);
		di[i] = buf;
	}
	int casenum; cin >> casenum;
	rep(cas, casenum){
		cin >> s;
		printf("Case #%d: %d\n", cas+1, solve());
	}
	return 0;
}

