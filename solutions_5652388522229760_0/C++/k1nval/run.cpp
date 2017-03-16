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
	int t;
	scanf("%d", &t);
	forn(ttt, 0, t){
		int n;
		scanf("%d", &n);
		LL lln = (LL)n;

		vector<char> v(10);
		LL ans = -1;
		for (LL i = 1; i <= 100000; ++i){
			LL nn = i * lln;
			while (nn > 0){
				v[nn % 10] = 1;
				nn /= 10;
			}
			bool good = true;
			for (int j = 0; j < 10; ++j){
				if (v[j] == 0){
					good = false;
					break;
				}
			}

			if (good){
				ans = i * lln;
				break;
			}
		}

		printf("Case #%d: ", ttt+1);
		if (ans == -1){
			printf("INSOMNIA\n");
		}
		else{
			printf("%I64d\n", ans);
		}
	}
	return 0;
}