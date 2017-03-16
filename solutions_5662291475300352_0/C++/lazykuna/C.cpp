#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

ifstream in;
ofstream out;

// only for simple 1

struct hiker {
	unsigned long long pos;
	double speed;	// revolution time
};

hiker d[10];
int cnt = 0;

void clear() {
	memset(d, 0, sizeof(d));
}

int process() {
	if (cnt == 1)
		return 0;

	// recalc speed
	d[0].speed = 360.0 / d[0].speed;
	d[1].speed = 360.0 / d[1].speed;

	hiker *fast, *slow;
	if (d[0].speed < d[1].speed) {
		fast = &d[1];
		slow = &d[0];
	} else if (d[0].speed == d[1].speed) {
		return 0;
	} else {
		fast = &d[0];
		slow = &d[1];
	}
	
	double t = (360 - fast->pos + slow->pos) / (fast->speed - slow->speed);
	double angle = slow->pos + slow->speed * t;	//slow one's angle
	return (angle>=360);
}

int main(int argc, char **argv) {
	if (argc <= 1) {
		cout << "plz argument\n";
		return -1;
	}

	in.open(argv[1]);
	out.open("output.txt");

	int t, n;
	in >> t;
	for (int i=0; i<t; i++) {
		in >> n;
		for (cnt=0; cnt<n; cnt++) {
			int pcnt;
			in >> d[cnt].pos >> pcnt >> d[cnt].speed;
			if (pcnt > 1) {
				d[cnt+1].pos = d[cnt].pos;
				d[cnt+1].speed = d[cnt].speed+1;
				cnt++;
			}
		}

		cout << "Case #"<<i+1 << "\n";
		out << "Case #" << i+1 << ": " << process() << "\n";
	}

	in.close();
	out.close();

	return 0;
}
