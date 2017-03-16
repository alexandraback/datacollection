#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define N 1005
using namespace std;

int n, ed;
map<string, int> S1, S2;
int l[N], qd[N], qn[N], f[N], v[N];
char s1[44], s2[44];

int dfs(int x){
	EXP(i,l[x]) if (!v[qd[i]]){
		v[qd[i]] = 1;
		if (f[qd[i]] == -1 || dfs(f[qd[i]])){
			f[qd[i]] = x;
			return 1;
		}
	}
	return 0;
}

int BiMatch(){
	int ret = 0;
	memset(f, -1, sizeof(f));
	FOE(i,1,n){
		memset(v, 0, sizeof(v));
		ret += dfs(i);
	}
	return ret;
}


int trans(char s[], map<string, int> *S){
	if (S->find((string)s) != S->end()) return (*S)[(string)s];
	int t = S->size();
	(*S)[(string)s] = t + 1;
	return t + 1;
}



int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d:", TC);
	scanf("%d", &n);
	S1.clear(), S2.clear();
	CLR(l, 0);
	ed = 0;
	
	FOR(i,0,n){
		scanf("%s%s", s1, s2);
		int x = trans(s1, &S1);
		int y = trans(s2, &S2);
		qd[++ed] = y, qn[ed] = l[x], l[x] = ed;
	}
	printf(" %d\n", n - (S1.size() + S2.size() - BiMatch()));
}return 0;}
