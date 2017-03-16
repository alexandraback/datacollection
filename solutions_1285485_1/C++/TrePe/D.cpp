#include <stdio.h>
#include <math.h>

int i, j, k, cnt;
int n, H, W, D, nw;
char a[30][31];

enum TYPE {
	reflect,
	blackhole,
	nothing,
	back
};

struct P {
	double x, y;
	double len() {
		return sqrt(x*x + y*y);
	}
	void normalize() {
		static double d;
		d = len();
		x /= d;
		y /= d;
	}
} start, v;
P was[1000000];

struct L {
	P A, B;
} lines[4*30*30];
int nl;

bool wasq(P v) {
	static int i;
	static double d;
	d = v.len();
	v.x /= d; v.y /= d;
	for (i = 0; i < nw; i++) {
		if (fabs(was[i].x - v.x) < 1e-9 && fabs(was[i].y - v.y) < 1e-9) return true;
	}
	return false;
}

void wasadd(P v) {
	static double d;
	d = v.len();
	was[nw].x = v.x/d; was[nw].y = v.y/d;
	nw++;
}

P get_new_v(P cur, L line, P v) {
	int r, c;
	TYPE type = reflect;
	if (fabs(cur.x - floor(cur.x+1e-9)) < 1e-9 && fabs(cur.y - floor(cur.y+1e-9)) < 1e-9) {
		r = floor(cur.x+1e-9) - 1; c = floor(cur.y+1e-9) - 1;
		if (a[r][c] == '#' && a[r][c+1] == '#' && a[r+1][c] == '#' && a[r+1][c+1] == '.') type = back;
		if (a[r][c] == '#' && a[r][c+1] == '#' && a[r+1][c] == '.' && a[r+1][c+1] == '#') type = back;
		if (a[r][c] == '#' && a[r][c+1] == '.' && a[r+1][c] == '#' && a[r+1][c+1] == '#') type = back;
		if (a[r][c] == '.' && a[r][c+1] == '#' && a[r+1][c] == '#' && a[r+1][c+1] == '#') type = back;
		if (a[r][c] == '.' && a[r][c+1] == '#' && a[r+1][c] == '#' && a[r+1][c+1] == '.') type = nothing;
		if (a[r][c] == '#' && a[r][c+1] == '.' && a[r+1][c] == '.' && a[r+1][c+1] == '#') type = nothing;
		if ((a[r][c] == '#' && a[r][c+1] == '#' && a[r+1][c] == '.' && a[r+1][c+1] == '.') || 
		    (a[r][c] == '.' && a[r][c+1] == '.' && a[r+1][c] == '#' && a[r+1][c+1] == '#')) {
			line.A.x = line.B.x = 0;
			line.A.y = 0; line.B.y = 1;
		}
		if ((a[r][c] == '#' && a[r][c+1] == '.' && a[r+1][c] == '#' && a[r+1][c+1] == '.') || 
		    (a[r][c] == '.' && a[r][c+1] == '#' && a[r+1][c] == '.' && a[r+1][c+1] == '#')) {
			line.A.y = line.B.y = 0;
			line.A.x = 0; line.B.x = 1;
		}
		if (a[r][c] == '#' && a[r][c+1] == '.' && a[r+1][c] == '.' && a[r+1][c+1] == '.') {
			if (v.x < -1e-9 && v.y < -1e-9) type = blackhole;
			else type = nothing;
		}
		if (a[r][c] == '.' && a[r][c+1] == '#' && a[r+1][c] == '.' && a[r+1][c+1] == '.') {
			if (v.x < -1e-9 && v.y > 1e-9) type = blackhole;
			else type = nothing;
		}
		if (a[r][c] == '.' && a[r][c+1] == '.' && a[r+1][c] == '#' && a[r+1][c+1] == '.') {
			if (v.x > 1e-9 && v.y < -1e-9) type = blackhole;
			else type = nothing;
		}
		if (a[r][c] == '.' && a[r][c+1] == '.' && a[r+1][c] == '.' && a[r+1][c+1] == '#') {
			if (v.x > 1e-9 && v.y > 1e-9) type = blackhole;
			else type = nothing;
		}
	}
	switch (type) {
	case reflect:
		if (line.A.x == line.B.x) {
			v.x = -v.x;
		}
		if (line.A.y == line.B.y) {
			v.y = -v.y;
		}
		break;
	case back:
		v.x = -v.x;
		v.y = -v.y;
		break;
	case blackhole:
		v.x = 1e123;
		break;
	case nothing:
		break;
	}
	return v;
}

