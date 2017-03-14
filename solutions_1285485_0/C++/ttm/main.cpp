#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define EPSILON (0.00000001)
#define thatVal (3)

class Double {
public:
	double value;
	Double(double d = 0)
		: value(d) { }
	Double(int d)
		: value(d) { }
	bool operator==(const Double &other) const {
		return abs(value - other.value) < EPSILON;
	}
	bool operator<(const Double &other) const {
		return value < other.value;
	}
	bool operator<=(const Double &other) const {
		return value <= other.value;
	}
	bool operator>(const Double &other) const {
		return value > other.value;
	}
	bool operator>=(const Double &other) const {
		return value >= other.value;
	}
	Double operator+(const Double &other) const {
		return Double(value + other.value);
	}
	Double operator*(const Double &other) const {
		return Double(value * other.value);
	}
	Double operator-(const Double &other) const {
		return Double(value - other.value);
	}
	Double operator/(const Double &other) const {
		return Double(value / other.value);
	}
};

Double halfpythag(Double dx, Double dy) {
	return dx.value * dx.value + dy.value * dy.value;
}

int main(int argc, char *argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int cases;
	cin >> cases;
	for (int cas = 1; cas <= cases; ++cas) {
		int h, w, d;
		cin >> h >> w >> d;
		char c;
		int minx = 100, maxx = 0, miny = 100, maxy = 0;
		Double mx, my;
		for (int x = 0; x < h; ++x) {
			for (int y = 0; y < w; ++y) {
				cin >> c;
				if (c == '#') {
					if (x < minx)
						minx = x;
					else if (x > maxx)
						maxx = x;
					if (y < miny)
						miny = y;
					else if (y > maxy)
						maxy = y;
				}
				else if (c == 'X') {
					mx = x + 0.5;
					my = y + 0.5;
				}
			}
		}
		minx++;
		miny++;
		mx = mx - minx;
		my = my - miny;
		set<Double> left, right;
		bool up = false, down = false;
		int width = maxx - minx, height = maxy - miny;
		int hboxrad = d / width + thatVal, vboxrad = d / height + thatVal;
		for (int hbox = -hboxrad; hbox <= hboxrad; ++hbox) {
			for (int vbox = -vboxrad; vbox < vboxrad; ++vbox) {
				Double hloc, vloc;
				hloc = Double(hbox * width);
				vloc = Double(vbox * height);
				if (halfpythag(hloc - mx, vloc - my) <= d * d / 4.0) {
					//cout << "#{" << hbox << ", " << vbox << "}" << endl;
					if (hloc < mx) {
						left.insert((vloc - my) / (hloc - mx));
					}
					else {
						right.insert((vloc - my) / (hloc - mx));
					}
				}
				if (hbox == 0 && vbox == 0)
					continue;
				if (hbox % 2 == 0) {
					hloc = Double(hbox * width) + mx;
				}
				else {
					hloc = Double((hbox + 1) * width) - mx;
				}
				if (vbox % 2 == 0) {
					vloc = Double(vbox * height) + my; 
				}
				else {
					vloc = Double((vbox + 1) * height) - my;
				}
				if (halfpythag(hloc - mx, vloc - my) <= d * d) {
					//cout << " {" << hbox << ", " << vbox << "}" << endl;
					if (hbox == 0) {
						if (vbox > 0)
							up = true;
						else
							down = true;
					}
					else if (hbox < 0) {
						left.insert((vloc - my) / (hloc - mx));
					}
					else {
						right.insert((vloc - my) / (hloc - mx));
					}
				}
			}
		}

		cout << "Case #" << cas << ": " << (left.size() + right.size() + (up ? 1 : 0) + (down ? 1 : 0)) << endl;
	}
	return 0;
}