#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>

class pair {
public:
	int gcd(int a, int b) {
		a = a < 0 ? -a : a;
		b = b < 0 ? -b : b;

		if (a == 0)
			return b;

		while (b != 0) {
			(a > b) ? a -= b : b -= a;
		}

		return a;
	}

	int x;
	int y;

	int d;
	bool corner;

	pair(int a, int b, int d, bool c):x(a),y(b),d(d),corner(c) {
		int div = gcd(x,y);
		if (div != 0) {
			x /= div;
			y /= div;
		}
	}

	bool operator<(const pair& p) {
		return (x == p.x) ? (y == p.y) ? d < p.d : y < p.y : x < p.x;
	}

	bool operator==(const pair& p) {
		return x == p.x && y == p.y;
	}
};

void read(std::ifstream& in, int& h, int& w, int& d, int& x, int& y) {
	in >> h >> w >> d;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char c;
			in >> c;

			if (c == 'X') {
				x = i;
				y = j;
			}
		}
	}
}

void prepare(int& h, int& w, int& d, int& x1, int& x2, int& y1, int& y2) {
	h = (h-2) * 2;
	w = (w-2) * 2;
	d *= 2;
	x1 = 2 * x1 - 1;
	x2 = h - x1;
	y1 = 2 * y1 - 1;
	y2 = w - y1;
}

void get_candidates(std::vector<pair>& candidate, const int h, const int w, const int d, const int x1, const int x2, const int y1, const int y2) {
	int d_sqrd = d*d;

	int num_a = d/h + 3;
	int num_b = d/w + 3;

	num_a -= num_a%2;
	num_b -= num_b%2;

	int a = -(num_a) * h;
	bool bool_a = (num_a)%2 == 1;

	while (a <= (num_a) * h) {
		int a_sqrd = a*a;
		
		int b = -(num_b) * w;
		bool bool_b = (num_b)%2 == 1;

		while (b <= (num_b) * w) {
			int dist_sqrd = a_sqrd + b*b;
			if (dist_sqrd <= d_sqrd) {
				candidate.push_back(pair(a,b,dist_sqrd,false));
			}

			b += 2* (bool_b ? y1 : y2);
			bool_b = !bool_b;
		}

		a += 2 * (bool_a ? x1 : x2);
		bool_a = !bool_a;
	}
}

void get_corners(std::vector<pair>& candidate, const int h, const int w, const int d, const int x1, const int x2, const int y1, const int y2) {
	int d_sqrd = d*d;

	int num_a = d/h + 1;
	int num_b = d/w + 1;

	int a = x2 - (num_a) * h;
	while (a <= -x1 + (num_a) * h) {
		int a_sqrd = a*a;
		
		int b = y2 -(num_b) * w;
		while (b <= -y1 + (num_b) * w) {
			int dist_sqrd = a_sqrd + b*b;
			if (dist_sqrd <= d_sqrd) {
				candidate.push_back(pair(a,b,dist_sqrd,true));
			}
			b += w;
		}
		a += h;
	}
}

int count_candidates(std::vector<pair>& candidate, const int d) {
	int count = 0;

	int d_half_sqrd = d*d/4;

	if (candidate.size() > 1) {
		std::sort(candidate.begin(),candidate.end());
		if (!candidate[0].corner || candidate[0].d <= d_half_sqrd) {
			++count;
		}
		for (unsigned int i = 1; i < candidate.size(); ++i) {	
			if (!(candidate[i-1] == candidate[i])) {
				if (!candidate[i].corner || candidate[i].d <= d_half_sqrd) {
					++count;
				}
			}
		}
		--count;
	}

	return count;
}

void solve(std::string infile, std::string outfile) {
	std::ifstream in(infile);
	std::ofstream out(outfile);

	int cnt; in >> cnt;
	for (int c = 1; c <= cnt; ++c) {
		int h, w, d, x1, x2, y1, y2;
		read(in,h,w,d,x1,y1);
		prepare(h,w,d,x1,x2,y1,y2);

		std::vector<pair> candidate;
		get_candidates(candidate,h,w,d,x1,x2,y1,y2);
		get_corners(candidate,h,w,d,x1,x2,y1,y2);

		out << "Case #" << c << ": " << count_candidates(candidate,d) << std::endl;
	}

	out.close();
	in.close();
}

int main() {
	solve("small5.in","small5.out");

	return 0;
}