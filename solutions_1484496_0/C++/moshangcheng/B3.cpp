#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
	int v, prevV;
	Node(int a, int b) : prevV(a), v(b) {}
};

int N;
int v[500];
map<int, int> vCount;
map<int, int>::iterator cnt;

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");

	int T;
	in >> T;
	for(int i = 1; i <= T; i++) {
		in >> N;
		vCount.clear();
		for(int j = 0; j < N; j++) {
			in >> v[j];
		}
		vCount[0] = 0;
		bool flag = false;
		for(int j = 0; j < N; j++) {
			map<int, int> tempCount = vCount;
			for(cnt = vCount.begin(); cnt != vCount.end(); cnt++) {
				if(tempCount.count(cnt->first + v[j]) > 0) {
					flag = true;
					out << "Case #" << i << ":\n";
					int cntV = cnt->first + v[j];
					out << cntV - vCount[cntV];
					for(cntV = vCount[cntV]; cntV > 0 && vCount.count(cntV) > 0; cntV = vCount[cntV]) {
						out << " " << cntV - vCount[cntV];
					}
					out << endl;
					cntV = cnt->first + v[j];
					out << v[j];
					for(cntV = cnt->first; cntV > 0 && vCount.count(cntV) > 0; cntV = vCount[cntV]) {
						out << " " << cntV - vCount[cntV];
					}
					out << endl;
					break;
				} else {
					tempCount[cnt->first + v[j]] = cnt->first;
				}
			}
			vCount = tempCount;
			if(flag) {
				break;
			}
		}
	}
	return 0;
}