#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;

int B;
LL M;

bool possible;

struct Edge {
	int a, b;
};
Edge e[4096];
int nEdge;

void addEdge(int A, int B)
{
	e[nEdge].a = A;
	e[nEdge].b = B;
	nEdge ++;
}

string solv()
{
	LL path = (1ULL << (B-2));
	
	possible = (path >= M);
	if (possible) {
		nEdge = 0;
		for (int i=1;i<B;++i) {
			for (int j=i+1;j<B;++j) {
				addEdge(i, j);
			}
		}
		addEdge(0, B-1);
		M --;
		for (int i = 0; (1ULL << i) <= M; ++i) {
			if (M & (1ULL << i)) {
				addEdge(0, B-2-i);
			}
		}
	}
	return (possible? "POSSIBLE":"IMPOSSIBLE");
}

char table[51][51];

void dump()
{
	if (!possible) return;
	
	memset(table, 0, sizeof(table));
	
	for (int i=0;i<B;++i) for (int j=0;j<B;++j) table[i][j] = '0';
	
	for (int i=0;i<nEdge;++i) {
		//printf("(%d -> %d)\n", e[i].a, e[i].b);
		table[e[i].a][e[i].b] = '1';
	}
	for (int i=0;i<B;++i) {
		printf("%s\n", table[i]);
	}
}

int main()
{
	int T;
	cin >> T;
	for (int nCase = 1; nCase <= T; ++nCase) {
		cin >> B >> M;
		printf("Case #%d: %s\n", nCase, solv().c_str());
		dump();
	}
	return 0;
}