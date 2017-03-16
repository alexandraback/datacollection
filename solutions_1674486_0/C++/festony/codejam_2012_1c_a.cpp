//============================================================================
// Name        : codejamtest2.cpp
// Author      : festony
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

struct C {
	int i;
	int parent_num;
	vector<int> parents;
};

bool check_diamond(C classes[], int c_size, int node_i) {
	if(classes[node_i].parent_num <= 1) {
		return false;
	}
	set<int> mid;
	set<int> checked_mid;
	set<int> root;
	for(int i=0; i<classes[node_i].parent_num; i++) {
		mid.insert(classes[node_i].parents[i]);
	}
	while(mid.size() != 0) {
		int temp = * mid.begin();
		mid.erase(temp);
		if(classes[temp].parent_num == 0) {
			root.insert(temp);
		} else {
			checked_mid.insert(temp);
			for(int i=0; i<classes[temp].parent_num; i++) {
				int temp2 = classes[temp].parents[i];
				if(mid.find(temp2) != mid.end()) {
					return true;
				}
				if(checked_mid.find(temp2) != checked_mid.end()) {
					return true;
				}
				if(root.find(temp2) != root.end()) {
					return true;
				}
				mid.insert(temp2);
			}
		}
	}
	return false;
}

bool check_diamond(C classes[], int c_size) {
	for(int i=1; i<c_size; i++) {
		if(check_diamond(classes, c_size, i)) {
			return true;
		}
	}
	return false;
}

static string process(int case_num, fstream & in) {
	clock_t t1=clock();
	char buf[10240];
	string temp_str = "";
	string result = "";

	int N;
	in >> N;
	C * classes = new C [N+1];
	for(int i=1; i<= N; i++) {
		classes[i].i = i;
		in >> classes[i].parent_num;
		int temp;
		for(int j=0; j<classes[i].parent_num; j++) {
			in >> temp;
			classes[i].parents.push_back(temp);
		}
	}


	if(check_diamond(classes, N+1)) {
		temp_str = "Yes";
	} else {
		temp_str = "No";
	}


	sprintf(buf, "Case #%d: %s\n", case_num + 1, temp_str.c_str());
	clock_t t2=clock();
	cout<<"Iteration " << case_num + 1 << " took " << t2-t1 << " mini seconds" << endl;
	result.append(buf);
	return result;
}

int main() {
	int caseNum = 0;
	fstream in("F:\\Users\\festony\\Downloads\\codejam\\2012_1c\\A-small-attempt0.in");
	fstream out("F:\\Users\\festony\\Downloads\\codejam\\2012_1c\\testout.txt", ios_base::out | ios_base::trunc);

	in >> caseNum;
	in.ignore(256, '\n');
	char buf[10240];

	string result = "";

	for(int i=0; i<caseNum; i++) {
		result.append(process(i, in));
	}
	cout << result;
	out << result;
	in.close();
	out.close();

}


