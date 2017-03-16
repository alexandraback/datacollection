#include <stdio.h>
#include <vector>
#include <algorithm>

#define INFILE		"wall.in"
#define OUTFILE		"wall.out"

struct Tribe {
	int n;
	int d, deltaD;
	int west, east, deltaP;
	int s, deltaS;
};

struct Attack {
	int day;
	int west, east, strength;

	Attack(int d, int w, int e, int s) {
		day = d;
		west = w;
		east = e;
		strength = s;
	}
};

bool AttackCmmp(const Attack &lhs, const Attack &rhs) {
	return lhs.day < rhs.day;
}

int n;
Tribe tribes[1024];
std::vector<Attack> attacks;

int wall[2048];

bool success(int w, int e, int s) {
	for (int i=w; i<=e; i++)
		if (wall[i] < s)
			return true;
	return false;
}

void update(int w, int e, int s) {
	for (int i=w; i<=e; i++)
		if (wall[i] < s)
			wall[i] = s;
}

void solve(FILE *fin, FILE *fout) {
	int tests;
	fscanf(fin, "%d", &tests);
	for (int t=0; t<tests; t++) {
		fscanf(fin, "%d", &n);
		attacks.clear();
		for (int i=0; i<n; i++) {
			fscanf(fin, "%d %d %d %d %d %d %d %d\n", &tribes[i].d, &tribes[i].n, &tribes[i].west, &tribes[i].east,
				&tribes[i].s, &tribes[i].deltaD, &tribes[i].deltaP, &tribes[i].deltaS);
			int d = tribes[i].d;
			int w = tribes[i].west;
			int e = tribes[i].east;
			int s = tribes[i].s;
			for (int j=0; j<tribes[i].n; j++) {
				attacks.push_back(Attack(d, w+1000, e-1+1000, s));
				d += tribes[i].deltaD;
				w += tribes[i].deltaP;
				e += tribes[i].deltaP;
				s += tribes[i].deltaS;
			}
		}

		memset(wall, 0, sizeof(wall));
		std::sort(attacks.begin(), attacks.end(), AttackCmmp);

		int ans = 0;

		int numA = int(attacks.size());
		for (int i=0; i<numA; i++) {
			int j = i + 1;
			while (j<numA && attacks[j].day == attacks[i].day) j++;

			for (int k=i; k<j; k++)
				if (success(attacks[k].west, attacks[k].east, attacks[k].strength))
					ans ++;

			for (int k=i; k<j; k++)
				update(attacks[k].west, attacks[k].east, attacks[k].strength);

			i = j - 1;
		}

		fprintf(fout, "Case #%d: %d\n", t+1, ans);
	}

}

int main() {
	FILE *fin = fopen(INFILE, "r");
	FILE *fout = fopen(OUTFILE, "w");
	if (!fin) {
		printf("Cannot open input file!\n");
		return 0;
	}
	if (!fout) {
		printf("Cannot open output file!\n");
		return 0;
	}

	solve(fin, fout);

	fclose(fin);
	fclose(fout);
	return 0;
}
