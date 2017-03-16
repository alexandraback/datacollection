#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = 3.1415926535;
const double eps = 1e-6;

char s[110000];
map<char, char> hash;
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	hash['a'] = 'y';
	hash['b'] = 'h';
	hash['c'] = 'e';
	hash['d'] = 's';
	hash['e'] = 'o';
	hash['f'] = 'c';
	hash['g'] = 'v';
	hash['h'] = 'x';
	hash['i'] = 'd';
	hash['j'] = 'u';
	hash['k'] = 'i';
	hash['l'] = 'g';
	hash['m'] = 'l';
	hash['n'] = 'b';
	hash['o'] = 'k';
	hash['p'] = 'r';
	hash['q'] = 'z';
	hash['r'] = 't';
	hash['s'] = 'n';
	hash['t'] = 'w';
	hash['u'] = 'j';
	hash['v'] = 'p';
	hash['w'] = 'f';
	hash['x'] = 'm';
	hash['y'] = 'a';
	hash['z'] = 'q';
	hash[' '] = ' ';
	int T, ca = 0;
	for (scanf("%d", &T), gets(s); T; T--) {
		gets(s);
		printf("Case #%d: ", ++ca);
		int n = strlen(s);
		for (int i = 0; i < n; i++)
			cout << hash[s[i]];
		cout << endl;
	}
		
}
