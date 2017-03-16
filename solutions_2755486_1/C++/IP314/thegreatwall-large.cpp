#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

class thegreatwall_large
{
	private:
		class tribeattackdesc
		{
			private:
				int d;
				int n;
				int w, e;
				int s;
				int deltad;
				int deltap;
				int deltas;

			public:
				tribeattackdesc(int d_, int n_, int w_, int e_, int s_, int deltad_, int deltap_, int deltas_) : d(d_), n(n_), w(w_), e(e_), s(s_), deltad(deltad_), deltap(deltap_), deltas(deltas_) {}
				void applydelta() {
					d += deltad;
					w += deltap;
					e += deltap;
					s += deltas;
					--n;
				}
				bool isactive() const {
					return (n > 0);
				}
				int getd() const {
					return d;
				}
				int getw() const {
					return w;
				}
				int gete() const {
					return e;
				}
				int gets() const {
					return s;
				}
				bool operator<(const tribeattackdesc &tad2) const {
					return (d > tad2.d);
				}
		};

		class intervaltreewall
		{
			private:
				static int compsize(int minsize) {
					int i;
					for (i = 1; i < minsize; i *= 2);
					return i;
				}

				int n, ioff, maxh;
				int ttsz;
				vector<pair<int, int> > tt;

				void applyraise(int p, int val) {
					tt.at(p).first = max(tt.at(p).first, val);
					tt.at(p).second = max(tt.at(p).second, val);
				}
				void propagate(int p) {
					applyraise(2 * p, tt.at(p).second);
					applyraise(2 * p + 1, tt.at(p).second);
				}
				void update(int p) {
					tt.at(p).first = min(tt.at(2 * p).first, tt.at(2 * p + 1).first);
				}
				int minheightrec(int bi, int ei, int b, int e, int p) {
					if (bi <= b && e <= ei) {
						return tt.at(p).first;
					}
					if (e <= bi || ei <= b) {
						return maxh;
					}
					propagate(p);
					return min(minheightrec(bi, ei, b, b + (e - b) / 2, 2 * p), minheightrec(bi, ei, b + (e - b) / 2, e, 2 * p + 1));
				}
				void raisetorec(int bi, int ei, int nht, int b, int e, int p) {
					if (bi <= b && e <= ei) {
						applyraise(p, nht);
						return;
					}
					if (e <= bi || ei <= b) {
						return;
					}
					propagate(p);
					raisetorec(bi, ei, nht, b, b + (e - b) / 2, 2 * p);
					raisetorec(bi, ei, nht, b + (e - b) / 2, e, 2 * p + 1);
					update(p);
				}

			public:
				intervaltreewall(int minl, int maxl, int maxht, int initht) : n(maxl - minl), ioff(minl), maxh(maxht), ttsz(compsize(maxl - minl)), tt(2 * ttsz, make_pair(initht, initht)) {}
				int minheight(int bi, int ei) {
					return minheightrec(bi - ioff, ei - ioff, 0, ttsz, 1);
				}
				void raiseto(int bi, int ei, int nht) {
					raisetorec(bi - ioff, ei - ioff, nht, 0, ttsz, 1);
				}
		};

		int n;
		priority_queue<tribeattackdesc> attacks;
		int minw, maxe, maxh;

	public:
		void input() {
			cin >> n;
			minw = inf;
			maxe = -inf;
			maxh = 0;
			int di, ni, wi, ei, si, deltadi, deltapi, deltasi;
			for (int f = 0; f < n; ++f) {
				cin >> di >> ni >> wi >> ei >> si >> deltadi >> deltapi >> deltasi;
				attacks.push(tribeattackdesc(di, ni, wi, ei, si, deltadi, deltapi, deltasi));
				minw = min(minw, min(wi, wi + (ni - 1) * deltapi));
				maxe = max(maxe, max(ei, ei + (ni - 1) * deltapi));
				maxh = max(maxh, max(si, si + (ni - 1) * deltasi));
			}
		}

		int solve() {
			int sol = 0;
			intervaltreewall wall(minw, maxe, maxh, 0);
			while (!(attacks.empty())) {
				vector<tribeattackdesc> catks;
				catks.push_back(attacks.top());
				attacks.pop();
				while (!(attacks.empty()) && (catks.front().getd() == attacks.top().getd())) {
					catks.push_back(attacks.top());
					attacks.pop();
				}
				for (vector<tribeattackdesc>::iterator atk = catks.begin(); atk < catks.end(); ++atk) {
					if (wall.minheight(atk->getw(), atk->gete()) < atk->gets()) {
						++sol;
					}
				}
				for (vector<tribeattackdesc>::iterator atk = catks.begin(); atk < catks.end(); ++atk) {
					wall.raiseto(atk->getw(), atk->gete(), atk->gets());
					atk->applydelta();
					if (atk->isactive()) {
						attacks.push(*atk);
					}
				}
			}
			return sol;
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		thegreatwall_large task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
