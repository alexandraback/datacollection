#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


ofstream out("out.txt");

//int largest(vector<int> v, int start) {
//	if (start >= v.size()) return -1;
//	int max = v.at(start);
//	int where = start;
//	for (int i = start+1; i < v.size(); i++) {
//		if (v.at(i) > max) {
//			max = v.at(i);
//			where = i;
//		}
//	}
//	return where;
//}
//
//int largest(vector<int> v, int start, int end) {
//	if (start >= v.size() or start > end) return -1;
//	int max = v.at(start);
//	int where = start;
//	for (int i = start+1; i <= end; i++) {
//		if (v.at(i) > max) {
//			max = v.at(i);
//			where = i;
//		}
//	}
//	return where;
//}
//
int r, e;
vector<int> events;
int next(int where, int subtotal, int nrg) {
	if(where == events.size()) {
//		cout << "stop at " << subtotal << endl;
		return subtotal;
	}
	int best = 0;
	for (int i = 0; i<=nrg; i++) {
//		if (nrg+r-i > e) continue;
//		cout << "use " << i << " ";
		int result = next(where+1, subtotal + i*events.at(where), min(nrg+r-i, e));
		if (result > best) best = result;
	}
//	cout << "best for position " << where << " is " << best << endl;
	return best;
}

int main() {
//	ifstream f("B-large.in");
	ifstream f("B-small-attempt3.in");
	int T;
	f >> T;

	for (int x = 0; x < T; x++) {
		events.clear();

		int n, b, nb;
		f >> e >> r >> n;

//		cout << e << " " << r << " " << " " << n << endl;
		for (int i = 0; i < n; i++) {
			int cost;
			f >> cost;
			events.push_back(cost);
//			cout << i << " " << n << endl;
		}

		int best = next(0, 0, e);
//		b = r;
//		int li = largest(events, 0);
//		total += events.at(li) * e;
//		int mi = largest(events, 0, li-1);
//		nb = li * r;
//		if ()
//		while (true){
//
//			int ni = largest(events, li+1);
//			if (ni == -1) break;
//			for (int i = li+1; i < ni; i++) {
//				int nb = b + r;
//				if (nb > e) {
//					b = e;
//					total += events.at(i) * (nb-e);
//				}
//				else {
//					b = nb;
//				}
////				cout << i << endl;
//			}
//			total += events.at(ni) * b;
//			b = r;
////			cout << li <<" "<< ni << endl;
//			li = ni;
//		}


		out << "Case #" << x+1 << ": " << best << endl;

	}



	return 0;
}
