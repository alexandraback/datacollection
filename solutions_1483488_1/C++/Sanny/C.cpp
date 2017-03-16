#pragma warning(disable:4786)
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define rep(i,n) for(i=0;i<(n);i++)
#define MAX 105

int A, B;

char s[10];
string st;

int p10[12];
set< pair<int,int> > res;

/*
void go(int n) {
	int L, i,m;
	sprintf(s,"%d",n);
	st = s;
	L = st.size();
	for(i=0;i<L-1;i++) {
		m = atoi(st.substr(0,i+1).c_str()) + atoi(st.substr(i+1).c_str()) * p10[i+1];
		sprintf(s,"%d",m);
		if(strlen(s) < L) continue;
		if(m > n && m <= B) {
			//printf("%d %d %d %d\n",A,n,m,B);
			//res++;
			res.insert( make_pair(n, m) );
		}
	}
}*/

int t1[12], t2[12];

void go2(int n) {
	int L, i,m, cur,j;
	sprintf(s,"%d",n);
	L = strlen(s);
	cur = 0;
	for(i=0;i<L;i++) cur = t1[i] = cur * 10 + (s[i]-'0');
	cur = 0;
	for(i=L-1,j=0;i>=0;i--,j++) cur = t2[i] = cur + (s[i]-'0')*p10[j];

	for(i=0;i<L-1;i++) {
		//m = atoi(st.substr(0,i+1).c_str()) + atoi(st.substr(i+1).c_str()) * p10[i+1];
		if(s[i+1] == '0') continue;
		m = t1[i] + t2[i+1]*p10[i+1];
		//sprintf(s,"%d",m);
		//if(strlen(s) < L) continue;
		if(m > n && m <= B) {
			//printf("%d %d %d %d\n",A,n,m,B);
			//res++;
			res.insert( make_pair(n, m) );
		}
	}
}

void solve() {
	int i;
	res.clear();
	for(i = A; i < B; i++) {
		go2(i);
	}
	printf("%d\n",res.size());
}

void init() {
	int i;
	p10[0] = 1;
	for(i=1;i<=9;i++) p10[i] = p10[i-1]*10;
}

int main() {
	int T, kase = 1;
	scanf(" %d",&T);
	init();
	while(T--) {
		printf("Case #%d: ", kase++);
		scanf(" %d %d", &A, &B);
		solve();
	}
	return 0;
}