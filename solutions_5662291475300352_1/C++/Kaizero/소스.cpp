#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
#define pli pair<long long, int>
set<pli>Set;
struct P{
	long long v, d;
	bool operator<(const P &p)const{
		return v < p.v;
	}
}w[501000];
int CC[501000];
long long w2[501000];
long long Gap(int a, int c){
	return (c * 360 - w[a].d) * w[a].v;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC, TT, nn, n, i, a, b, c, j, Res, M, S, T, pv;
	set<pli>::iterator it;
	pli tp;
	scanf("%d", &TC);
	for (TT = 1; TT <= TC; TT++){
		printf("Case #%d: ", TT);
		scanf("%d", &nn);
		n = 0;
		for (i = 1; i <= nn; i++){
			scanf("%d%d%d", &a, &b, &c);
			for (j = c; j <= c + b - 1; j++){
				n++;
				w[n].d = a;
				w[n].v = j;
			}
		}
		sort(w + 1, w + n + 1);
		Res = n + 1;
		for (i = 1; i <= n; i++)w2[i] = Gap(i, 1);
		sort(w2 + 1, w2 + n + 1);
		Set.clear();
		for (i = 1; i <= n; i++){
			Set.insert(pli(Gap(i, 2), i));
			CC[i] = 2;
		}
		T = 0;
		pv = 1;
		while (T < Res){
			it = Set.begin();
			tp = *it;
			Set.erase(it);
			while (pv <= n && tp.first > w2[pv]){
				pv++;
			}
			a = tp.second;
			CC[a]++;
			Set.insert(pli(Gap(a, CC[a]), a));
			Res = min(Res, n + 1 - pv + T);
			T++;
		}
		printf("%d\n", Res);
	}
}