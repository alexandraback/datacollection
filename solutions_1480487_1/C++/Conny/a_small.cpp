#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <deque>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int scores[200];
int nScores;
int sum;
double average;
double result[200];

struct Contest {
	int score;
	int no;
} contestants[200];

void getInput();
void getResult();

bool comp1(Contest c1, Contest c2) {
	return c1.score > c2.score;
}

bool comp2(Contest c1, Contest c2) {
	return c1.no < c2.no;
}

int main() {
	//freopen("A-small-attempt0.in", "r", stdin); freopen("a-small0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("a-small1.out", "w", stdout);
	//freopen("A-small-attempt2.in", "r", stdin); freopen("a-small2.out", "w", stdout);
	//freopen("A-small-attempt3.in", "r", stdin); freopen("a-small3.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("a-large.out", "w", stdout);

	cout << fixed << setprecision(6);
	int cases;
	cin >> cases;
	cin.ignore();
	for (int cnt = 1; cnt <= cases; cnt++) {
		getInput();
		cout << "Case #" << cnt << ":";
		getResult();
		cout << endl;
	}

	return 0;
}

void getInput() {
	sum = 0;
	cin >> nScores;
	for (int i = 0; i < nScores; i++) {
		contestants[i].no = i;
		cin >> contestants[i].score;
		sum += contestants[i].score;
	}
}

void getResult() {
	sort(contestants, contestants + nScores, comp1);

	int con = nScores;
	int sum1 = sum + sum;

	int index = 0;
	average = (double)(sum1) / con;
	while (contestants[index].score > average) {
		sum1 -= contestants[index].score;
		index++;
		con--;
		average = (double)sum1 / con;
	}

	sort(contestants, contestants + nScores, comp2);

	for (int i = 0; i < nScores; i++) {
		double needed = average - contestants[i].score;
		if (needed < 0)
			cout << ' ' << 0.000000;
		else {
			cout << ' ' << needed * 100 / sum;
		}
	}	
}
