#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack> 
#include <algorithm>
#include <math.h>
#include <sstream>
#include <functional>
#include <bitset>
#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
#define sz(a) (int)a.size()
#define pb push_back

const int MAX = 2147483647;
const int MAXN = 200100;
typedef long long LL;
const LL MOD = 1000000000 + 7;
#define M_PI       3.14159265358979323846
vector<int> a;


int main(int argc, char* argv[]) {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("numbers.in", "r", stdin); freopen("numbers.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	bool erat[MAXN];
	mems(erat, 1);
	for (int i = 2; i * i < MAXN; i++){
		if (erat[i]){
			for (int j = i * i; j < MAXN; j += i){
				erat[j] = false;
			}
		}
	}

	vector<int> primes;


	int t;
	cin >> t;
	//scanf("%d", &t);
	forn(ttt, 0, t){
		string s;
		cin >> s;

		string goods = "";
		for (int i = 0; i < s.size(); ++i){
			goods += "+";
		}

		int r_ptr = s.size() - 1;


		int ans = 0;

		while (r_ptr >= 0){
			while (r_ptr >= 0 && s[r_ptr] == '+'){
				r_ptr--;
			}

			if (r_ptr < 0){
				break;
			}

			if (s[0] == '+'){
				ans++;
				for (int i = 0; s[i] != '-'; i++){
					s[i] = '-';
				}
			}
			else{
				string t_s = s;
				for (int i = 0; i <= r_ptr; i++){
					s[i] = t_s[r_ptr - i];
					s[i] = s[i] == '+' ? '-' : '+';
				}

				ans++;
			}
		}

		printf("Case #%d: %d\n", ttt+1,ans);

	}
	return 0;
}