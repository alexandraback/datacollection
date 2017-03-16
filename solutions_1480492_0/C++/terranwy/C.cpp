#include <cstdio>

const int maxn = 50;

struct TCar {
	bool lane;
	int speed;
	double posi;
};

char ch;
bool stop;
int casei, cases, n, c1, c2;
double tm, itv;
TCar cars[maxn];

inline void check(int i, int j) {
	if (cars[i].lane != cars[j].lane) return;
	if (cars[i].posi > cars[j].posi) {
		int t = i;
		i = j;
		j = t;
	}
	if (cars[i].speed <= cars[j].speed) return;
	double co = (cars[j].posi - cars[i].posi - 5) / (cars[i].speed - cars[j].speed);
	if (c1 == -1 || co < itv) {
		itv = co;
		c1 = i;
		c2 = j;
	}
}

inline int sgn(double now) {
	if (now > 1e-10) return 1;
	if (now < -1e-10) return -1;
	return 0;
}

inline bool move(int car) {
	for (int i = 0; i < n; ++i) 
		if (i != car && cars[i].lane != cars[car].lane)
			if (!(sgn(cars[car].posi - cars[i].posi - 5) >= 0 || sgn(cars[car].posi + 5 - cars[i].posi) <= 0)) {
				return false;
			}
	cars[car].lane = !cars[car].lane;
	//printf("move car %d to %d\n", car, cars[car].lane);
	return true;
}

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf(" %c %d%lf", &ch, &cars[i].speed, &cars[i].posi);
			cars[i].lane = (ch == 'L');
		}
		
		tm = 0;
		stop = false;
		bool zero = false;
		while (true) {
			c1 = -1;
			for (int i = 0; i < n; ++i)
				for (int j = i + 1; j < n; ++j) check(i, j);
			if (c1 == -1) break;
			if (sgn(itv) == 0) {
				if (zero) {
					stop = true;
					break;
				}
				else zero = true;
			}
			else zero = false;
			
			for (int i = 0; i < n; ++i) cars[i].posi += cars[i].speed * itv;
			tm += itv;
			//printf("%d, %d: %.6lf\n", c1, c2, itv);			
			
			if (!move(c1))
				if (!move(c2)) {
					stop = true;
					break;
				}
		}
		if (stop) printf("Case #%d: %.6lf\n", casei, tm);
		else printf("Case #%d: Possible\n", casei);
	}
}
