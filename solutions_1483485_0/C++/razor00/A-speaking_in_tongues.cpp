#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>

#define tr(c, i) for(typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define sz(c) int((c).size())
#define INF 1000000000
#define EPS 1e-9
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

/*
void solve() {
	char to[26], s[3][1005], t[3][1005];
	bool used[26] = {0};
	
	for(int i = 0; i < 3; ++i) gets(s[i]);
	for(int i = 0; i < 3; ++i) gets(t[i]);
	
	for(int i = 0; i < 26; ++i) to[i] = '-';
	
	for(int i = 0; i < 3; ++i) {
		for(int j = 0, bnd = strlen(s[i]); j < bnd; ++j)
			if(isalpha(s[i][j])) {
				to[s[i][j]-'a'] = t[i][j]-'a';	
				used[t[i][j]-'a'] = 1;
			}
	}
	
	to[16] = 25;
	to[25] = 16;
	for(int i = 0; i < 26; ++i) printf("	to[%d] = %d;\n", i, to[i]);
	for(int i = 0; i < 26; ++i) printf("to[%c]=%c\n", i+'a', to[i] == '-' ? '-' : to[i] + 'a');
//	for(int i = 0; i < 26; ++i) if(!used[i]) printf("not used=%c\n", i+'a');
	
}
*/

char to[26], s[105];
int T;

int main() {	
	to[0] = 24;
	to[1] = 7;
	to[2] = 4;
	to[3] = 18;
	to[4] = 14;
	to[5] = 2;
	to[6] = 21;
	to[7] = 23;
	to[8] = 3;
	to[9] = 20;
	to[10] = 8;
	to[11] = 6;
	to[12] = 11;
	to[13] = 1;
	to[14] = 10;
	to[15] = 17;
	to[16] = 25;
	to[17] = 19;
	to[18] = 13;
	to[19] = 22;
	to[20] = 9;
	to[21] = 15;
	to[22] = 5;
	to[23] = 12;
	to[24] = 0;
	to[25] = 16;
		
	scanf("%d", &T); getchar();
	
	for(int tc = 0; tc < T; ++tc) {
		gets(s);
		
		for(int i = 0, bnd = strlen(s); i < bnd; ++i)
			if(isalpha(s[i])) s[i] = to[s[i]-'a'] + 'a';
			
		printf("Case #%d: %s\n", tc + 1, s);
	}
		
	return 0;
}
