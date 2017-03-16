#include <iostream>
#include <fstream>
#include <queue>
#include <memory.h>
using namespace std;

int n;
ifstream in;
ofstream out;
int d[10000000];

int rev(int n) {
	int r = 0;
	for (; n>0; n/=10) {
		r *= 10;
		r += n%10;
	}
	return r;
}

void process(int n) {
	memset(d, 0, sizeof(d));
	d[1] = 1;
	for (int i=1; i<=n; i++) {
		if (d[i+1] == 0 || d[i+1] > d[i]+1)
			d[i+1] = d[i]+1;
		int r = rev(i);
		if (d[r] == 0 || d[r] > d[i]+1)
			d[r] = d[i]+1;

	}

	// check end
	if (d[n]) {
		out << d[n];
		return;
	}
}

int main () {
	in.open("input.txt");
	out.open("output.txt");
	
	in >> n;
	for (int i=0; i<n; i++) {
		int c;
		in >> c;
		out << "Case #" << i+1 << ": ";
		process(c);
		out << "\n";
		cout << i << "\n";
	}
	in.close();
	out.close();


	return 0;
}
