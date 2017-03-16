#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	// Take the first arg as an input file
	ifstream in(argv[1]);
	if (!in.good()) {
		fprintf(stderr, "bad input file\n");
		return 1;
	}
	string line;
	getline(in, line);
	int cases = atoi(line.c_str());
	for (int c = 1; c <= cases; ++c) {
		getline(in, line);
		// Tokenize the string
		list<string> tokens;
		istringstream iss1(line);
		copy(istream_iterator<string>(iss1), istream_iterator<string>(),
				back_inserter<list<string>>(tokens));
		int already = atoi(tokens.front().c_str());
		tokens.pop_front();
		int total = atoi(tokens.front().c_str());
		tokens.pop_front();
		tokens.clear();
		getline(in, line);
		istringstream iss2(line);
		copy(istream_iterator<string>(iss2), istream_iterator<string>(),
				back_inserter<list<string>>(tokens));
		double probs[already];
		for (int p = 0; p < already; ++p) {
			probs[p] = atof(tokens.front().c_str());
			tokens.pop_front();
		}
		// List of different amounts of possible keystrokes
		list<double> strokes;

		// Keystrokes if we just give up now
		strokes.push_back((double)(2 + total));

		// Probability we've typed everything corrct so far
		double csp = probs[0];
		for (int p = 1; p < already; ++p)
			csp *= probs[p];
		// Keystrokes if we keep typing
		strokes.push_back(csp * (double)(total - already + 1)
			+ (1.0 - csp) * (double)(total - already + 1 + total + 1));

		// Keystrokes if we back up a certain amount of characters
		for (int b = 1; b < already; ++b) {
			int strokesIfRight = total - already + 1 + 2 * b;
			int strokesIfWrong = strokesIfRight + total + 1;
			double bsp = probs[0];
			for (int p = 1; p < already - b; ++p)
				bsp *= probs[p];
			double bp = bsp * (double)strokesIfRight
					+ (1.0f - bsp) * (double)strokesIfWrong;
			strokes.push_back(bp);
		}

		printf("Case #\%d: %7.6f\n", c,
				*min_element(strokes.begin(), strokes.end()));
	}
	return 0;
}
