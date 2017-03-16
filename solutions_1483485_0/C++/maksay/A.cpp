#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define L(s) (int)((s).size())
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define x first
#define y second
#define inf 1000000000
#define all(s) (s).begin(), (s).end()
#define ll long long
#define VI vector<int>
#define ull unsigned ll
//ifstream in1("input.txt"), in2("output.txt");
//int mapping[26];
//char ch1, ch2;
//int main() {
//	memset(mapping, -1, sizeof(mapping));
//	while(in1 >> ch1) {
//		in2 >> ch2;
//		mapping[ch1 - 'a'] = ch2 - 'a';
//	}
////	cout << mapping['o' - 'a'] << endl;
//	mapping['q' - 'a'] = 'z' - 'a';
//	mapping['z' - 'a'] = 16;
//	for(int i = 0; i < 26; ++i) cout << mapping[i] <<o ",";
//	return 0;
//}
int mapping[26] = {24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16};
int cases;
char str[111];
int main() {
	freopen("/home/maksay/Downloads/A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	gets(str); sscanf(str, "%d", &cases);
	for(int casenum = 1; casenum <= cases; ++casenum) {
		gets(str);
		int len = (int)strlen(str);
		for(int i = 0; i < len; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				str[i] = (char)('a' + mapping[str[i] - 'a']);
			}
		}
		printf("Case #%d: %s\n", casenum, str);
	}
}
