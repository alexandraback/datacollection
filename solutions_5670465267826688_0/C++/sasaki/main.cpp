#include <iostream>
#include <cassert>
using namespace std;

struct Quaternion {
    char c;
    bool negative;

    void init() {
	c = '1';
	negative = false;
    }

    Quaternion &operator*=(char r) {
	if (c == '1') {
	    c = r;
	} else if (c == 'i') {
	    if (r == 'i') {
		c = '1';
		negative = !negative;
	    } else if (r == 'j') {
		c = 'k';
	    } else if (r == 'k') {
		c = 'j';
		negative = !negative;
	    } else {
		assert(false);
	    }
	} else if (c == 'j') {
	    if (r == 'i') {
		c = 'k';
		negative = !negative;
	    } else if (r == 'j') {
		c = '1';
		negative = !negative;
	    } else if (r == 'k') {
		c = 'i';
	    } else {
		assert(false);
	    }
	} else if (c == 'k') {
	    if (r == 'i') {
		c = 'j';
	    } else if (r == 'j') {
		c = 'i';
		negative = !negative;
	    } else if (r == 'k') {
		c = '1';
		negative = !negative;
	    } else {
		assert(false);
	    }
	}
	return *this;
    }

    bool isI() {
	return c == 'i' && !negative;
    }
    bool isJ() {
	return c == 'j' && !negative;
    }
    bool isK() {
	return c == 'k' && !negative;
    }

    bool isOne() {
	return c == '1' && !negative;
    }
};

class Solver {
    string str;

public:
    Solver(long x, string s) {
	for (long i = 0; i < x; i++)
	    str += s;
    }

    string solve() {
	if (getI() && getJ() && getK() && getOne())
	    return "YES";
	return "NO";
    }

    Quaternion q;
    long index;
    
    bool getI() {
	q.init();
	index = 0;
	for (; index < str.size(); index++) {
	    q *= str[index];
	    if (q.isI())
		return true;
	}
	return false;
    }

    bool getJ() {
	q.init();
	index = index+1;
	for (; index < str.size(); index++) {
	    q *= str[index];
	    if (q.isJ())
		return true;
	}
	return false;
    }

    bool getK() {
	q.init();
	index = index+1;
	for (; index < str.size(); index++) {
	    q *= str[index];
	    if (q.isK())
		return true;
	}
	return false;
    }

    bool getOne() {
	q.init();
	index = index+1;
	for (; index < str.size(); index++) {
	    q *= str[index];
	}
	return q.isOne();
    }
};

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
	long L, X;
	cin >> L >> X;
	string str;
	cin >> str;
	Solver solver(X, str);
	cout << "Case #" << t << ": " << solver.solve() << endl;
    }
}
