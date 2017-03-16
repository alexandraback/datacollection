#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void proc(int tc, ifstream &in, ofstream &out){
	double C, F, X;
	in >> C >> F >> X;
	double curRate = 2;
	double best = X / curRate;

	if (X >= C){
		double s = 0;
		while (true){
			double farm = C / curRate;
			double keep = X / curRate;

			best = min(best, s + keep);

			s += farm;
			
			if (s > best){
				break;
			}
			
			curRate += F;
		}
	}

	out << fixed;
	out.precision(7);
	out << "Case #" << tc << ": " << best << endl;

}

int main(){
	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-attempt0.out");

	int T;
	in >> T;
	for (int i = 1; i <= T; ++i){
		proc(i, in, out);
	}
}