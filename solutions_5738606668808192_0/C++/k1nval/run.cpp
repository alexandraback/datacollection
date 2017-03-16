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

string get_bit(LL n){
	string s;
	while (n > 0){
		s.push_back('0' + n % 2);
		n /= 2;
	}

	reverse(all(s));
	return s;
}

int main(int argc, char* argv[]) {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("numbers.in", "r", stdin); freopen("numbers.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	//scanf("%d", &t);
	forn(ttt, 0, t){
		int N, J;
		cin >> N >> J;
		LL tmp;
		printf("Case #%d:\n", ttt + 1);

		string s;
		for (int i1 = 1; i1 <= N - 3; i1 += 2){
			if (J == 0) break;

			for (int i2 = i1 + 2; i2 <= N - 3; i2 += 2){
				if (J == 0) break;

				for (int j1 = 2; j1 <= N - 2; j1 += 2){
					if (J == 0) break;

					for (int j2 = j1 + 2; j2 <= N - 2; j2 += 2){
						if (J == 0) break;

						LL tmp = (1 << (N - 1));
						tmp++;
						tmp |= (1 << i1);
						tmp |= (1 << i2);
						tmp |= (1 << j1);
						tmp |= (1 << j2);
						cout << get_bit(tmp) << " 3 2 3 2 7 2 3 2 3" << endl;;
						J--;
					}
				}
			}
		}
		

	}
	return 0;
}