#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <vector>

#define VERIFY 0

typedef unsigned u;


static const char MINE='*'; 

static char field[50*50];
static u R,C,M,UM;

static inline bool valid(int x, int y)
{
	return (u)x<C && (u)y < R;
}
static inline u idx(u x, u y)
{
	return x+y*C;
}
static inline char& at(int x,int y)
{
	return field[idx(x,y)];
}
static inline char get(int x, int y)
{
	return valid(x,y) ? at(x,y) : 0;
}
static inline bool ismine(int x,int y)
{
	return get(x,y) == MINE;
}

static const int xs[] = {-1, -1, -1, 0, 1, 1,  1,  0};
static const int ys[] = {-1,  0,  1, 1, 1, 0, -1, -1};

static inline void calc(int x,int y)
{
	char& here = at(x,y);
	if (here != MINE) {
		int mines = 0;
		for (int dir = 0;dir<8;dir++) {
			mines += ismine(x+xs[dir], y+ys[dir]);
		}
		here = '0'+mines;
	}
}

static inline void placemine(u x,u y, bool place)
{
	char& here = at(x,y);
	int delta = place ? 1 : -1;
	if (place) {
		//assert here != MINE
		here = MINE;
	} else {
		here = '0';
		calc(x,y);
	}
	for (int dir = 0;dir<8;dir++) {
		int nx = x+xs[dir];
		int ny = y+ys[dir];
		if (valid(nx,ny)) {
			char& dest = at(nx,ny);
			if (dest != MINE)
				dest += delta;
		}
	}
}

static void dump()
{
	for (u r=0;r<R;r++)
	{
		printf("%.*s\n", C, &at(0, r));
	}
}

struct XY
{
	u x,y;
};

static bool isgood()
{
	int sx = -1, sy;
	int nmx, nmy;
	int nNonMine=0;
	for (u x=0;x<C;x++) for (u y=0;y<R;y++) {
		char& c = at(x,y);
		if (c == '0') {
			sx = x;
			sy = y;
			goto founds;
		}
		else if (c != MINE) {
			nNonMine++;
			nmx = x;
			nmy = y;
		}
	}
	if (sx == -1) {
		if (nNonMine == 1) {
			at(nmx, nmy) = 'c';
			return true;
		}
		return false;
	}

founds:
	// Floodfill
	char state[50*50];
	memset(state, 0, sizeof state);

	std::vector<XY> todo;
	todo.push_back(XY({sx, sy}));
	while (!todo.empty())
	{
		XY c = todo.back();
		todo.pop_back();
		if (state[idx(c.x, c.y)]) continue;
		state[idx(c.x, c.y)] = 1;
		if (at(c.x, c.y) == '0')
		{
			for (int dir = 0;dir<8;dir++) {
				int nx = c.x+xs[dir];
				int ny = c.y+ys[dir];
				if (valid(nx,ny)) {
					todo.push_back(XY({nx, ny}));
				}
			}
		}
	}

	// Check for unopened squares:
	for (u x=0;x<C;x++) for (u y=0;y<R;y++) {
		if (at(x,y) == MINE) continue;
		if (!state[idx(x,y)])
			return false;
	}
	at(sx, sy) = 'c';

	return true;
}


static bool recur(int x, int y, u toplace, u rem)
{
	if (!rem) {
		if (isgood()) {
			return true;
		}
		return false;
	}

	u nextx = x+1;
	u nexty = y;
	if (nextx == C) {
		nexty++;
		nextx = 0;
	}
	if (toplace) {
		placemine(x,y, true);
		bool found = recur(nextx, nexty, toplace-1, rem-1);
		if (found) return true;
		placemine(x,y, false);
	}
	if (toplace < rem) {
		bool found = recur(nextx, nexty, toplace, rem-1);
		if (found) return true;
	}

	return false;
}

static bool solve1()
{
	field[0] = 'c';
	for (int i=1;i<R;i++)
	{
		field[i] = i < UM ? '.' : '*';
	}
	return true;
}

static bool solveUM1()
{
	field[0] = 'c';
	for (int i=1;i<R*C;i++)
	{
		field[i] = '*';
	}
	return true;
}

static inline void setrow(u r, u mines)
{
	for (u x=0;x<C;x++)
		at(x, r) = x<mines ? MINE : '0';
}

static inline void recalc()
{
	for (u x=0;x<C;x++) for (u y=0;y<R;y++) {
		calc(x,y);
	}
}

static inline bool solveOther()
{
	for (u r0 = 0; r0<C; r0++) for (u r1 = 0; r1<C; r1++) {
		if (r0+r1 > M) break; // r1 will only grow
		u r2 = (M - r0 - r1) % C;
		u f = (M - r0 - r1 - r2) / C; // full rows

		u remainingrows = R - f;

		if (remainingrows >= 3)
			setrow(f+2, r2);
		else if (r2 != 0) continue;
		if (remainingrows >= 2)
			setrow(f+1, r1);
		else if (r1 != 0) continue;
		if (remainingrows >= 1)
			setrow(f, r0);
		else if (r0 != 0) continue;
		for (u r=0;r<f;r++)
			setrow(r, C);
		for (u r=f+3;r<R;r++)
			setrow(r, 0);

		recalc();
		if (isgood()) {
			for (u x=0;x<C;x++) for (u y=0;y<R;y++) {
				char& c = at(x,y);
				if (c != MINE && c != 'c')
					c = '.';
			}
			return true;
		}
	}
	return false;
#if 0
	if (UM >= 2*C && UM%C != 1)
	{
		field[0] = 'c';
		for (int i=0;i<R*C; i++)
			field[i] = i<UM ? '.' : '*';
		return true;
	}

	return false;
#endif
}

extern "C"
void solve(int r, int c, int m)
{
	R = r;
	C = c;
	M = m;
	UM = R*C-M;
	memset(field, '0', sizeof field);
	bool swapped = false;
	swapped = C>R;
	if (swapped)
	{
		std::swap(R,C);
	}
	// Now C <= R
	bool solved = false;
	if (C == 1) {
		solved = solve1();
	}
	else if (UM == 1) {
		solved = solveUM1();
	}
	else {
		solved = solveOther();
	}

	if (solved && swapped)
	{
		char backup[50*50];
		memcpy(backup, field, sizeof backup);
		std::swap(R,C);
		for (u x=0;x<C;x++) for (u y=0;y<R;y++) {
			at(x,y) = backup[y+x*R];
		}
	}
	if (solved)
		dump();
	else
		printf("Impossible\n");

#if VERIFY
	if (R*C<=30) {
		memset(field, '0', sizeof field);
		bool checksolved = recur(0, 0, M, R*C);
		if (checksolved != solved) {
			if (!checksolved)
				printf("Aiee: solution not found in bruteforce!\n");
			else
			{
				printf("Aiee: you did not find this solution:\n");
				dump();
			}
		}
	}
#endif
	fflush(stdout);
}
