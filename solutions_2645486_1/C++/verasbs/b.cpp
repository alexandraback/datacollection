#include <stdio.h>
#include <list>
#include <algorithm>

#define MAXN 10005

using namespace std;

list<int> lista;
list<int>::iterator its[MAXN];
pair<long long, int> sv[MAXN];
long long e, r, n, v[MAXN];

long long doit(int d, long long c, long long sf) {
	//printf("%d %d %d\n", d, c, sf);
	if(d == n) return sf;
	long long ssp = c;
	for(list<int>::iterator it = lista.begin(); it != lista.end(); it++) {
		int mad = *it;
		long long sp = c + (mad-d)*r - e;
		//printf("%d %d %d\n", d, mad, sp);
		if(mad == d) {
			lista.erase(it);
			if(ssp > 0) return doit(d+1, max(0LL, c-ssp) + r, sf+min(c, ssp)*v[d]);
			else return doit(d+1, r, sf + c*v[d]);
		}
		ssp = min(ssp, sp);
		if(sp <= 0)  {
			lista.erase(its[d]);
			return doit(d+1, c+r, sf);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++) {
		lista.clear();
		scanf("%lld%lld%lld", &e, &r, &n);
		for(int i = 0; i < n; i++) {
			scanf("%lld", &v[i]);
			sv[i] = make_pair(-v[i], i);
		}

		sort(sv, sv+n);
		for(int i = 0; i < n; i++)
			lista.push_back(sv[i].second);

		for(list<int >::iterator it = lista.begin(); it != lista.end(); it++)
			its[*it] = it;

		printf("Case #%d: %lld\n", ca, doit(0, e, 0));
	}
	return 0;
}
