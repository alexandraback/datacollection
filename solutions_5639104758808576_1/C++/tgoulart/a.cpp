#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

void solve(int testNo) {
    int S;
    string people;
    cin >> S >> people;

    int additional = 0;
    int alreadyThere = people[0] - '0';

    for (int i=1; i <= S; ++i) {
        int toAdd = max(0, i - alreadyThere);
        additional += toAdd;
        alreadyThere += toAdd + (people[i] - '0');
    }

    cout << "Case #" << testNo << ": " << additional << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solve(i);
    }
	return 0;
}
