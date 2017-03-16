#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int nLevels;

struct Level {
	Level(int n1, int n2) : no(n1), stars(n2) {}
	int no;
	int stars;
};

int small[1001], large[1001];
vector<Level> onePoint, twoPoint;

bool comp1(Level v1, Level v2) {
	return v1.stars > v2.stars;
}

bool comp2(Level v1, Level v2) {
	if (v1.stars != v2.stars)
		return v1.stars > v2.stars;

	int no1 = v1.no, no2 = v2.no;
	return large[no1] < large[no2];
}

bool comp3(Level v1, Level v2) {
	int no1 = v1.no, no2 = v2.no;

	if (large[no1] != large[no2])
		return large[no1] < large[no2];

	return v1.stars > v2.stars;
}

void removeSmall(int n) {
	for (vector<Level>::iterator it = onePoint.begin(); it != onePoint.end(); it++) {
		if (it->no == n) {
			onePoint.erase(it);
			return;
		}
	}
}

void moveNo(int n) {
	Level v(0,0);
	for (vector<Level>::iterator it = twoPoint.begin(); it != twoPoint.end(); it++) {
		if (it->no == n) {
			v = *it;
			large[n] = INT_MAX;
			twoPoint.erase(it);
			onePoint.push_back(v);
			return;
		}
	}
}

int getResult() {
	int result = 0;
	int points = 0;
	onePoint.clear();
	twoPoint.clear();

	for (int i = 0; i < nLevels; i++) {
		Level level(i, small[i]);
		onePoint.push_back(level);

		level = Level(i, large[i]);
		twoPoint.push_back(level);
	}

	while (!onePoint.empty() || !twoPoint.empty()) {
		result++;

		if (!twoPoint.empty()) {
			sort(twoPoint.begin(), twoPoint.end(), comp1);
			Level v = twoPoint.back();

			if (points >= v.stars) {
				twoPoint.pop_back();
				int no = v.no;
				points += 2;
				removeSmall(no);
				continue;
			}
		}

		if (!onePoint.empty()) {
			sort(onePoint.begin(), onePoint.end(), comp3);
			Level v = onePoint.back();
			if (points >= v.stars && large[v.no] == INT_MAX) {
				onePoint.pop_back();
				int no = v.no;
				points++;
				continue;
			}

			sort(onePoint.begin(), onePoint.end(), comp2);
			v = onePoint.back();

			if (points >= v.stars) {
				onePoint.pop_back();
				int no = v.no;
				points++;

				moveNo(no);
				continue;
			}
		}

		return -1;
	}

	return result;
}

int main() {
	ifstream cin("b-small-attempt2.in");
	ofstream cout("b-small.out");
	//ifstream cin("b-large.in");
	//ofstream cout("b-large.out");

	int cases;
	cin >> cases;

	for (int cnt = 1; cnt <= cases; cnt++) {
		cin >> nLevels;

		for (int i = 0; i < nLevels; i++)
			cin >> small[i] >> large[i];

		int result = getResult();
		cout << "Case #" << cnt << ": ";
		if (result >= 0)
			cout << result << endl;
		else
			cout << "Too Bad" << endl;
	}

	return 0;
}