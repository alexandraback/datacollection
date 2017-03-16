#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <iostream>
#include <fstream>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
using namespace std;
typedef vector<int> vi;

vector<vi> clauses;

void addClause(vi v) {
	v.erase(remove(v.begin(), v.end(), 0), v.end());
	clauses.push_back(v);
}
void addClause(int x1) {
	vi v; v.push_back(x1);
	addClause(v);
}
void addClause(int x1, int x2) {
	vi v;
	v.push_back(x1);
	v.push_back(x2);
	addClause(v);
}
void addClause(int x1, int x2, int x3) {
	vi v;
	v.push_back(x1);
	v.push_back(x2);
	v.push_back(x3);
	addClause(v);
}
void addClause(int x1, int x2, int x3, int x4) {
	vi v;
	v.push_back(x1);
	v.push_back(x2);
	v.push_back(x3);
	v.push_back(x4);
	addClause(v);
}

void printCaluses(ostream &o) {
	int variables = 0;
	each(i, clauses) each(j, *i) variables = max(variables, abs(*j));
	o << "c (DIMACS format)" << endl;
	o << "p cnf " << variables << " " << clauses.size() << endl;
	rep(i, clauses.size()) {
		vi &clause = clauses[i];
		rep(j, clause.size()) o << clause[j] << " ";
		o << "0" << endl;
	}
}

void readVariables(istream &in, vector<bool> &v) {
	v.clear();
	char sat[6];
	in >> sat;
	if(strcmp(sat, "SAT") == 0) {
		v.push_back(true);
	}else if(strcmp(sat, "UNSAT") == 0) {
		v.push_back(false);
		return;
	}else {
		return;
	}
	int x;
	while(1) {
		if(!(in >> x)) {
			v.clear();
			return;
		}
		if(x == 0) break;
		if(abs(x) != v.size()) {
			v.clear();
			return;
		}
		v.push_back(x > 0);
	}
}

namespace sat {
int H, W, MaxD, M;
int Board, Empty, Propagate, Click, Reach, MineCount;

int packyx(int y, int x) { return y * W + x; }
int board(int y, int x) { return Board + packyx(y, x); }
int empty(int y, int x) { return Empty + packyx(y, x); }
int propagate(int y, int x, int d) { return Propagate + packyx(y, x) * (MaxD + 1) + d; }
int click(int y, int x) { return Click + packyx(y, x); }
int reach(int y, int x, int d) { return Reach + packyx(y, x) * (MaxD + 1) + d; }
int minecount(int yx, int n) { return MineCount + yx * (M + 1) + n; }

void makeClauses() {
	clauses.clear();

	MaxD = H + W - 2;
	Board = 1;
	Empty = Board + H * W;
	Propagate = Empty + H * W;
	Click = Propagate + H * W * (MaxD + 1);
	Reach = Click + H * W;
	MineCount = Reach + H * W * (MaxD + 1);

	//clickは1箇所だけ
	rep(y0, H) rep(x0, W) rep(y1, H) rep(x1, W)
		if(make_pair(y0, x0) < make_pair(y1, x1))
			addClause(-click(y0, x0), -click(y1, x1));

	//clickは非mine
	rep(y, H) rep(x, W)
		addClause(-click(y, x), -board(y, x));

	{	vector<int> clause;
		rep(y, H) rep(x, W) clause.push_back(click(y, x));
		addClause(clause);
	}

	//reachの構成(click)
	rep(y, H) rep(x, W)	//reach(y, x, 0) -> click(y, x)
		addClause(-reach(y, x, 0), click(y, x));

	//reachの構成(伝播)
	rep(y, H) rep(x, W) rer(d, 1, MaxD) {
		//reach(y, x, d) -> ~board(y, x) /\ Or_{dy,dx} (reach(y+dy, x+dx, d-1) /\ ~number(y+dy, x+dx))
		//~reach(y, x, d) \/ ~board(y, x)
		//~reach(y, x, d) \/ Or_{dy,dx} (reach(y+dy, x+dx, d-1) /\ empty(y+dy, x+dx))
		addClause(-reach(y, x, d), -board(y, x));
		vector<int> clause;
		clause.push_back(-reach(y, x, d));
		rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
			int yy = y + dy, xx = x + dx;
			if(yy<0||yy>=H||xx<0||xx>=W) continue;
			clause.push_back(propagate(yy, xx, d-1));
		}
		addClause(clause);
	}

