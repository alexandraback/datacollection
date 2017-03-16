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
	input("C-small-attempt0 (1).in");
	output("out.txt");
	int t, n, kasus = 0, f[1000];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> f[i];
			f[i]--;
		}
		
		int maximum = 0;
		
		for (int mask = 0; mask < (1 << n); mask++) {
			vector<int> permut;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) > 0)
					permut.push_back(i);
			}
			
			do {
				bool valid = true;
				
				for (int i = 0; i < permut.size(); i++) {
					int right = (i + 1) % (int)permut.size();
					int left = ((i - 1) + (int)permut.size()) % (int)permut.size();
					
					if (f[permut[i]] != permut[right] && f[permut[i]] != permut[left]) {
						valid = false;
						break;
					}
				}
				
				if (valid)
					maximum = max(maximum, (int)permut.size());
			} while (next_permutation(permut.begin(), permut.end()));
		}
		
		cout << "Case #" << ++kasus << ": " << maximum << endl;
	}
    return 0;
}

