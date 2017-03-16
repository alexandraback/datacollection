//#include "storeCredit.h"
//#include "reverseWords.h"
//#include "t9Spelling.h"
//#include "minimumScalarProduct.h"
//#include "milkshakes.h"

#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <list>

void magicTrick(int testcase) {
	std::set<short> a, b;
	short choice;
	std::cin >> choice;
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < 4; j++) {
			short buf;
			std::cin >> buf;
			if (i + 1 == choice)
				a.insert(buf);
		}
	}
	std::cin >> choice;
	for (auto i = 0; i < 4; i++) {
		for (auto j = 0; j < 4; j++) {
			short buf;
			std::cin >> buf;
			if (i + 1 == choice)
				b.insert(buf);
		}
	}
	std::set<short> c;
	std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.begin()));
	std::cout << "Case #" << testcase << ": ";
	if (c.size() == 1)
		std::cout << *c.begin();
	else if (c.size() == 0)
		std::cout << "Volunteer cheated!";
	else
		std::cout << "Bad magician!";
	std::cout << std::endl;
}

void cookieClicker(int testcase) {
	double c, f, x;
	std::cin >> c >> f >> x;
	double stayCost = x / 2, staySpd = 2;
	double farmCost = c / staySpd;
	double buyCost = x / (staySpd + f) + farmCost;
	while (buyCost < stayCost) {
		stayCost = buyCost;
		staySpd += f;
		farmCost += c / staySpd;
		buyCost = x / (staySpd + f) + farmCost;
	}
	std::cout << "Case #" << testcase << ": ";
	printf("%.7f\n", stayCost);
}

class Mine {
public:
	int r, c, m, f, rc;
	std::vector<bool> table;
	std::vector<char> zeroTable;

	inline bool isZero(int pos, unsigned char isBound) {
		if ((isBound & 1) && table[pos - c - 1])
			return false;
		if ((isBound & 2) && table[pos - c])
			return false;
		if ((isBound & 4) && table[pos - c + 1])
			return false;
		if ((isBound & 8) && table[pos - 1])
			return false;
		if ((isBound & 16) && table[pos + 1])
			return false;
		if ((isBound & 32) && table[pos + c - 1])
			return false;
		if ((isBound & 64) && table[pos + c])
			return false;
		if ((isBound & 128) && table[pos + c + 1])
			return false;
		return true;
	}

	inline bool isNearZero(int pos, unsigned char isBound) {
		if ((isBound & 1) && zeroTable[pos - c - 1])
			return true;
		if ((isBound & 2) && zeroTable[pos - c])
			return true;
		if ((isBound & 4) && zeroTable[pos - c + 1])
			return true;
		if ((isBound & 8) && zeroTable[pos - 1])
			return true;
		if ((isBound & 16) && zeroTable[pos + 1])
			return true;
		if ((isBound & 32) && zeroTable[pos + c - 1])
			return true;
		if ((isBound & 64) && zeroTable[pos + c])
			return true;
		if ((isBound & 128) && zeroTable[pos + c + 1])
			return true;
		return false;
	}

