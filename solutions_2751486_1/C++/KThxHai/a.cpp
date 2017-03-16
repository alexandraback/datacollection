
#include <map>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define INPUT_FILE_NAME "A-large"
#define OUTPUT_FILE_NAME "a"

char name[1001000];

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void solveCase(){
	int n;
	list<int> nStreakEndLocs;
	scanf("%s", name);
	scanf("%d", &n);

	int streak = 0;
	for(int i = 0; name[i] != 0; ++i) {
		if(isVowel(name[i])) {
			streak = 0;
		} else {
			streak += 1;
		}
		if(streak >= n) {
			nStreakEndLocs.push_back(i);
		}
//		printf("%c", name[i]);
//		printf("%d", streak);

	}
	//iterate over possible end positions
	int count = 0;
	VAR(a, nStreakEndLocs.begin());
	if(a == nStreakEndLocs.end()) {
		printf("%d", 0);
		return;
	}
	for(int i = *a; name[i] != 0; i++) {
		VAR(next, a);
		while(next != nStreakEndLocs.end() && *next <= i) {
			a = next;
			next++;
		}
//		printf("%d %d ", i, *a);

		count += *a - n + 2;
	}
	printf("%d", count);

//	printf(" ");
//	for(VAR(a, nStreakEndLocs.begin()); a != nStreakEndLocs.end(); a++) {
//		printf("%d", *a);
//	}
}

int main() {
	freopen(INPUT_FILE_NAME ".in","r",stdin);
	freopen(OUTPUT_FILE_NAME ".out","w",stdout);
	int caseAmount;
	scanf("%d", &caseAmount);
	for (int caseNumber = 1; caseNumber <= caseAmount; ++caseNumber) {
		printf("Case #%d: ", caseNumber);

		solveCase();

		printf("\n");
	}
	return 0;
}
