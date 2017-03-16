#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define maxit(x,y) ((x) = max((x),(y)))
#define minit(x,y) ((x) = min((x),(y)))
typedef long long LL;

char mapping[128];

void update_mapping(const char *encoded, const char *decoded)
{
	assert(strlen(encoded) == strlen(decoded));
	for (int i = 0; encoded[i] != 0; ++i) {
		if (encoded[i] == ' ' || encoded[i] == '\n') continue;
		mapping[(int)encoded[i]] = decoded[i];
	}
}

int main()
{
	for (int i = 0; i < 128; ++i) {
		if (i < 'a' || i > 'z') mapping[i] = i;
	}
	update_mapping("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
	update_mapping("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
	update_mapping("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
	mapping['q'] = 'z';
	mapping['z'] = 'q';

	int cases;
	char buf[256];
	fgets(buf, 256, stdin);
	sscanf(buf, "%d", &cases);
	for (int T = 1; T <= cases; ++T) {
		printf("Case #%d: ", T);
		fgets(buf, 256, stdin);
		for (int i = 0; buf[i] != 0; ++i)
			buf[i] = mapping[(int)buf[i]];
		fputs(buf, stdout);
	}
	return 0;
}
