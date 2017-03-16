#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

fstream in, out;

int t;
int a, b;

int numdigits(int x) {
	int ret = 0;
	while (x > 0) {
		x /= 10;
		ret++;
	}
	return ret;
}

int pow(int exp) {
	int ret = 1;
	for (int i = 0; i < exp; i++) {
		ret *= 10;
	} 
	return ret;
}

int main() {
	in.open("probc.in", fstream::in);
	out.open("probc.out", fstream::out);

	set<int> used;
	in >> t;
    for (int i = 0; i < t; i++) {
		in >> a >> b;

	    long long ans = 0;
		int digits = numdigits(a);
		int mult = pow(digits - 1);
		for (int j = a; j < b; j++) {
			used.clear();
			int temp = j;
			for (int k = 0; k < digits - 1; k++) {
				temp = temp / 10 + (temp % 10) * mult;
				if (temp > j && temp <= b && used.count(temp) == 0) {
					ans = ans + 1;
					used.insert(temp);
				}
			}
		}
		
		out << "Case #" << i + 1 << ": " << ans << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
