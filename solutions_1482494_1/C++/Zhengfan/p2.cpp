#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>

using namespace std;

struct level {
	int a, b;
	bool ad, bd;
};

int main(int argc, char* argv[]) {
	ifstream fff;
	fff.open(argv[1]);
	int T;
	fff >> T;
	for (int ttt=0; ttt<T; ttt++) {
		cout << "Case #" << ttt+1 << ": ";
		int N;
		fff >> N;
		level* x = new level[N];
		for (int i=0; i<N; i++) { 
			fff >> x[i].a >> x[i].b;
			x[i].ad = x[i].bd = false;
		}
		
		int step = 0;
		int star = 0;
		int finished = 0;
		bool toobad = false;
		while (finished < N) {
			int min = 10000;
			int mini = -1;
			for (int i=0; i<N; i++) {
				if (x[i].b < min && (!x[i].bd)) { min = x[i].b; mini = i; }
			}
			if (star >= min) {
				step++;
				x[mini].bd = true;
				if (x[mini].ad) star++; else star += 2;
				finished++;
				continue;
			}
			min = 10000;
			mini = -1;
			for (int i=0; i<N; i++) {
				if (x[i].a < min && (!x[i].ad) && (!x[i].bd)) { min = x[i].a; mini = i; }
			}
			if (star >= min) {
				int max = -1;
				int maxi = -1;
				for (int i=0; i<N; i++) {
					if (x[i].a <= star && x[i].b > max && (!x[i].ad) && (!x[i].bd)) { max = x[i].b; maxi = i; }
				}
				step++;
				x[maxi].ad = true;
				star++;
			} else {
				toobad = true;
				break;
			}
		}
		if (toobad) cout << "Too Bad" << endl;
		else cout << step << endl;
		delete[] x;
	}	
	fff.close();
}
