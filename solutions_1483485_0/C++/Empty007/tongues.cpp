#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

int main() {
	string ini = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd	de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string fin = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	int n = ini.length();
	map < char, char > mapa;
	
	mapa['z'] = 'q';
	mapa['q'] = 'z';
	REP(i, n) {
		mapa[ini[i]] = fin[i];
	}
	
	int T;
	string word;
	
	scanf("%d", &T);
	getline(cin, word);
	REP(i, T) {
		printf("Case #%d: ", i+1);
		getline(cin, word);
		for (int i = 0; i < word.length(); i++) if (isalpha(word[i])) cout << mapa[word[i]]; else cout << word[i];
		cout << "\n";
	}
	
	return 0;
}
