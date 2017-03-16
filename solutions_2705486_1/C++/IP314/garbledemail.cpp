#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int alphasize = 26;

const int reqdist = 5;

class garbledemail
{
	private:
		static int minminus1(int a, int b, int addb) {
			if (b < 0) {
				return a;
			} else if (a < 0) {
				return b + addb;
			} else {
				return min(a, b + addb);
			}
		}

		class trienode {
			private:
				vector<trienode *> ptrs;
				bool endp;

			public:
				trienode() : ptrs(alphasize, NULL), endp(false) {}

				~trienode() {
					for (int l = 0; l < alphasize; ++l) {
						if (ptrs.at(l) != NULL) {
							delete ptrs.at(l);
						}
					}
				}

				void add(const string &as, int ai = 0) {
					if (ai == (int)as.size()) {
						endp = true;
					} else {
						int al = as.at(ai) - 'a';
						if (ptrs.at(al) == NULL) {
							ptrs.at(al) = new trienode();
						}
						ptrs.at(al)->add(as, ai + 1);
					}
				}

				int match(int mindist, int enddist, const string &mw, int mi = 0) const {
					if (mi == (int)mw.size()) {
						if (endp && (mindist <= enddist)) {
							return 0;
						} else {
							return -1;
						}
					} else {
						int nml = mw.at(mi) - 'a';
						int bsol = -1;
						if (ptrs.at(nml) != NULL) {
							bsol = minminus1(bsol, ptrs.at(nml)->match(mindist - 1, enddist, mw, mi + 1), 0);
						}
						if (mindist == 0) {
							for (int l = 0; l < alphasize; ++l) {
								if (ptrs.at(l) != NULL) {
									bsol = minminus1(bsol, ptrs.at(l)->match(reqdist - 1, enddist, mw, mi + 1), 1);
								}
							}
						}
						return bsol;
					}
				}
		};

		trienode *dict;
		unsigned int maxwlen;

		string gs;

	public:
		garbledemail() : dict(NULL), maxwlen(0) {}

		~garbledemail() {
			if (dict != NULL) {
				delete dict;
			}
		}

		void dictinput(string filepath) {
			if (dict != NULL) {
				delete dict;
			}
			dict = new trienode();
			maxwlen = 0;
			ifstream ifs(filepath.c_str());
			string ins;
			while (true) {
				ins = "";
				ifs >> ins;
				if (ins.size() > 0) {
					dict->add(ins);
					maxwlen = max(maxwlen, (unsigned int)ins.size());
				} else {
					break;
				}
			}
		}

		void input() {
			cin >> gs;
		}

		int solve() {
			vector<vector<int> > dp;
			dp.resize(gs.size() + 1, vector<int>(reqdist, -1));
			for (int f = 0; f < reqdist; ++f) {
				dp.at(0).at(f) = 0;
			}
			for (unsigned int f = 0; f < gs.size(); ++f) {
				for (unsigned int g = 0; g < reqdist; ++g) {
					for (unsigned int h = 0; h < reqdist; ++h) {
						for (unsigned int ml = 1; ml <= maxwlen; ++ml) {
							if ((f + ml <= gs.size()) && (dp.at(f).at(g) > -1)) {
								int tm = dict->match(g, h, gs.substr(f, ml));
								if (tm > -1) {
									dp.at(f + ml).at(h) = minminus1(dp.at(f + ml).at(h), dp.at(f).at(g) + tm, 0);
								}
							}
						}
					}
				}
			}
			int sol = -1;
			for (int f = 0; f < reqdist; ++f) {
				sol = minminus1(sol, dp.at(gs.size()).at(f), 0);
			}
			return sol;
		}
};

int main(void) {
	garbledemail task;
	task.dictinput("garbled_email_dictionary.txt");
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
