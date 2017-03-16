#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

int i, j, k, kejsis, kejs, n;
struct CAR {
	char lane;
	double pos;
	double aktpos;
	double speed;
} c[50];
char s[10];
double ret;
set<double> v;
set<double>::iterator it;

double dobehne(int i, int j) {
	double t = 0;
	if (fabs(c[i].speed - c[j].speed) < 1e-9) return -1;
	t = (5 + c[i].pos - c[j].pos) / (c[j].speed-c[i].speed);
	return t;
}

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%s%lf%lf", s, &c[i].speed, &c[i].pos);
			c[i].lane = s[0];
		}
		v.clear();
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				v.insert(dobehne(i, j));
			}
		}
		ret = -1;
		for (it = v.begin(); it != v.end(); ++it) {
			if (*it < 1e-9) continue;
			for (i = 0; i < n; i++) {
				c[i].aktpos = c[i].pos + c[i].speed * (*it);
			}
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (i == j) continue;
					if (c[i].lane != c[j].lane) continue;
					if (fabs(c[i].aktpos + 5 - c[j].aktpos) < 1e-9 && c[i].speed > c[j].speed + 1e-9) {
						c[i].lane = c[i].lane == 'L' ? 'R' : 'L';
						for (k = 0; k < n; k++) {
							if (i == k || c[i].lane != c[k].lane) continue;
							if (max(c[i].aktpos, c[k].aktpos)-1e-9 < min(c[i].aktpos+5, c[k].aktpos+5)) break;
						}
						if (k < n) {
							c[i].lane = c[i].lane == 'L' ? 'R' : 'L';
							c[j].lane = c[j].lane == 'L' ? 'R' : 'L';
							for (k = 0; k < n; k++) {
								if (j == k || c[j].lane != c[k].lane) continue;
								if (max(c[j].aktpos, c[k].aktpos)-1e-9 < min(c[j].aktpos+5, c[k].aktpos+5)) break;
							}
							if (k < n) {
								ret = (*it);
								goto end;
							}
						}
					}
				}
			}
		}
end:
		if (ret == -1) printf("Possible\n");
		else printf("%.10lf\n", ret);
	}
	return 0;
}


