#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG(x) cout << ">>> " << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0;i<(a);++i)

#define INF (1<<29)
typedef long long ll;

struct Trie {
	Trie() {
		REP(i,26) children[i] = 0;
		end = false;
	}

	~Trie() {
		REP(i,26) delete children[i];
	}

	void add(const char *word) {
		if (*word) {
			int chI = *word - 'a';
			if (!children[chI]) {
				children[chI] = new Trie;
			}
			children[chI]->add(word+1);
		} else {
			end = true;
		}
	}

	Trie *children[26];

	bool end;
};

Trie tr;

vector<string> dict;

void loadDict() {
	ifstream fin("garbled_email_dictionary.txt");
	string line;
	getline(fin, line);
	while (!line.empty()) {
		dict.push_back(line);
		getline(fin, line);
	}
}

const int MAXL = 5000;

int T;
string msg;

int minErrors[5000][5];

struct Prog {
	Prog(Trie *t, int e, int l, int f):
		trie(t), errors(e), lastError(l), firstError(f) {}

	Trie *trie;
	int errors;
	int lastError;
	int firstError;
};

int main() {
	loadDict();

	for(const string &s : dict) {
		char word[20];
		strcpy(word, s.c_str());
		int len = s.size();
		reverse(word, word+len);
		tr.add(word);
	}

	scanf("%d\n", &T);
	REP(t,T) {
		getline(cin, msg);
		REP(i,5) minErrors[0][i] = 0;

		FOR(step,1,(int)msg.size()) {
			REP(i,5) minErrors[step][i] = MAXL;
			vector<Prog> pos;
			pos.push_back(Prog(&tr, 0, MAXL, -12));
			FORD(at,step-1,max(step-12,-1)) {
				vector<Prog> npos;
				for (auto &p : pos) {
					if (p.trie->end) {
						int corrEnd = min(step-p.firstError-1, 4);
						int minPrevCorrEnd = 4-min(p.lastError-at-1,4);
						/*
						DEBUG(step)
						DEBUG(at)
						DEBUG(corrEnd)
						DEBUG(minPrevCorrEnd)
						DEBUG("")
						*/
						REP(i,corrEnd+1) {
							minErrors[step][i] = min(minErrors[step][i], minErrors[at+1][max(minPrevCorrEnd,i-(step-at-1))]+p.errors);
						}
					}

					if (at < 0) continue;

					char ch = msg[at];

					Trie *corr = p.trie->children[ch-'a'];
					if (corr) npos.push_back(Prog(corr, p.errors, p.lastError, p.firstError));
					if (at <= p.lastError - 5) {
						for (char nch = 'a'; nch <= 'z'; ++nch) {
							Trie *child = p.trie->children[nch-'a'];
							if (nch != ch && child) {
								npos.push_back(Prog(child, p.errors+1, at, max(at, p.firstError)));
							}
						}
					}
				}
				pos.swap(npos);
			}
			/*
			REP(i,5) printf("%d ", minErrors[step][i]);
			printf("\n");
			*/
		}
		int best = MAXL;
		REP(i,5) {
			best = min(best, minErrors[msg.size()][i]);
		}
		printf("Case #%d: %d\n", t+1, best);
	}

	return 0;
}
