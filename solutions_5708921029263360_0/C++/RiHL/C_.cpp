#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int J, P, S, K;

#define MAX(a,b) ((a) > (b) ? (a) : (b))

struct jps {
	int j, p, s;
};

void vypis(vector <struct jps> v)
{
	printf("%d\n", v.size());
	for (auto a: v)
		printf("%d %d %d\n", a.j + 1, a.p + 1, a.s + 1);

	fflush(stdout);
}

struct jps next(struct jps jps)
{
	if (jps.s < S - 1){
		jps.s++;
		return jps;
	}

	jps.s = 0;
	if (jps.p < P - 1){
		jps.p++;
		return jps;
	}

	jps.p = 0;
	if (jps.j < J - 1){
		jps.j++;
		return jps;
	}

	jps.j = -1;
	return jps;
}

int JP[10][10], PS[10][10], SJ[10][10];

vector <struct jps> rec(struct jps now)
{
	struct jps ne = next(now);
	int j = ne.j, p = ne.p, s = ne.s;
	if (j == -1){
		vector <struct jps> prazdny;
		return prazdny;
	}

	pair <int, int> a = {ne.j, ne.p}, b = {ne.p, ne.s}, c = {ne.s, ne.j};
	vector <struct jps> one, two;
	if (JP[j][p] < K && PS[p][s] < K && SJ[s][j] < K){
		JP[j][p]++;
		PS[p][s]++;
		SJ[s][j]++;
		one = rec(ne);
		one.push_back(ne);
		JP[j][p]--;
		PS[p][s]--;
		SJ[s][j]--;
	}
	two = rec(ne);

	if (one.size() >= two.size())
		return one;

	return two;
}

void solve(void)
{
	scanf("%d %d %d %d", &J, &P, &S, &K);
	vector <struct jps> res;
	for (int j=0; j<J; j++){
		for (int p=0; p<P; p++)
			JP[j][p] = 0;

		for (int s=0; s<S; s++)
			SJ[s][j] = 0;
	}

	for (int p=0; p<P; p++)
		for (int s=0; s<S; s++)
			PS[p][s] = 0;

	JP[0][0] = PS[0][0] = SJ[0][0] = 1;
	res.push_back({0, 0, 0});
	for (auto a: rec({0, 0, 0}))
		res.push_back(a);

	vypis(res);
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d: ", i + 1);
		solve();
	}
}
