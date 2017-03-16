#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

struct bod_t
{
	int r, s;
	bod_t(int r = 0, int s = 0)
	{
		this->r = r;
		this->s = s;
	}
};

const int dr[4] = { -1, 1, 0, 0 };
const int ds[4] = { 0, 0, -1, 1 };

bool mrizka[20][20];
int naposledy_navstiveno[20][20];
int age;

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int R, S, K;
		scanf("%d%d%d", &R, &S, &K);
		int RS = R*S;
		int vysledek = RS;
		for (int i = 0; i < (1<<RS); i++) {
			int pocet_kamenu = 0;
			for (int r = 0; r < R; r++) {
				for (int s = 0; s < S; s++) {
					bool je_kamen = i & (1 << (r*S + s));
					mrizka[r][s] = je_kamen;
					if (je_kamen) {
						pocet_kamenu++;
					}
				}
			}
			int neuzavrenych_kamenu = 0;
			queue<bod_t> fronta;
			age++;
			for (int r = 0; r < R; r++) {
				for (int s = 0; s < S; s++) {
					if (!mrizka[r][s] && (r == 0 || r == R-1 || s == 0 || s == S-1)) {
						fronta.push(bod_t(r, s));
						neuzavrenych_kamenu++;
						naposledy_navstiveno[r][s] = age;
					}
				}
			}
			while (!fronta.empty()) {
				bod_t bod = fronta.front();
				fronta.pop();
				for (int j = 0; j < 4; j++) {
					bod_t soused = bod_t(bod.r + dr[j], bod.s + ds[j]);
					if (soused.r >= 0 && soused.r < R && soused.s >= 0 && soused.s < S
						&& !mrizka[soused.r][soused.s]
						&& naposledy_navstiveno[soused.r][soused.s] != age
					) {
						fronta.push(soused);
						neuzavrenych_kamenu++;
						naposledy_navstiveno[soused.r][soused.s] = age;
					}
				}
			}
			int uzavrenych_kamenu = R*S - neuzavrenych_kamenu;
			if (uzavrenych_kamenu >= K) {
				vysledek = min(vysledek, pocet_kamenu);
			}
		}
		printf("Case #%d: %d\n", t, vysledek);
	}
	return 0;
}
