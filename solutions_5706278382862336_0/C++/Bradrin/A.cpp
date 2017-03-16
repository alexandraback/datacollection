#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

 #include <sstream>

using namespace std;

double p;
double q;
string input;
double eps = pow(0.5,60);

double string_to_double(const string& s){
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
} 

void read() {
	cin >> input;
	size_t pos = 0;
	pos = input.find('/');
	p = string_to_double(input.substr(0, pos));
	input.erase(0, pos + 1);
	q = string_to_double(input);
}

void solve() {
	int level = 1;
	double per = 0.5;
	double total = (double)p/q;
	int gen = 1000;
	while (total > eps) {
		if (level > 40) {
			cout << "impossible" << endl;
			return;
		}
		if (total >= per) {
			total -= per;
			gen = min(level,gen);
		}
		per *= 0.5;
		level++;
	}
	cout << gen << endl;
}

int main() {
    freopen("inputA.in", "r", stdin);
	freopen("outputA.txt", "w", stdout);
	
    int cases;
    cin >> cases;
    for (int count = 1; count <= cases; count++) {
		read();
        cout << "Case #" << count << ": ";
		solve();
    }
    return 0;
}