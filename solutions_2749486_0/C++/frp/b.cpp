#include <iostream>
#include <vector>

using namespace std;
int sx, sy, step;

void step_east() {
	cout << "E";
	sx += step;
	step++;
}

void step_west() {
	cout << "W";
	sx -= step;
	step++;
}

void step_north() {
	cout << "N";
	sy += step;
	step++;
}

void step_south() {
	cout << "S";
	sy -= step;
	step++;
}

void test(int num) {
	cout << "Case #" << num << ": ";
	int x, y;
	cin >> x >> y;
	step = 1;
	sx = 0; sy = 0;
	bool overstepped = false;
	while(x != sx) {
		if (!overstepped)
			if (sx > x) {
				step_west();
				if(sx < x) overstepped = true;
			}
			else {
				step_east();
				if(sx > x) overstepped = true;
			}
		else {
			if (sx > x) {
				step_east();
				step_west();
			}
			else {
				step_west();
				step_east();
			}
		}
	}
	overstepped = false;
	while(y != sy) {
		if (!overstepped)
			if (sy > y) {
				step_south();
				if(sy < y) overstepped = true;
			}
			else {
				step_north();
				if(sy > y) overstepped = true;
			}
		else {
			if (sy > y) {
				step_north();
				step_south();
			}
			else {
				step_south();
				step_north();
			}
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		test(i+1);
}
