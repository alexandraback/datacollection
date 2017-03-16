#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
static int caseNum = 1;
int maxcount = 0;
struct mystruct {
	int ID;
	bool enable;
};

void clearChildren(vector<mystruct>& children) {
	for (int i = 0; i < children.size(); i++) {
		children[i].enable = true;
	}
}
int inverseFind(vector<mystruct> children, int thisChild, int count) {
	
	int j;
	for (j = 0; j < children.size();j++) {
		if ((children[j].ID == thisChild) && children[j].enable) {
			children[j].enable = false;
			inverseFind(children, j, count+1);
		}
	}
	if (count > maxcount) maxcount = count;
	return maxcount;
}
int connectBBF(vector<mystruct>& children, int start) {
	int count = 1;
	int thisChild = start;
	children[thisChild].enable = false;
	int nextChild;
	bool direction = true;
	while (1) {
		if (direction) {
			if (children[children[thisChild].ID].enable) {
				nextChild = children[thisChild].ID;
				children[nextChild].enable = false;
				thisChild = nextChild;
				count++;
				if (count == children.size()) break;
			}
			else { direction = false; }
		}
		int inverseCount = 0;
		if(direction == false){
			count = count + inverseFind(children, thisChild, inverseCount);
			maxcount = 0;
			break;
		}	
	}
	return count;
}

void bbf(ifstream& in, ofstream& out, int N) {
	vector<mystruct> children;
	string temp;
	int tempNum;
	for (int i = 0; i < N; i++) {
		in >> temp;
		tempNum = stoi(temp);
		children.push_back({ tempNum - 1, true });
	}
	int bbf;
	int length = 0, maxlength = 0;
	for (int i = 0; i < children.size();i++) {
		
		clearChildren(children);
		length = connectBBF(children, i);
		if (maxlength < length) maxlength = length;
		break;
	}
	cout << "Case #" << caseNum << ": " << maxlength << endl;
	out << "Case #" << caseNum << ": " << maxlength << endl;
}

int main() {
	string temp;
	ifstream file("C-small-attempt1.in");
	ofstream out("output.out");
	int T;
	file >> temp;
	T = stoi(temp);
	if (T >= 1 && T <= 100) {
		while (T != 0) {
			int N;
			file >> temp;
			N = stoi(temp);
			bbf(file, out, N);
			T--;
			caseNum++;
		}
	}
	return 0;
}