#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <utility>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int) (n); ++i)
#define fore(i, a, b) for(int i = (int) (a); i < (int) (b); ++i)

#define ll long long
#define ld long double
#define PLL pair <ld, ld>
#define PII pair <int, int>
#define pb push_back
#define sz size

const ld EPS = 1e-9;
const int MAXN = 510;
const int INF = (int)(2e9 + 1e-9);

int decode[] = {121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108, 98, 107, 114, 
122, 116, 110, 119, 106, 112, 102, 109, 97, 113};

int main()
{
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);    

	int tk;
	scanf("%d\n", &tk);

	string s;
	forn(ii, tk){
		getline(cin, s);
		printf("Case #%d: ", ii + 1);

		forn(i, s.size()){
			if (s[i] == ' ') cout << s[i];
			else
				cout << (char)decode[s[i] - 'a'];
		}
		cout << endl;
	}
	
	return 0;
}

