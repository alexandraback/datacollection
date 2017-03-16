#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
// use: ./A input.txt > output.txt

ifstream in;
int n;
int c,d,v;
int money[100];
#define MAX 100
bool ar[MAX];

void fill(int mon) {
	// fill ...?
		for (int j=v; j>=1; j--) {
			if (j-mon>0 && ar[j-mon])
				ar[j] = true;
		}
		ar[mon] = true;
}

void process(int idx) {
	int r = 0;

	memset(ar, 0, sizeof(ar));
	for (int i=0; i<d; i++) {
		fill(money[i]);
	}

	for (int i=1; i<=v; i++) {
		if (!ar[i]) {
			fill(i);
			r++;
		}
	}

	cout << "Case #" << idx << ": " << r << endl;
}

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "please enter input.txt argv\n";
		return -1;
	}

	in.open(argv[1]);

	in >> n;

	for (int i=0; i<n; i++) {
		in >> c >> d >> v;
		for (int j=0; j<d; j++) {
			int m;
			in >> m;
			money[j] = m;
		}
		process(i+1);
	}

	in.close();

	return 0;
}
