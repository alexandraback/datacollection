#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct tribe {
	int d_first, n, w_first, e_first, s_first, delta_d, move, delta_s;
};

int main(int argc, char* argv[])
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int t;
	in >> t;
	for (int c=1; c<=t; c++) {
		out << "Case #" << c << ": ";
		int N;
		in >> N;
		vector<tribe> tribes;
		for (int i=0; i < N; ++i) {
			tribe a;
			in >> a.d_first >> a.n >> a.w_first >> a.e_first >> a.s_first >> a.delta_d >> a.move >> a.delta_s;
			tribes.push_back(a);
		}
		map<double, int> wall;
		for (double i = -200; i <= 200; i += 0.5) {
//			if (abs(i-int(i)) < 0.01) {wall[int(i)] = 0;}
					wall[i] = 0; 
		}
		int tribes_left = N; int count_suc(0);
		while (tribes_left) {
			vector<int> next_attackers;
			int next(INT_MAX);
			for (int i(0); i < tribes.size(); i++) {
				if (tribes[i].n == 0) {continue;}
				if (tribes[i].d_first < next) {
					next_attackers.clear();
					next_attackers.push_back(i);
					next = tribes[i].d_first;
				}
				else if (tribes[i].d_first == next) {
					next_attackers.push_back(i);
				}
			}
			vector<int> set;
			for (int i(0); i < next_attackers.size(); i++) {
				cout << next_attackers[i];
				//check if succeeded
				bool suc(false);
				for (double j(tribes[next_attackers[i]].w_first); j <= tribes[next_attackers[i]].e_first; j+=.5) {
					if (wall[j] < tribes[next_attackers[i]].s_first) {
						suc = true;
					}
				}
				if (suc) count_suc++;
				set.push_back(tribes[next_attackers[i]].w_first); set.push_back(tribes[next_attackers[i]].e_first);
				set.push_back(tribes[next_attackers[i]].s_first);
				//update struct
				tribes[next_attackers[i]].d_first += tribes[next_attackers[i]].delta_d;
				tribes[next_attackers[i]].n--;
				tribes[next_attackers[i]].w_first += tribes[next_attackers[i]].move; tribes[next_attackers[i]].e_first += tribes[next_attackers[i]].move;
				tribes[next_attackers[i]].s_first += tribes[next_attackers[i]].delta_s;
				//rem
				if (tribes[next_attackers[i]].n == 0) tribes_left--;
				cout << (suc ? 'S' : 'N');
			}
			cout << endl;
			//update wall
			for (int i(0); i < set.size(); i+=3) {
				for (double j(set[i]); j <= set[i+1]; j+=.5) {
					wall[j] = max(wall[j], set[i+2]);
				}
			}
		} //while
		out << count_suc << endl;
		cout << "----" << endl;
	}

}//main