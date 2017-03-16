#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

#define cin fin
#define cout fout

void run() {
	double c, f, x;
	cin>>c>>f>>x;
	double best = 1e10, base = 0, speed = 2.0;
	for (int i = 0; i <= 200000; ++i) {
		double t = base + x / speed;
		if (t < best) best = t;
		base += c / speed;
		speed += f;
	}
	char buf[100];
	sprintf(buf, "%.7lf", best);
	cout<<buf<<endl;
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		run();
	}
	return 0;
}