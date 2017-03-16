#include <cstdlib>
#include <string>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int test;
	cin >> test;
	int n;
	for (n = 0; n < test; n++) {
		cout<<"Case #"<<(n + 1)<<": ";
		string s = "";

		string m;
		cin >> m;
		int g = m.size();
		int i;
		char p;
		for (i = 0; i < g; i++) {
			p = m.at(i);
			if (s.empty()) {
				s = s + p;
			} else {
				if (p < s.at(0)) {
					s = s + p;
				} else {
					s = p + s;
				}
			}
		}		

		cout<<s<<endl;


	}

}