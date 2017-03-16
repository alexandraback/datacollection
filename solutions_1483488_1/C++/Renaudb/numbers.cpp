#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int pairs(const string &smin, int min, int max)
{
    set< pair< int, int > > s;
    int l = smin.size();


    for (int n = min; n <= max; n++) {
	ostringstream ss;
	ss << n;

	for (int i = 1; i < l; i++) {
	    int m = atoi((ss.str().substr(i, string::npos) + ss.str().substr(0, i)).c_str());
	    if (n < m && m <= max) {
		s.insert(pair<int, int>(n, m));
	    }
	}
    }

    return s.size();
}

int main(int argc, char **argv)
{
    ifstream f;
    string line;

    f.open(argv[1]);

    getline(f, line);
    int n = atoi(line.c_str());
    for (int i = 0; i < n; i++) {
	getline(f, line);

	int min, max;

	min = atoi(line.substr(0, line.find(' ')).c_str());
	max = atoi(line.substr(line.find(' '), string::npos).c_str());

	int c = pairs(line.substr(0, line.find(' ')), min, max);

	cout << "Case #" << i + 1 << ": " << c << endl;
    }

    f.close();

    return 0;
}
