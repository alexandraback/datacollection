#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char C[25], J[25];
ll bestDiff=1100000000000000000LL;
char bestC[25];
char bestJ[25];

char tmpC[25], tmpJ[25];
int len;

ll strToLL(char* s){
	ll ret=0;
	for(int i=0; s[i]; ++i){
		ret *= 10;
		ret += s[i]-'0';
	}
	return ret;
}

void rec(int pos){
	if(pos == len){
		ll diff=strToLL(tmpC)-strToLL(tmpJ);
		if(diff < 0)diff=-diff;
		if(diff < bestDiff || (diff == bestDiff && strcmp(tmpC, bestC) < 0) || (diff == bestDiff && strcmp(tmpC, bestC) == 0 && strcmp(tmpJ, bestJ) < 0)){
			bestDiff=diff;
			strcpy(bestC, tmpC);
			strcpy(bestJ, tmpJ);
		}
		return;
	}
	tmpC[pos]=0;
	tmpJ[pos]=0;
	int cmp=strcmp(tmpC, tmpJ);
	if(C[pos] == '?'){
		if(J[pos] == '?'){
			if(cmp < 0){
				tmpC[pos]='9';
				tmpJ[pos]='0';
				rec(pos+1);
			}
			else if(cmp > 0){
				tmpC[pos]='0';
				tmpJ[pos]='9';
				rec(pos+1);
			}
			else{
				tmpC[pos]='0';
				tmpJ[pos]='0';
				rec(pos+1);
				tmpC[pos]='0';
				tmpJ[pos]='1';
				rec(pos+1);
				tmpC[pos]='1';
				tmpJ[pos]='0';
				rec(pos+1);
			}
		}
		else{
			tmpJ[pos]=J[pos];
			if(cmp < 0){
				tmpC[pos]='9';
				rec(pos+1);
			}
			else if(cmp > 0){
				tmpC[pos]='0';
				rec(pos+1);
			}
			else{
				if(J[pos] > '0'){
					tmpC[pos]=J[pos]-1;
					rec(pos+1);
				}
				if(J[pos] < '9'){
					tmpC[pos]=J[pos]+1;
					rec(pos+1);
				}
				tmpC[pos]=J[pos];
				rec(pos+1);
			}
		}
	}
	else{
		if(J[pos] == '?'){
			tmpC[pos]=C[pos];
			if(cmp < 0){
				tmpJ[pos]='0';
				rec(pos+1);
			}
			else if(cmp > 0){
				tmpJ[pos]='9';
				rec(pos+1);
			}
			else{
				if(C[pos] > '0'){
					tmpJ[pos]=C[pos]-1;
					rec(pos+1);
				}
				if(C[pos] < '9'){
					tmpJ[pos]=C[pos]+1;
					rec(pos+1);
				}
				tmpJ[pos]=C[pos];
				rec(pos+1);
			}
		}
		else{
			tmpC[pos]=C[pos];
			tmpJ[pos]=J[pos];
			rec(pos+1);
		}
	}
}

void solve(){
	scanf("%s%s", C, J);
	len=strlen(C);
	bestDiff=1100000000000000000LL;
	bestC[len]=0;
	bestJ[len]=0;
	tmpC[len]=0;
	tmpJ[len]=0;
	rec(0);
	printf("%s %s\n", bestC, bestJ);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i <= T; ++i){
		printf("Case #%d: ", i);
		solve();
	}
}