	int checkTable() {
		unsigned char isBound;
		int ans = -1;
		int zeroCount = 0;
		// zero scan
		for (auto &i : zeroTable) {
			i = 0;
		}
		for (auto i = 0; i < rc; i++) {
			if (!table[i] && zeroTable[i] == 0) {
				isBound = 0;
				if (i < c)
					isBound |= 7;
				if (i % c == 0)
					isBound |= 41;
				if (i % c == c - 1)
					isBound |= 148;
				if (i >= rc - c)
					isBound |= 224;
				isBound = ~isBound;
				if (isZero(i, isBound)) {
					zeroCount++;
					zeroTable[i] = 1;
					ans = i;
				}
			}
		}
		// free is connected with zero check
		for (auto i = 0; i < rc; i++) {
			isBound = 0;
			if (i < c)
				isBound |= 7;
			if (i % c == 0)
				isBound |= 41;
			if (i % c == c - 1)
				isBound |= 148;
			if (i >= rc - c)
				isBound |= 224;
			isBound = ~isBound;
			if (!table[i] && zeroTable[i] == 0 && !isNearZero(i, isBound))
				return -1;
		}
		// zero connected check
		std::vector<int> q;
		q.push_back(ans);
		while (!q.empty()) {
			int cur = q.back();
			q.pop_back();
			zeroTable[cur] = 2;
			zeroCount--;
			if (cur - c >= 0 && zeroTable[cur - c] == 1)
				q.push_back(cur - c);
			if (cur - 1 >= 0 && zeroTable[cur - 1] == 1)
				q.push_back(cur - 1);
			if (cur + c < rc && zeroTable[cur + c] == 1)
				q.push_back(cur + c);
			if (cur + 1 < rc && zeroTable[cur + 1] == 1)
				q.push_back(cur + 1);
		}
		if (zeroCount > 0)
			return -1;
		else
			return ans;
	}

	void mineSweeper(int testcase) {
		int click;
		std::cin >> r >> c >> m;
		rc = r * c;
		f = rc - m;
		if (f == 1) {
			std::cout << "Case #" << testcase << ":" << std::endl;
			for (auto i = 0; i < rc; i++) {
				if (i == 0)
					std::cout << "c";
				else
					std::cout << "*";
				if (i % c == c - 1)
					std::cout << std::endl;
			}
			return;
		}
		zeroTable.resize(r * c);
		table = std::vector<bool>(r * c, true);
		for (auto i = 0; i < f; i++) {
			table[i] = false;
		}
		click = checkTable();
		while (click < 0) {
			if (!std::next_permutation(table.begin(), table.end()))
				break;
			if (table[1])
				break;
			click = checkTable();
		}
		std::cout << "Case #" << testcase << ":" << std::endl;
		if (click < 0)
			std::cout << "Impossible" << std::endl;
		else {
			for (auto i = 0; i < rc; i++) {
				if (click == i)
					std::cout << "c";
				else if (table[i])
					std::cout << "*";
				else
					std::cout << ".";
				if (i % c == c - 1)
					std::cout << std::endl;
			}
		}
	}

};

void deceitfulWar(int testcase) {
	int n;
	std::cin >> n;
	std::vector<int> a(n, 0), b(n, 0);
	for (auto i = 0; i < n; i++) {
		float buf;
		std::cin >> buf;
		buf *= 100000;
		a[i] = static_cast<int>(buf);
	}
	for (auto i = 0; i < n; i++) {
		float buf;
		std::cin >> buf;
		buf *= 100000;
		b[i] = static_cast<int>(buf);
	}
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	// war
	int score1 = 0, score2 = 0;
	std::list<int> al(a.begin(), a.end()), bl(b.begin(), b.end());
	// nao choose heavy first
	for (auto i = 0; i < n; i++) {
		if (al.back() > bl.back()) {
			score2++;
			al.pop_back();
			bl.pop_front();
		}
		else {
			al.pop_back();
			bl.pop_back();
		}
	}
	// deceit war
	al = std::list<int>(a.begin(), a.end());
	bl = std::list<int>(b.begin(), b.end());
	for (auto i = 0; i < n; i++) {
		if (al.front() < bl.front()) {
			al.pop_front();
			bl.pop_back();
		}	else {
			al.pop_front();
			bl.pop_front();
			score1++;
		}
	}
	std::cout << "Case #" << testcase << ": " << score1 << " " << score2 << std::endl;
}

void run() {
	int nTest;
	std::cin >> nTest;
	//Mine mine;
	for (auto i = 0; i < nTest; i++) {
		//mine.mineSweeper(i + 1);
		deceitfulWar(i + 1);
	}
}

int main() {
	//StoreCredit inst;
	//ReverseWords inst;
	//T9Spelling inst;
	//MinimumScalarProduct inst;
	//Milkshakes inst;
	//inst.run();
	run();
	return 0;
}
