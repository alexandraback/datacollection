#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <limits>
#include <map>
#define FOREACH(it, C) for(typeof((C).begin()) it = (C).begin(); it != (C).end(); ++it)
using namespace std;
typedef long long int ll;

ostream& operator<<(ostream& os, const vector<int>& v) {
    if(v.size() > 0) {
        for(size_t i = 0; i < v.size() - 1; ++i) {
            os << v[i] << " ";
        }
        os << v[v.size() - 1];
    }
    return os;
}

int n;
vector<int> numbers;

void solve(void) {
    map<int, int> p[n + 1];
    int i;
    for(i = 0; i < n; ++i) {
        int cur = numbers[i];
        if(p[i].count(0) > 0)
            break;
        p[i + 1][cur] = cur;
        FOREACH(it, p[i]) {
            p[i + 1][it->first + cur] = cur;
            p[i + 1][it->first - cur] = -cur;
            p[i + 1][it->first] = 0;
        }
    }
    if(p[i].count(0) == 0) {
        cout << "Impossible" << endl;
        return;
    }
    cout << "\n";
    vector<int> plus, minus;
    int cur = 0;
    do {
        int z = p[i][cur];
        if(z < 0)
            minus.push_back(-z);
        else if(z > 0)
            plus.push_back(z);
        cur -= z;
        --i;
    } while(cur != 0);
    cout << plus << "\n" << minus << endl;

}

int main() {
    int numberOfCases;
	cin >> numberOfCases;
	for(int testCase = 1; testCase <= numberOfCases; ++testCase) {
        cin >> n;
        numbers.resize(n);
        for(int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        
		cout << "Case #" << testCase << ":";
        solve();
	}
}
