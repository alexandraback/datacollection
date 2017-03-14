#include <iostream>
#include <stdio.h>
#include <math.h>

#define STEP (M_PI / 100000.0f)
//#define STEP (M_PI / 64.0f)
#define EPSILON 0.00001
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define FEQ(a, b) (fabs(a - b) < EPSILON)
//#define DEBUG

char box[32][32];

void printbox(int x, int y)
{
	int i, j;

	fprintf(stderr, "(%d, %d): %c\n", x, y, box[y][x]);
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++)
			if (i == y && j == x)
				fprintf(stderr, "*");
			else
				fprintf(stderr, "%c", box[i][j]);
		fprintf(stderr, "\n");
	}
}

int cast_ray(double x0, double y0, double angle, double dist)
{
	int hit;
	double x, y, x1, y1, d1, d2;
	double cosphi, sinphi;
	double xmod, ymod;
	int intx, inty;
	double tmp;
	int horsnap;
	char c1, c2;

	x = x0;
	y = y0;
	hit = 0;
	while (hit == 0 && dist > 0.0f) {
#ifdef DEBUG
		fprintf(stderr, "--> %f, %f (%f) <%f\n", x, y, dist, angle * 180.0f / M_PI);
#endif
		cosphi = cos(angle);
		sinphi = sin(angle);
		if (cosphi != 0.0f) {
			x1 = (cosphi > 0) ?
					MIN(floor(x + 1.0f), floor(x + 0.5f) + 0.5f) :
					MAX(ceil(x - 1.0f), floor(x) - 0.5f);
			d1 = (x1 - x) / cosphi;
		} else
			d1 = 512.0f;
		if (sinphi != 0.0f) {
			y1 = (sinphi > 0) ?
					MIN(floor(y + 1.0f), floor(y + 0.5f) + 0.5f) :
					MAX(ceil(y - 1.0f), floor(y) - 0.5f);
			d2 = (y1 - y) / sinphi;
		} else
			d2 = 512.0f;
		if (d1 < d2) {
			y = y + d1 * sinphi;
			x = x1;
			dist -= d1;
			horsnap = 1;
		} else {
			x = x + d2 * cosphi;
			y = y1;
			dist -= d2;
			horsnap = 0;
		}
#ifdef DEBUG
		fprintf(stderr, "<-- %f, %f (%f) <%f\n", x, y, dist, angle * 180.0f / M_PI);
#endif
		if (dist < 0.0f) {
#ifdef DEBUG
			fprintf(stderr, "Distance over\n");
#endif
			break;
		}

		xmod = modf(x, &tmp);
		ymod = modf(y, &tmp);
		intx = (int) x;
		inty = (int) y;
		if (FEQ(ymod, 0.0f) && sinphi < 0.0f)
			inty--;
		if (FEQ(xmod, 0.0f) && cosphi < 0.0f)
			intx--;
#ifdef DEBUG
		printbox(intx, inty);
#endif
		if (box[inty][intx] == 'X')
			if (FEQ(xmod, 0.5f) && FEQ(ymod, 0.5f)) {
#ifdef DEBUG
				fprintf(stderr, "Hit\n");
#endif
				hit = 1;
				break;
			} else
				continue;
		if (box[inty][intx] == '.')
			continue;
		if ( (FEQ(xmod, 0.0f) && ! FEQ(ymod, 0.0f)) ||
		     (! FEQ(xmod, 0.0f) && FEQ(ymod, 0.0f)) ) {
			if (horsnap)
				angle = M_PI - angle;
			else
				angle = -angle;
			continue;
		}
		if (FEQ(xmod, 0.0f) && FEQ(ymod, 0.0f)) {
			if (cosphi > 0)
				c1 = box[inty][intx - 1];
			else
				c1 = box[inty][intx + 1];
			if (sinphi > 0)
				c2 = box[inty - 1][intx];
			else
				c2 = box[inty + 1][intx];
			if (c1 == '#' && c2 != '#')
				angle = - angle;
			else if (c1 != '#' && c2 == '#')
				angle = M_PI - angle;
			else if (c1 == '#' && c2 == '#')
				angle = M_PI + angle;
			else {
#ifdef DEBUG
				fprintf(stderr, "Ray lost\n");
#endif
				break;
			}
			continue;
		}
		printf("reached bottom");
	}

	return hit;
}

int main(int argc, char **argv)
{
	FILE *f;
	int i, j;
	int H, W, D;
	int cs = 1, res;
	char buf[32];
	double x0, y0, ang;

	f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "Cannot open %s\n", argv[1]);
		return 1;
	}
	fscanf(f, "%d", &i);
	fprintf(stderr, "%d cases\n", i);
	while (fscanf(f, "%d %d %d\n", &H, &W, &D) != EOF) {
		//fprintf(stderr, "%d %d %d", H, W, D);
		for (i = 0; i < 32; i++)
			for (j = 0; j < 32; j++)
				box[i][j] = ' ';
		for (i = 0; i < H; i++) {
			fgets(buf, 32, f);
			for (j = 0; j < W; j++) {
				box[i][j] = buf[j];
				if (buf[j] == 'X') {
					x0 = (float) j + 0.5f;
					y0 = (float) i + 0.5f;
				}
			}
		}
		//printbox(0,0);

		res = 0;
		for (ang = 0.0f; ang < (2.0f - EPSILON) * M_PI; ang += STEP)
			res += cast_ray(x0, y0, ang, D);

		//cast_ray(x0, y0, -1.0f * M_PI / 4.0f, D);

		printf("Case #%d: %d\n", cs, res);
		fprintf(stderr, "case %d\n", cs);
		cs++;
	}

	fclose(f);
	return 0;
}
