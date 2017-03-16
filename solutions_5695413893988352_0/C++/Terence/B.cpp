#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;
#define N 30
#define INF 1100000000000000000LL

void updateMinMax(const char *sc, const char *sj, int off, int n, long long vc, long long vj, long long &mc, long long &mj)
{
	for(int i = off; i < n; i++) {
		vc = vc * 10 + (sc[i]=='?' ? 0 : sc[i]-'0');
		vj = vj * 10 + (sj[i]=='?' ? 9 : sj[i]-'0');
	}
	if(abs(vc-vj) < abs(mc-mj) || (abs(vc-vj)==abs(mc-mj) && (vc < mc || (vc == mc && vj < mj)))) {
		mc = vc; mj = vj;
	}
}
pair<long long, long long> minDiff(const char *sc, const char *sj, int n)
{
	long long d = 0, b = 1, vc = 0, vj = 0;
	long long mc = INF, mj = -INF;

	for(int i = 0; i < n && vc == vj; i++) {
		if(sc[i] != '?') {
			if(sj[i] != '?') {
				vc = vc * 10 + sc[i]-'0';
				vj = vj * 10 + sj[i]-'0';
				if(vc > vj) {
					updateMinMax(sc, sj, i+1, n, vc, vj, mc, mj);
					break;
				} else if(vc < vj) {
					break;
				}
			} else {
				if(sc[i] > '0') {
					updateMinMax(sc, sj, i+1, n, vc*10+sc[i]-'0', vj*10+sc[i]-'1', mc, mj);
				}
				vc = vc * 10 + sc[i]-'0';
				vj = vj * 10 + sc[i]-'0';
			}
		} else {
			if(sj[i] != '?') {
				if(sj[i] < '9') {
					updateMinMax(sc, sj, i+1, n, vc*10+sj[i]-'0'+1, vj*10+sj[i]-'0', mc, mj);
				}
				vc = vc * 10 + sj[i]-'0';
				vj = vj * 10 + sj[i]-'0';
			} else {
				updateMinMax(sc, sj, i+1, n, vc*10+1, vj*10, mc, mj);
				vc = vc * 10;
				vj = vj * 10;
			}
		}
	}
	if(vc == vj && (mc > mj || (mc == mj && vc < mc))) {
		mc = vc; mj = vj;
	}
	return make_pair(mc, mj);
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int icase = 1; icase <= t; icase++) {
		char sc[N], sj[N];
		scanf("%s%s", sc, sj);
		int n = strlen(sc);
		pair<long long, long long> o1 = minDiff(sc, sj, n);
		pair<long long, long long> o2 = minDiff(sj, sc, n);
		long long vc, vj;
		if(abs(o1.first-o1.second) < abs(o2.first-o2.second)) {
			vc = o1.first; vj = o1.second;
		} else if(abs(o1.first-o1.second) > abs(o2.first-o2.second)) {
			vj = o2.first; vc = o2.second;
		} else if(o1.first < o2.second || (o1.first == o2.second && o1.second < o2.first)) {
			vc = o1.first; vj = o1.second;
		} else {
			vj = o2.first; vc = o2.second;
		}
		printf("Case #%d: %0*lld %0*lld\n", icase, n, vc, n, vj);
	}
  return 0;
}
