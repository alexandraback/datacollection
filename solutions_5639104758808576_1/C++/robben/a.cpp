#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ifstream in("A-large.in");
	int t;
	in >> t;
	ofstream out;
	out.open("a.output");

	for(int z = 0; z < t; z++) {
		int invite = 0; 
		int lvl ;
		int buf = 0;
		in >> lvl;
		string s;
		in >> s;
		for(int i = 0; i < s.length(); i++) {
			buf += (int)(s[i] - '0');
			buf--;
			if(buf < 0){
				invite ++;
				buf = 0;
			}
		}
		out << "Case #" << z+1 << ": " << invite << endl;
	}
	out.close();
	return 0;
}
