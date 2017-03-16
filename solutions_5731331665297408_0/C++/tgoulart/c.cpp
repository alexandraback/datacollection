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

vector <string> zipcodes;
vector < vector <bool> > m;
vector <bool> visited;
string smallest;

void dfs(int currentCity, vector <int> previousCities, string acc) {
    visited[currentCity] = true;

    previousCities.push_back(currentCity);
    acc += zipcodes[currentCity];

    if (acc.length() == visited.size() * 5) {
        smallest = min(smallest, acc);
    } else {
        vector <int> tempPreviousCities;
        for (int k=0; k < previousCities.size(); ++k) {
            int comingFrom = previousCities[k];
            tempPreviousCities.push_back(comingFrom);

            for (int i=0; i < visited.size(); ++i) {
                if (!visited[i] && m[comingFrom][i]) {
                    dfs(i, tempPreviousCities, acc);
                }
            }
        }
    }

    visited[currentCity] = false;
}

int main() {
	int T;

    cin >> T;
    for (int t=1; t <= T; ++t) {
        int N, M;
        cin >> N >> M;

        zipcodes = vector <string>(N);
        m = vector < vector <bool> >(N, vector <bool>(N));
        visited = vector <bool>(N);
        smallest = "xxxx";

        for (int i=0; i < N; ++i) {
            cin >> zipcodes[i];
        }

        while (M--) {
            int i, j;
            cin >> i >> j;
            m[i-1][j-1] = m[j-1][i-1] = true;
        }

        for (int i=0; i < N; ++i) {
            dfs(i, vector <int>(), "");
        }

        cout << "Case #" << t << ": " << smallest << endl;
    }
	
	return 0;
}
