#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

using namespace std;

struct Level
{
	int reqs[2];
	int got; // How many points we've received so far
};

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
		int numLevels = atoi(line.c_str());
		Level levels[numLevels];
		for (int l = 0; l < numLevels; ++l) {
			getline(in, line);
			// Tokenize the line
			list<string> tokens;
			istringstream iss(line);
			copy(istream_iterator<string>(iss), istream_iterator<string>(),
					back_inserter<list<string>>(tokens));
			levels[l].reqs[0] = atoi(tokens.front().c_str());
			tokens.pop_front();
			levels[l].reqs[1] = atoi(tokens.front().c_str());
			levels[l].got = 0;
		}
		// Sort lowest to highest by stars required to finish the second level
		sort(levels, levels + numLevels, [](const Level& a, const Level&b)
				{
					return a.reqs[1] < b.reqs[1];
				});
		bool won = false;
		int stars = 0;
		int levelsPlayed = 0;
		while(!won) {
			// Find one that can get us the most points
			Level* todo = nullptr;
			int starsOp = 0;
			for (auto& l : levels) {
				if (l.got < 2) {
					if (stars >= l.reqs[1] && 2 - l.got > starsOp) {
						starsOp = 2 - l.got;
						todo = &l;
					}
					if (stars >= l.reqs[0] && 1 - l.got > starsOp) {
						starsOp = 1 - l.got;
						todo = &l;
					}
				}
			}
			// If we don't have a level we can play, game over. We lose
			if (todo == nullptr)
				break;

			// Play the level for the points we can get
			todo->got += starsOp;
			if (todo->got > 2)
				printf("wtf eh\n");
			stars += starsOp;
			++levelsPlayed;

			// Check if we won
			won = true;
			for (const auto& l : levels) {
				if (l.got < 2) {
					won = false;
					break;
				}
			}
		}
		if (won)
			printf("Case #%d: %d\n", c, levelsPlayed);
		else
			printf("Case #%d: Too Bad\n", c);
	}
	return 0;
}
