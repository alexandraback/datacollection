#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MX = 10000;
const int MID = 1500;

int t, n, wall[MX];

struct attack {
	int d, p, k, s;
	attack() {}
	attack(int _d, int _p, int _k, int _s) {
		d = _d;
		p = _p;
		k = _k;
		s = _s;
	}
};

vector<attack> ats, stos;

bool cmp_day(attack FOO, attack BAR) {
	return FOO.d < BAR.d;
}

void update(attack FOO) {
	for(int i=FOO.p;i<=FOO.k;i++) wall[i] = max(wall[i], FOO.s);
}

int solve() {
	for(int i=0;i<=2*MID;i++) wall[i] = 0;
	int ret = 0;
	ats.clear();
	stos.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
		scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &delta_di, &delta_pi, &delta_si);
		wi *= 2; ei *= 2;
		wi += MID; ei += MID;
		for(int j=1;j<=ni;j++) {
			ats.push_back(attack(di, wi, ei, si));
			wi += delta_pi*2;
			ei += delta_pi*2;
			si += delta_si;
			di += delta_di;
		}
	}
	sort(ats.begin(), ats.end(), cmp_day);
	//for(int i=0;i<ats.size();i++) printf("%d: %d %d %d %d\n", i, ats[i].d, ats[i].p, ats[i].k, ats[i].s);
	for(int i=0;i<ats.size();i++) {
		bool zle = false;
		for(int j=ats[i].p;j<=ats[i].k;j++) {
			if(wall[j] < ats[i].s) zle = true;
		}
//		if(zle) printf("Atak %d udany\n", i);
//		else printf("Atak %d nieudany\n", i);
		ret += zle;
		if(stos.size() > 0 && ats[i].d != stos.back().d) {
			while(!stos.empty()) {
				//printf("Usuwam atak z dnia %d\n", stos.back().d);
				update(stos.back());
				stos.pop_back();
			}
		}
		stos.push_back(ats[i]);
	}
	return ret;
}

int main() {
	scanf("%d",&t);
	for(int cs=1;cs<=t;cs++) {
		printf("Case #%d: %d\n", cs, solve());
	}
	return 0;
}
