#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void run() {
	int y=0,z=0;
	int n;
	cin >> n;
	set<double> me,you;
	for(int i=0; i<n; i++) {
		double tmp;
		cin >> tmp;
		me.insert(tmp);
	}
	for(int i=0; i<n; i++) {
		double tmp;
		cin >> tmp;
		you.insert(tmp);
	}
	
	/*for(set<double>::iterator it=me.begin(); it != me.end(); ++it) 
		cout << *it << ", ";
	cout << endl;
	for(set<double>::iterator it=you.begin(); it != you.end(); ++it) 
		cout << *it << ", ";
	cout << endl;*/


	set<double> me2=me, you2=you;

	for(int i=0; i<n; i++) {//war
		double myMove=*me2.rbegin();
		me2.erase(*me2.rbegin());
		set<double>::iterator yourMove=you2.upper_bound(myMove);
		if(yourMove == you2.end()) {
			z++;
			you2.erase(you2.begin());
		} else you2.erase(yourMove);
	}

	//deceptive war
	while(you.size() > 0) {
		while(*you.begin() > *me.begin()) {
			you.erase(*you.rbegin());
			me.erase(*me.begin());
			if(you.size() == 0) break;
		}
		if(you.size() == 0) break;
		while(*you.begin() < *me.begin()) {
			you.erase(*you.begin());
			me.erase(*me.begin());
			y++;
			if(you.size() == 0) break;
		}
	}

	cout << y << " " << z << endl;
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cout << "Case #" << (i+1) << ": ";
		run();
	}
}