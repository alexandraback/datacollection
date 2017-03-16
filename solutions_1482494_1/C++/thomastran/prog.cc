#include "macro.hh"

struct pr{
	int x;
	int y;
};

bool cmpf (pr A, pr B) {
	if (B.y == A.y)
		return (A.x < B.x);
	return (A.y < B.y);
}

int solve(ostream& out, int caseNum, vector<pr> &v, int N) {
	out << "Case #" << caseNum << ": ";
	sort(all(v), cmpf);
	int r = 0;
	int curr = 0;
	int res = 0;
	vector<bool> in(N,1);
	while (curr < N) {
		while (r >= v[curr].y) {
			r += in[curr]? 2 : 1;
			in[curr] = 0;
			curr++;
			res++;
			if (curr >=N)
				return res; 
		}
		bool ok = 0;
		for (int i = N -1; i >= curr; i--) { 
			if (in[i] && v[i].x <= r) {
				ok = 1;
				in[i] = 0;
				r++;
				res++;
				break;
			}
		}
		if (!ok)
			return -1;
	}
}

int main () {
	ifstream in("input");
	ofstream out("output");
	int T;
	in >> T; 
	rep(i,T) {
		int N;
		in >> N;
		vector<pr> v(N);
		rep(j,N)
			in >> v[j].x >> v[j].y;
		int res=	solve(out, i+1, v, N);
		if (res == -1)
			out << "Too Bad" << endl;	
		else
			out << res << endl;
	}
}
