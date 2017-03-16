#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>

using namespace std;

pair<int, int> sol;
void update_sol(int a, int b) {
	if(sol.first < 0
		|| abs(sol.first-sol.second) > abs(a-b)
		||( abs(sol.first - sol.second) == abs(a - b) && a<sol.first)
		|| (abs(sol.first - sol.second) == abs(a - b) && a == sol.first && b < sol.second))
	{
		sol = { a,b };
	}
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		out << "Case #" << test << ": ";
		string a, b;
		in >> a >> b;
		sol = { -1,-1 };
		for (int i = 0; i < a.length(); ++i) {
			if (a[i] == '?' && b[i] == '?') {
				string c = a, d = b;
				c[i] = '1';
				replace(c.begin() + i, c.end(), '?', '0');
				d[i] = '0';
				replace(d.begin() + i, d.end(), '?', '9');
				update_sol(stoi(c), stoi(d));
				c = a, d = b;
				c[i] = '0';
				replace(c.begin() + i, c.end(), '?', '9');
				d[i] = '1';
				replace(d.begin() + i, d.end(), '?', '0');
				update_sol(stoi(c), stoi(d));
				a[i] = b[i] = '0';
			}
			else if (a[i] == '?') {
				if (b[i] != '9') {
					string c = a, d = b;
					c[i] = b[i]+1;
					replace(c.begin() + i, c.end(), '?', '0');
					replace(d.begin() + i, d.end(), '?', '9');
					update_sol(stoi(c), stoi(d));
				}
				if (b[i] != '0') {
					string c = a, d = b;
					c[i] = b[i] - 1;
					replace(c.begin() + i, c.end(), '?', '9');
					replace(d.begin() + i, d.end(), '?', '0');
					update_sol(stoi(c), stoi(d));
				}
				a[i] = b[i];
			}
			else if (b[i] == '?') {
				if (a[i] != '9') {
					string c = a, d = b;
					d[i] = a[i] + 1;
					replace(c.begin() + i, c.end(), '?', '9');
					replace(d.begin() + i, d.end(), '?', '0');
					update_sol(stoi(c), stoi(d));
				}
				if (a[i] != '0') {
					string c = a, d = b;
					d[i] = a[i] - 1;
					replace(c.begin() + i, c.end(), '?', '0');
					replace(d.begin() + i, d.end(), '?', '9');
					update_sol(stoi(c), stoi(d));
				}
				b[i] = a[i];
			}
			else {
				if (a[i] < b[i]) {
					string c = a, d = b;
					replace(c.begin() + i, c.end(), '?', '9');
					replace(d.begin() + i, d.end(), '?', '0');
					update_sol(stoi(c), stoi(d));
				}
				else if (a[i] > b[i]) {
					string c = a, d = b;
					replace(c.begin() + i, c.end(), '?', '0');
					replace(d.begin() + i, d.end(), '?', '9');
					update_sol(stoi(c), stoi(d));
				}
			}
		}
		update_sol(stoi(a), stoi(b));
		out << setfill('0') << setw(a.length()) << sol.first << " " << setfill('0') << setw(a.length()) << sol.second << endl;
	}
	return 0;
}