#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define x first
#define y second
typedef pair<int, int> ii;
typedef long long int ll;

int N, A, T;
int mote[110];

int DP(int curr, int ind) {
	if (ind==N) return 0;
	if (curr>mote[ind]) return DP(curr+mote[ind], ind+1);
	if (curr==1) return N;
	return min(N-ind, DP(2*curr-1,ind)+1);
}


int main() {
	//FILE* fin = fopen("data.txt", "r");
	FILE* fin = fopen("A-small-attempt0.in", "r");
	FILE* fout = fopen("answer.txt", "w");
	fscanf(fin, "%d", &T);
	REP(mm, T) {
		fscanf(fin, "%d %d", &A, &N);
		REP(i, N) fscanf(fin, "%d", &mote[i]);
		sort(mote, mote+N);
		fprintf(fout, "Case #%d: %d\n", mm+1, DP(A,0));
	}
		
		
	
}