	//reachのチェック
	rep(y, H) rep(x, W) {
		vector<int> clause;
		clause.push_back(board(y, x));
		rer(d, 0, MaxD)
			clause.push_back(reach(y, x, d));
		addClause(clause);
	}

	//propagateの構成
	rep(y, H) rep(x, W) rer(d, 0, MaxD) {
		addClause(-propagate(y, x, d), reach(y, x, d));
		addClause(-propagate(y, x, d), empty(y, x));
	}

	//emptyの構成
	rep(y, H) rep(x, W) {
		rer(dy, -1, 1) rer(dx, -1, 1) if(dy || dx) {
			int yy = y + dy, xx = x + dx;
			if(yy<0||yy>=H||xx<0||xx>=W) continue;
			addClause(-empty(y, x), -board(yy, xx));
		}
	}

	//minecountの構成
	addClause(minecount(packyx(0, 0), 0));
	rer(n, 1, M) addClause(-minecount(packyx(0, 0), n));
	rep(y, H) rep(x, W) {
		int yx = packyx(y, x);
		rer(n, 0, M) {
			//minecount(yx+1, n) <-> (minecount(yx, n-1) /\ board(y, x)) \/ (minecount(yx, n) /\ ~board(y, x))

			//  ~minecount(yx+1, n) \/ (minecount(yx, n-1) /\ board(y, x)) \/ (minecount(yx, n) /\ ~board(y, x))
			if(n > 0) {
				addClause(-minecount(yx+1, n), minecount(yx, n-1), minecount(yx, n));
				addClause(-minecount(yx+1, n), minecount(yx, n-1), -board(y, x));
			}else {
				addClause(-minecount(yx+1, n), minecount(yx, n));
				addClause(-minecount(yx+1, n), -board(y, x));
			}
			addClause(-minecount(yx+1, n), board(y, x), minecount(yx, n));
			//  minecount(yx+1, n) \/ ~minecount(yx, n-1) \/ ~board(y, x)
			//  minecount(yx+1, n) \/ ~minecount(yx, n) \/ board(y, x)
			if(n > 0)
				addClause(minecount(yx+1, n), -minecount(yx, n-1), -board(y, x));
			addClause(minecount(yx+1, n), -minecount(yx, n), board(y, x));
		}
	}
	addClause(minecount(H * W, M));
}

void showVariables(const vector<bool> &v) {
	rep(y, H) {
		rep(x, W)
			putchar(".*c?"[v[board(y, x)] + v[click(y, x)] * 2]);
		puts("");
	}
}
}

int solve(int testcase) {
	scanf("%d%d%d", &sat::H, &sat::W, &sat::M);

	sat::makeClauses();

	const char *filename = "C:/test/sagyo/gcj-qual-c.sat", *outname = "C:/test/sagyo/gcj-qual-c.out";
	ofstream fout(filename, ios_base::out);
	printCaluses(fout);
	fout.close();

	cerr << "Done!" << endl;

	char buf[256];
	sprintf(buf, "C:/test/program/minisat/core/minisat.exe %s %s > NUL", filename, outname);
	cerr << "solve SAT..." << endl;
	system(buf);
	cerr << "Done!" << endl;
	
	ifstream fin(outname);
	vector<bool> v;
	readVariables(fin, v);
	if(v.empty()) {
		cerr << "some error or indetermined" << endl;
		return -1;
	}
	fin.close();

	printf("Case #%d:\n", testcase+1);

	if(!v[0]) {
		puts("Impossible");
		return 2;
	}
	
	sat::showVariables(v);

	return 0;
}

int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		solve(ii);
	}
	return 0;
}
