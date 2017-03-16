#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;


long long gcd(long long a, long long b) {
	if (a > b) return gcd(b, a);
	else if (a == 0) return b;
	else return gcd(b % a, a);
}


long long myabs(long long a) {
    if ( a < 0) return -a;
    else return a;
} 

class Rat
{
public:
	long long num, den;
	Rat(long long a, long long b): num(a), den(b) { Norm(); }
	Rat() {num = 0; den = 1;}
	void Norm() {
		long long d = gcd(myabs(num), myabs(den));
		num /= d;
		den /= d;
		if (den < 0) {
			den = -den;
			num = -num;
		}
	}
	bool isint() {
		return den == 1;
	}

	Rat ceil() {
		Rat ans  (num + den - num % den, den);
		return ans;
	}

	Rat floor() {
		Rat ans (num - num % den, den);
		if ( ans.num == num) ans.num--;
		return ans;
	}
	long double dbl()
	{
		return num / ((long double)den);
	}

};

Rat operator +(const Rat &a, const Rat &b) {
	return Rat(a.num*b.den+a.den*b.num, a.den*b.den);
}

Rat operator -(const Rat &a, const Rat &b) {
	return Rat(a.num*b.den-a.den*b.num, a.den*b.den);
}

Rat operator *(const Rat &a, const Rat &b) {
	return Rat(a.num*b.num, a.den*b.den);
}

Rat operator /(const Rat &a, const Rat &b) {
	return Rat(a.num*b.den, a.den*b.num);
}


bool operator <(const Rat &a, int x) {
	return a.num < x*a.den;
}

bool operator >(const Rat &a, int x) {
	return a.num > x*a.den;
}

bool operator >(int x, const Rat &a) {
	return a.num < x*a.den;
}

bool operator <(int x, const Rat &a) {
	return a.num > x*a.den;
}

bool operator <(const Rat &a, const Rat &b) {
	return a.num*b.den < b.num*a.den;
}

bool operator >(const Rat &a, const Rat &b) {
	return a.num*b.den > b.num*a.den;
}

Rat operator -(const Rat &a) {
	return Rat(-a.num, a.den);
}


bool operator == (const Rat a, const Rat b) {
	return a.den == b.den && a.num == b.num;
}


class Point
{
public: 
	Rat x, y;
	Point() {};

	long double len() {
		return sqrt(x.dbl() * x.dbl() + y.dbl()*y.dbl());
	}
	Point(Rat a, Rat b) : x(a), y(b) { }
};

Point operator + (const Point &a, const Point &b) {
	return Point(a.x+b.x, a.y+b.y);
}

Point operator - (const Point &a, const Point &b) {
	return Point(a.x-b.x, a.y-b.y);
}


Point operator *(const Rat &a, const Point &b) {
	return Point(b.x*a, b.y*a);
}

Point operator *(const Point &b, const Rat &a) {
	return Point(b.x*a, b.y*a);
}

char map[50][50];
int n, m, d;

Point beg;
int bi, bj;


class Line {
public:
    Line() {dist = 0.0;}
	Point p, v;
	long double dist;
    int id;
	Line(Point pos, Point vec, int idd) : p(pos), v(vec), dist(0.0), id(idd) {}
};



void Solve()
{
	cin >> n >> m >> d;
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'X') {
				beg = Point(Rat(2*i+1, 2), Rat(2*j+1, 2));
				bi = i;
				bj = j;
			}
		}

	vector <Line> lines;

	int shft = 0;
    int cur = 0;
	for (i = -d; i <= d; i++) {
		for (j = -d + shft; j <= d; j++) {
			if ((i == 0 && j == 0) || gcd(myabs(i), myabs(j)) != 1 || i*i+j*j > d*d) continue;
			lines.push_back(Line(beg, Point(Rat(i, 1), Rat(j,1)), ++cur));
		}
		shft = 0;
	}

	int ans = 0;
    int id = 0;
	while (lines.size() > 0) {
		int q = 0;
		for (int z = 0; z < (int)lines.size(); z++) {
            id++;
            //if (id ==  121) {
            //    id =  121;
            //}
			Line &ln = lines[z];
			Point &p = ln.p;
			Point &v = ln.v;
	    
//            cerr << "p (" << p.x.dbl() << ", " << p.y.dbl() << ") v(" << v.x.dbl() << ", " << v.y.dbl() << ") " << ln.id << " " << id << "\n";
			Rat timex, timey;
	    
			if (v.x > 0) {
				timex = (p.x.ceil() - p.x) / v.x;
			} else if (v.x < 0) {
				timex = (p.x.floor() - p.x) / v.x;
			} else timex = Rat(10000, 1);
	    
			if (v.y > 0) {
				timey = (p.y.ceil() - p.y) / v.y;
			} else if (v.y < 0) {
				timey = (p.y.floor() - p.y) / v.y;
			} else timey = Rat(10000, 1);
			if (timex > timey) timex = timey;
	    
            Point diff = v * timex;
	        Point vv = beg - p;
	        if (vv.x*v.y == v.x*vv.y && vv.x*v.x+vv.y*v.y > 0 && vv.len() < diff.len()) {
	        	long double tmp = ln.dist + vv.len();
                if (tmp < d + 1e-9) {
                    //cerr << "*\n";
                    ans++;
                    ln.dist += 100000.0;
                }
	        }
            
            p = p + diff;
			ln.dist += diff.len();
	    
			int i, j;
			i = (int) (p.x.num / p.x.den);
			j = (int) (p.y.num / p.y.den);
			int dx = 0, dy = 0;
	    
	    
	        // reflect;
			if (p.x.isint() && p.y.isint()) {
				if (v.x > 0) {
					i--; dx = 1;
				} else if (v.x < 0 ) {
					dx = -1;
				}
				if (v.y > 0) {
					j--; dy = 1;
				} else if (v.y < 0 ) {
					dy = -1;
				}
				if (map[i][j] == '#') 
                    cerr << "Botva! 1\n";
				if (map[i+dx][j+dy] == '#' && map[i][j+dy] == '#' ) {
					v.y = -v.y;
				}
				if (map[i+dx][j+dy] == '#' && map[i+dx][j] == '#' ) {
					v.x = -v.x;
				}
				if (map[i+dx][j+dy] == '#' && map[i][j+dy] != '#' && map[i+dx][j] != '#') {
					ln.dist += 100000.0;
				}
			} else if (p.x.isint()) {
			    if (v.x > 0) {
					i--; dx = 1;
				} else if (v.x < 0 ) {
					dx = -1;
				}

				if (map[i+dx][j] == '#')
					v.x = -v.x;

                if (map[i][j] == '#') 
                    cerr << "Botva! 1x\n";

			} else if (p.y.isint()) {
				if (v.y > 0) {
					j--; dy = 1;
				} else if (v.y < 0 ) {
					dy = -1;
				}

				if (map[i][j+dy] == '#')
					v.y = -v.y;

                if (map[i][j] == '#') 
                    cerr << "Botva! 1y\n";

			} else {
				cerr << "Botva! 2\n";
			}

           // cerr << "p (" << p.x.dbl() << ", " << p.y.dbl() << ") v(" << v.x.dbl() << ", " << v.y.dbl() << ") new\n";

			lines[q] = ln;
			if (ln.dist < d + 1e-9) {
				q++;
			}
          //  else cerr << "killed\n";
		}    
        lines.resize(q);
	    
	}


	cout << ans << "\n";

}

int main()
{
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cerr << tt << "\n";
		cout << "Case #" << tt << ": ";
		Solve(); 
	}
	return 0;
}
