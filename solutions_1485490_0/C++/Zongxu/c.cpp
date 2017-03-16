#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>
#include <deque>
#include <list>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;

typedef long long lint;

int n, m;
lint numA[100], numB[100], maxRes;
int typeA[100], typeB[100];

void go(int posA, int posB, int remTypeA, int remTypeB, lint remNumA, lint remNumB, lint res) {
	if (posA==n && posB==m) {
		if (maxRes < res)
			maxRes = res;
	}
	else {
		if (posA<n) {
			if (typeA[posA]==remTypeB)
				go(posA+1, posB, typeA[posA], remTypeB, numA[posA]-min(numA[posA], remNumB), remNumB-min(numA[posA], remNumB), res+min(numA[posA], remNumB));
			else
				go(posA+1, posB, typeA[posA], remTypeB, numA[posA], remNumB, res);
		}
		if (posB<m) {
			if (typeB[posB]==remTypeA)
				go(posA, posB+1, remTypeA, typeB[posB], remNumA-min(remNumA, numB[posB]), numB[posB]-min(remNumA, numB[posB]), res+min(remNumA, numB[posB]));
			else
				go(posA, posB+1, remTypeA, typeB[posB], remNumA, numB[posB], res);
		}
		if (posA<n && posB<m) {
			if (typeA[posA] == typeB[posB])
				go(posA+1, posB+1, typeA[posA], typeB[posB], numA[posA]-min(numA[posA], numB[posB]), numB[posB]-min(numA[posA], numB[posB]), res+min(numA[posA], numB[posB]));
			//else
			//	go(posA+1, posB+1, typeA[posA], typeB[posB], numA[posA], numB[posB], res);
		}
	}
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small.out", "w", stdout);

	int T; cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>n>>m;
		for (int i=0; i<n; i++) {
			cin>>numA[i]>>typeA[i];
		}
		for (int i=0; i<m; i++) {
			cin>>numB[i]>>typeB[i];
		}

		maxRes = 0;
		go(0,0,0,0,0,0,0);

		printf("Case #%d: ", t);
		cout<<maxRes<<endl;
	}

	return 0;
}
