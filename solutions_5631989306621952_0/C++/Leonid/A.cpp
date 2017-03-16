#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <list>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("A-small-attempt1.out", "wt", stdout);
#endif
}

char line[1005];
void solve() {
	gets(line);
	int len = strlen(line);
	list<char> v;
	for (int i = 0; i < len; i++) {
		if (v.size() == 0 || line[i] >= *(v.begin())) {
			v.push_front(line[i]);
		} else {
			v.push_back(line[i]);
		}
	}
	for (list<char>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
		const char& value = *ii;
		putchar(value);		
	}
	putchar('\n');
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
            printf("Case #%d: ", i + 1);
            solve();
    }
    return 0;
}
