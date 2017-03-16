#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <iostream>

#define ln printf("\n")
typedef long long ll;

#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)

#define dbg(x) cerr << #x << " = " << x << endl
#define db dbg
#define _  << " , " <<

#define sarr(r,n) rep(i,n) scanf("%d", &r[i])
#define parr(r,n) printf("%d", r[0]); fr(i,1,n) printf(" %d", r[i]);  ln; 
#define mem(r,v) memset(r, v, sizeof r)

using namespace std;

const double eps = 1e-8;
int n;

int cn = 1;

char buf[4444];
int sres[15][6];
char s[4444];

int dist(int a, int b){
	int res = min(abs(a-b), abs(a-(b+26)));
	res = min(res, abs((a+26)-b));
	
	return res;
}



struct trie{
	trie * v [26];	
	bool word;
	char let;
	
	trie(){
		rep(i,26) v[i] = NULL;
	}
	
	trie(char x){
		rep(i,26) v[i] = NULL;
		word = false;
		let = x;		
	}
	
	void add(int pos){
		//printf("%d(%c) at %lld\n", pos, buf[pos], (ll)(this));
		//printf("Word is %s\n", buf);
		//printf("Letter at %d of %s is %c\n", pos+1, buf, buf[pos+1]);
		if(buf[pos+1] == 0){
			//printf("Finished %s\n", buf);
			word = true;
		}
		else{
			//printf("%d is not the end\n", pos);
			int x = buf[pos+1] - 'a';
			if(v[x] == NULL){
				//printf("Creating new trie for\n");
				v[x] = new trie(buf[pos+1]);
			}
			v[x]->add(pos+1);
		}
	}
	
	void search(int pos, int size, int mis, int rem, string ss){
		//printf("%d %d %d %d %s %lld\n", pos, size, mis, rem, ss.c_str(), (ll)(this));				
		
		if(s[pos] != let){
			if(rem) return;
			rem = 5;
			mis++;
		}
		
		//ss += let;
		
		if(word){
			//printf("Match %s\n", ss.c_str());
			sres[size][rem] = min(sres[size][rem], mis);
			//printf("sres[%d][%d] = %d\n", size, rem, sres[size][rem]);
		}
		
		rep(i,26) if(s[pos+1] && v[i] != NULL) v[i]->search(pos+1, size+1, mis, rem?rem-1:0,ss);
	}
};

trie base;

void search(int pos, int rem){
	rep(i,15) rep(j,6) sres[i][j] = 1000000;
	
	int x = s[pos] - 'a';
	
	string ss = "";
	
	if(base.v[x] != NULL){
		base.v[x]->search(pos, 1, 0, rem, ss);
	}
	if(rem == 0){
		rep(i,26){
			if(base.v[i] != NULL) base.v[i]->search(pos, 1, 0, rem, ss);
		}
	}
	
	//rep(i,15) rep(j,6) printf("sres[%d][%d] = %d\n", i, j, sres[i][j]);
}

void add(){
	int x = buf[0] - 'a';
	
	if(base.v[x] == NULL) base.v[x] = new trie(buf[0]);
	base.v[x]->add(0);
}

int dp[4444][6];

int rec(int pos, int rem){
	if(s[pos] == 0) return 0;
	if(dp[pos][rem] != -1) return dp[pos][rem];
	
	//printf("calling %d %d\n", pos, rem);
	
	search(pos, rem);
	
	int res = 100000;
	
	int srest[15][6];
	rep(i,15) rep(j,6) srest[i][j] = sres[i][j];
	
	rep(i,15) rep(j,6){
		if(srest[i][j] != 1000000){
			//printf("%d %d is %d\n", i, j, srest[i][j]);
			res = min(res, srest[i][j] + rec(pos+i, j?j-1:0));
		}
	}
	
	//printf("dp[%d][%d] = %d\n", pos, rem, res);
	
	return dp[pos][rem] = res;
}

bool read(){
	scanf("%s", s);
	
	return true;
}

void process(){
	printf("Case #%d: ", cn++);
	
	//search(0);
	
	mem(dp, -1);	
	
	printf("%d\n", rec(0,0));
}

void init(){
	FILE * f = fopen("dic.in", "r");
	
	rep(i,521196){
		fscanf(f, "%s", buf);
		//printf("Adding word %s\n", buf);
		add();
		//printf("Done adding %s\n", buf);
	}
}

int main(){	
	int t = -1;
	
	init();
	
	scanf("%d", &t);
	
	while(t-- && read()){		
		process();
	}	
	
	return 0;
}