bool yes(P v, bool writeout = false) {
	double d = 0, mind, travelled = 0;
	P cur = start, next, minnext = start;
	double s = 0, t = 0;
	int i, mini = -1;
	if (writeout) fprintf(stderr, "---\n");
	for (;;) {
		if (writeout) fprintf(stderr, "Arrow[{{%.2lf,%.2lf},{%.2lf,%.2lf}}],\n", cur.x, cur.y, cur.x+v.x, cur.y+v.y);
		
		mind = 1e123;
		for (i = 0; i < nl; i++) {
			s = lines[i].A.y * v.x - lines[i].B.y * v.x - lines[i].A.x * v.y + lines[i].B.x * v.y;
			if (s == 0) continue; // parallel
			t = lines[i].A.y * lines[i].B.x - lines[i].A.x * lines[i].B.y - lines[i].A.y * cur.x + lines[i].B.y * cur.x + lines[i].A.x * cur.y - lines[i].B.x * cur.y;
			t /= s;
			s = (lines[i].A.y * v.x - cur.y * v.x - lines[i].A.x * v.y + cur.x * v.y) / s;
			if (t > 1e-9 && s > -1e-9 && s < 1 + 1e-9) { // intersects
				next.x = lines[i].A.x + s * (lines[i].B.x - lines[i].A.x);
				next.y = lines[i].A.y + s * (lines[i].B.y - lines[i].A.y);
				d = sqrt((next.x-cur.x)*(next.x-cur.x) + (next.y-cur.y)*(next.y-cur.y));
				if (d > 1e-9 && d < mind) {
					mind = d;
					minnext = next;
					mini = i;
				}
			}
		}

		// did we find solution? - does the start lie on the current half line?
		// and is it closer than reflection point?
		bool found = true;
		if (fabs(v.x) < 1e-9 && fabs(cur.x - start.x) > 1e-9) found = false;
		if (fabs(v.y) < 1e-9 && fabs(cur.y - start.y) > 1e-9) found = false;
		if (found) {
			found = false;
			if (fabs(v.x) >= 1e-9) s = (start.x - cur.x) / v.x;
			if (fabs(v.y) >= 1e-9) t = (start.y - cur.y) / v.y;
			if (fabs(v.x) < 1e-9 && t > 1e-9) found = true;
			if (fabs(v.y) < 1e-9 && s > 1e-9) found = true;
			if (!found && fabs(v.x) >= 1e-9 && fabs(v.y) >= 1e-9) {
				if (fabs(s-t) < 1e-9 && fabs(s) > 1e-9) found = true;
			}
		}

		if (found) {
			d = sqrt((cur.x-start.x)*(cur.x-start.x) + (cur.y-start.y)*(cur.y-start.y));
			if (d < mind) {
				travelled += d;
				if (travelled > D + 1e-9) return false;
				if (writeout) fprintf(stderr, "travelled: %.4lf\n", travelled);
				return true;
			}
		}


		travelled += mind;
		if (travelled > D + 1e-9) return false;
		cur = minnext;
		if (writeout) fprintf(stderr, "Point[{%.2lf, %.2lf}],\n", cur.x, cur.y);
		v = get_new_v(cur, lines[mini], v);
		if (v.x == 1e123) return false; // black hole
	}
	return true;
}

int main() {
	int i,j;
	scanf("%d", &n);
	for (int kejs = 1; kejs <= n; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d%d%d", &H, &W, &D);
		for (i = 0; i < H; i++) scanf("%s", a[i]);
		nl = 0;
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				if (a[i][j] == 'X') start.x = i + 0.5, start.y = j + 0.5, a[i][j] = '.';
				if (a[i][j] == '#') {
					lines[nl].A.x = i; lines[nl].A.y = j; lines[nl].B.x = i+1; lines[nl].B.y = j;
					++nl;
					lines[nl].A.x = i+1; lines[nl].A.y = j; lines[nl].B.x = i+1; lines[nl].B.y = j+1;
					++nl;
					lines[nl].A.x = i+1; lines[nl].A.y = j+1; lines[nl].B.x = i; lines[nl].B.y = j+1;
					++nl;
					lines[nl].A.x = i; lines[nl].A.y = j; lines[nl].B.x = i; lines[nl].B.y = j+1;
					++nl;
				}
			}
		}
		/*
		if (kejs == 27) {
		for (i = 0; i < nl; i++) {
			fprintf(stderr, "{{%d,%d},{%d,%d}},", (int) lines[i].A.x, (int) lines[i].A.y, (int) lines[i].B.x, (int) lines[i].B.y);
		}
		fprintf(stderr, "\nPoint[{%.1lf, %.1lf}]\n", start.x, start.y);
		}*/
		nw = 0;
		cnt = 0;
		for (i = -D-1; i <= D+1; i++) {
			for (j = -D-1; j <= D+1; j++) {
				if (i == 0 && j == 0) continue;
				v.x = i;
				v.y = j;
				v.normalize();
				if (!wasq(v)) {
					wasadd(v);
					if (yes(v)) {
						cnt++;
//						yes(v, kejs == 27);
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
