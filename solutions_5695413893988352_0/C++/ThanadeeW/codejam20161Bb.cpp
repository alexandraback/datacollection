#include "main.h"

using namespace Core;
using namespace std;

void Core::init() {}

enum class Mode {
	CODER, JAMMER, EITHER
};

int pre(long long s) {
	return (s / 10) % 10;
}

void Core::solve() {
	string coder, jammer;
	CGET(coder);
	CGET(jammer);
	long long coderR = 0, jammerR = 0;
	Mode mode = Mode::EITHER;
	fori(i, coder.size()) {
		coderR *= 10;
		jammerR *= 10;
		if (coder[i] == '?' && jammer[i] == '?') {
			switch (mode) {
			case Mode::EITHER:
				break;
			case Mode::CODER:
				jammerR += 9;
				break;
			case Mode::JAMMER:
				coderR += 9;
				break;
			}
		} else if (coder[i] == '?') {
			switch (mode) {
			case Mode::EITHER:
				coderR += jammer[i] - '0';
				jammerR += jammer[i] - '0';
				break;
			case Mode::CODER:
				break;
			case Mode::JAMMER:
				coder += 9;
				break;
			}
		} else if (jammer[i] == '?') {
			switch (mode) {
			case Mode::EITHER:
				coderR += coder[i] - '0';
				jammerR += coder[i] - '0';
				break;
			case Mode::CODER:
				jammerR += 9;
				break;
			case Mode::JAMMER:
				break;
			}
		} else {
			switch (mode) {
			case Mode::EITHER:
				if (coder[i] == jammer[i]) {
					break;
				}
				coderR += coder[i] - '0';
				jammerR += jammer[i] - '0';
				int diff = 10000;
				long long aa, bb;
				auto checkDiff = [&](long long a, long long b) {
					if (diff > std::abs(a - b)) {
						aa = a;
						bb = b;
						diff = std::abs(a - b);
					}
				};
				if (i > 0 && pre(coderR) != 0 && coder[i - 1] == '?') {
					checkDiff(coderR - 10, jammerR);
				}
				if (i > 0 && pre(jammerR) != 0 && jammer[i - 1] == '?') {
					checkDiff(coderR, jammerR - 10);
				}
				checkDiff(coderR, jammerR);
				if (i > 0 && pre(jammerR) != 9 && jammer[i - 1] == '?') {
					checkDiff(coderR, jammerR + 10);
				}
				if (i > 0 && pre(coderR) != 9 && coder[i - 1] == '?') {
					checkDiff(coderR + 10, jammerR);
				}
				coderR = aa;
				jammerR = bb;
			}
		}
	}
	stringstream ss;
	ss << setfill('0') << setw(coder.size()) << coderR;
	cout << ss.str();
	ss.str("");
	ss << setfill('0') << setw(coder.size()) << jammerR;
	cout  << " " << ss.str() << endl;
}