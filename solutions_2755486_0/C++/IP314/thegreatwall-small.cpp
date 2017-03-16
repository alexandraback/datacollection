#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

class thegreatwall_small
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

		class intervaltreewall // not a tree yet
		{
			private:
				int n, ioff, maxh;
				vector<int> tt;

				int minheightint(int bi, int ei) {
					int sol = maxh;
					for (int f = bi; f < ei; ++f) {
						sol = min(sol, tt.at(f));
					}
					return sol;
				}
				void raisetoint(int bi, int ei, int nht) {
					for (int f = bi; f < ei; ++f) {
						tt.at(f) = max(tt.at(f), nht);
					}
				}

			public:
				intervaltreewall(int minl, int maxl, int maxht, int initht) : n(maxl - minl), ioff(minl), maxh(maxht), tt(maxl - minl, initht) {}
				int minheight(int bi, int ei) {
					return minheightint(bi - ioff, ei - ioff);
				}
				void raiseto(int bi, int ei, int nht) {
					raisetoint(bi - ioff, ei - ioff, nht);
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
		thegreatwall_small task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
