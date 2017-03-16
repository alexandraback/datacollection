// INCLUDE LIST
#include <cstdio>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

// DEFINE LIST
#define REP(_I, _J, _K) for(_I = (_J) ; _I < (_K) ; _I++)
#define input(_A)       freopen(_A, "r", stdin);
#define output(_A)      freopen(_A, "w", stdout);
#define INPUT           input("in.txt");
#define OUTPUT          output("out.txt");
#define CASE_LEFT(_A)   fprintf(stderr, "Cases left: %d\n", _A);
#define hold            {fflush(stdin); getchar();}
#define reset(_A, _B)   memset((_A), (_B), sizeof (_A));
#define debug           printf("<<TEST>>\n");
#define eps             1e-11
#define f_cmp(_A, _B)   (fabs((_A) - (_B)) < eps)
#define phi             acos(-1)
#define pb              push_back
#define value(_A)       cout << "Variabel -> " << #_A << " -> " << _A << endl;
#define st              first
#define nd              second

// TYPEDEF LIST
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       LL;

// VAR LIST
int MAX =               1000000;
int MIN =               -1000000;
int INF =               1000000000;
int x4[4] =             {0, 1, 0, -1};
int y4[4] =             {1, 0, -1, 0};
int x8[8] =             {0, 1, 1,  1,  0, -1, -1, -1};
int y8[8] =             {1, 1, 0, -1, -1, -1,  0,  1};
int i, j, k;

// MAIN CODE
int main () {
	input("B-large.in");
	output("out.txt");
	int t, n, kasus = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		
		vector<int> arr;
		int count[100010], x;
		reset(count, false);
		
		for (int i = 0; i < n * 2 - 1; i++) {
			for (int j = 0; j < n; j++) {
				cin >> x;
				if (count[x] == 0) {
					arr.push_back(x);
				}
				
				count[x]++;
			}
		}
		
		vector<int> ret;
		for (int i = 0; i < arr.size(); i++) {
			if (count[arr[i]] % 2 == 1)
				ret.push_back(arr[i]);
		}
		
		sort(ret.begin(), ret.end());
		
		cout << "Case #" << ++kasus << ":";
		for (int i = 0; i < ret.size(); i++) cout << " " << ret[i];
		cout << endl;
	}
    return 0;
}

