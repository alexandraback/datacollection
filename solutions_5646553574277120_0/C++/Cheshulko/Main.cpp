//#pragma comment(linker, "/STACK:100000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <locale>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define rep(x, a, b) for(int (x) = (a); (x) < int(b); ++(x))
#define sci(x) scanf("%d", &(x))
#define scii(x, y) scanf("%d %d", &(x), &(y))
#define pri(x) printf("%d ", (x))
#define prii(x, y) printf("%d %d", (x), (y))
#define pril(x) printf("%d\n", (x));
#define priil(x, y) printf("%d %d\n", (x), (y));
#define Wait cin.sync(); cin.get();
#define INF 0x3F3F3F3F
#define y1 qwerty 
#define EPS 1e-6
using namespace std;
typedef long long                  ll;
typedef pair<long long, long long> pll;
typedef pair<int, int>             pii;
typedef pair<double, int>          pdi;
typedef pair<double, double>       pdd;
typedef pair<string, string>       pss;

int have[111111];
int t, c, d, v, a[111];

bool check(){
	int ok = 1;
	for (int i = 1; i <= v; ++i){
		if (have[i] == 0) return 0;
	}
	return 1;
}

int main(){
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);

	
	scanf("%d", &t);
	rep(_t, 0, t){
		memset(have, 0, sizeof have);
		memset(a, 0, sizeof a);
		scanf("%d %d %d", &c, &d, &v);
		rep(i, 0, d) scanf("%d", a + i);
		rep(h0, 0, 2){
			rep(h1, 0, 2){
				rep(h2, 0, 2){
					rep(h3, 0, 2){
						rep(h4, 0, 2){
							int all = 0;
							all += h0 == 1 ? a[0] : 0;
							all += h1 == 1 ? a[1] : 0;
							all += h2 == 1 ? a[2] : 0;
							all += h3 == 1 ? a[3] : 0;
							all += h4 == 1 ? a[4] : 0;
							if (all <= v)  have[all] = 1;
						}
					}
				}
			}
		}
		//cout << "have : " << endl;
		//rep(i, 1, v + 1){
		//	if (have[i]) cout << i << " ";
		//}
		//cout << endl;
		int cnt = 0;
		rep(i, 1, v + 3){
			if (check()){
				printf("Case #%d: %d\n", _t + 1, cnt);
				break;
			}
			
			if (!have[i]){
				//cout << i << endl;
				++cnt;
				int used[11111];
				memset(used, 0, sizeof used);
				have[i] = 1;
				used[i] = 1;
				rep(j, 1, v + 1){
					if (have[j] && !used[j] && i + j <= v && !have[i + j]) have[i + j] = 1, used[i + j] = 1;
				}
			}
		}
	}

	//printf("TIME: %.3lf\n", (long double)(clock()) / CLOCKS_PER_SEC);
	Wait 
	return 0;
}