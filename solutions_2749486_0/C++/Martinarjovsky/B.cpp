#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

ifstream fin ("B.in");
ofstream fout ("B.out");

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()

struct node {
	ii coord;
	string seq;
} ;

int main() {
	long long int T, c, i, step, X, Y;
	fin >> T;
	vector<vector<node> > DP;
	vector<node> a;
	node x;
	string res;
	bool flag;

	for (c = 1; c <= T; c++) {
		fin >> X >> Y;

		step = 0;
		x.seq = "";
		x.coord.first = 0;
		x.coord.second = 0;
		a.pb(x);
		DP.pb(a);

		res = "";
		if (X < 0) {
			for (i = 0; i < abs(X); i++) {
				res += "EW";
			}
		}
		else if (X > 0) {
			for (i = 0; i < abs(X); i++) {
				res += "WE";
			}
		}

		if (Y < 0) {
			for (i = 0; i < abs(Y); i++) {
				res+= "NS";
			}
		}
		else if (Y > 0) {
			for (i = 0; i < abs(Y); i++) {
				res+= "SN";
			}
		}

		fout << "Case #" << c <<": " << res << endl;
		continue;



		flag = false;
		while(true) {
			a.clear();

			for (i = 0; i < sz(DP[step]); i++) {
				x = DP[step][i];
				x.coord.first += step + 1;
				x.seq += "E";
				if (abs(x.coord.first) < 10000) a.pb(x);
				if (x.coord.first == X && x.coord.second == Y) {
					a.clear();
					DP.clear();
					fout << "Case #" << c <<": " << x.seq << endl;
					flag = true;
					break;
				}

//				cout << x.coord.first << ' ' << x.coord.second<<endl;

				x = DP[step][i];
				x.coord.first -= step + 1;
				x.seq += "W";
				if (abs(x.coord.first) < 10000) a.pb(x);
				if (x.coord.first == X && x.coord.second == Y) {
					a.clear();
					DP.clear();
					fout << "Case #" << c <<": " << x.seq << endl;
					flag = true;
					break;
				}

				x = DP[step][i];
				x.coord.second += step + 1;
				x.seq += "N";
				if (abs(x.coord.second) < 10000) a.pb(x);
				if (x.coord.first == X && x.coord.second == Y) {
					a.clear();
					DP.clear();
					fout << "Case #" << c <<": " << x.seq << endl;
					flag = true;
					break;
				}

				x = DP[step][i];
				x.coord.second -= step + 1;
				x.seq += "S";
				if (abs(x.coord.second) < 10000) a.pb(x);
				if (x.coord.first == X && x.coord.second == Y) {
					a.clear();
					DP.clear();
					fout << "Case #" << c <<": " << x.seq << endl;
					flag = true;
					break;
				}
			}

			if (flag) {
				break;
			}
			DP.pb(a);
			step++;
		}

	}

	return 0;
}
