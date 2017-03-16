// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 2005;
const int INF = 0x3f3f3f3f;
const bool debug = true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector < int >VI;
typedef vector < string > VS;
typedef vector < VI > VVI;
typedef pair < int, int >PII;
typedef pair < int, PII > PIII;

char s[M];
int len;
const string word[] =
    { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
    "SEVEN", "EIGHT", "NINE"
};


bool is_empty()
{
    for (int i = 0; i < len; ++i) {
	if (s[i] != '1') {
	    return false;
	}
    }
    return true;
}

bool find_word(char x)
{
    for (int i = 0; i < len; ++i) {
	if (s[i] == x) {
	    return true;
	}
    }
    return false;
}

void remove_word(int digit)
{
    int word_len = SZ(word[digit]);

    for (int i = 0; i < word_len; ++i) {
	for (int j = 0; j < len; ++j) {
	    if (s[j] == word[digit][i]) {
		s[j] = '1';
		break;
	    }
	}
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for (int t = 1; t <= tc; ++t) {
	scanf("%s", s);
	len = strlen(s);

	vector < pair < char, int > >digit_map;

	digit_map.push_back(make_pair('Z', 0));
	digit_map.push_back(make_pair('W', 2));
	digit_map.push_back(make_pair('U', 4));
	digit_map.push_back(make_pair('X', 6));
	digit_map.push_back(make_pair('G', 8));
	digit_map.push_back(make_pair('O', 1));
	digit_map.push_back(make_pair('H', 3));
	digit_map.push_back(make_pair('F', 5));
	digit_map.push_back(make_pair('S', 7));
	digit_map.push_back(make_pair('N', 9));



	vector < int >result;

	while (!is_empty()) {
	    for (int i = 0; i < 10; ++i) {
		pair < char, int >cur = digit_map[i];

		if (find_word(cur.first)) {
		    result.push_back(cur.second);
		    remove_word(cur.second);
		    break;
		}
	    }
	}

	sort(ALL(result));

	printf("Case #%d: ", t);

	for (int i = 0; i < SZ(result); ++i) {
	    printf("%d", result[i]);
	}
	puts("");
    }

    return 0;
}
