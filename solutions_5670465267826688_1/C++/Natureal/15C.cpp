#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 200010;

int T;
ll X,L;
char pre[MAXN];
char s[MAXN / 4],S[MAXN];
char mp[200][200];
char pr[200];

void Pre(){
	pr['2'] = '1'; pr['1'] = '2';
	pr['3'] = 'i'; pr['i'] = '3';
	pr['4'] = 'j'; pr['j'] = '4';
	pr['5'] = 'k'; pr['k'] = '5';
	mp['1']['1']='1',mp['1']['i']='i',mp['1']['j']='j',mp['1']['k']='k';
	mp['i']['1']='i',mp['i']['i']='2',mp['i']['j']='k',mp['i']['k']='4';
	mp['j']['1']='j',mp['j']['i']='5',mp['j']['j']='2',mp['j']['k']='i';
	mp['k']['1']='k',mp['k']['i']='j',mp['k']['j']='3',mp['k']['k']='2';
}

char Mul(char a,char b){
	int f = 0;
	if(a >= '2' && a <= '5'){
		a = pr[a];
		f ^= 1;
	}
	if(b >= '2' && b <= '5'){
		b = pr[b];
		f ^= 1;
	}
	char res = mp[a][b];
	if(f) res = pr[res];
	return res;
}

int main(){
	freopen("15C.out","w",stdout);
	Pre();
	scanf("%d",&T);
	FOR(tt,1,T){
		cin >> L >> X;
		if(X > 12) X = X % 4LL + 12;
		scanf("%s",s);
		memcpy(S,s,sizeof(s));
		for(int i = 0; i < X; ++i) strcat(S,s);
		L *= X;
		char c = '1';
		for(int i = 0; i < L; ++i){
			c = Mul(c,S[i]);
			pre[i] = c;
		}
		bool flag = false;
		char tot = pre[L];
		int p1 = 0,p2 = 0;
		if(pre[L - 1] == '2'){
			for(int i = 0; i < L; ++i){
				if(pre[i] == 'i') p1 = 1;
				else if(pre[i] == 'k' && p1){
					p2 = 1;
					flag = true;
					break;
				}
			}
		}
		printf("Case #%d: ",tt);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

