#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)


map<int, bool> memo;

int n;
map<int, int> initial_keys;
vector<vector<int> > chest_keys;
vector<int> chest_lock;

bool can(int q)
{
	if(__builtin_popcount(q) == n) return true;
		
	map<int, bool>::iterator itq = memo.find(q);
	if(itq != memo.end()) return itq->second;

	map<int, int> keys = initial_keys;
	FORN(i, 0, n){
		if((q >> i) & 1){
			keys[chest_lock[i]]--;
			FOREACH(k, chest_keys[i]){
				keys[*k]++;
			}
		}
	}

	bool possible = false;
	FORN(i, 0, n){
		if(not((q >> i) & 1) and keys[chest_lock[i]] > 0){
			if(can(q | (1 << i))){
				possible = true;
				break;
			}
		}
	}

	memo[q] = possible;
	return possible;
}

int main(){
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		memo.clear();
		initial_keys.clear();

		int k;
		scanf("%d%d", &k, &n);
		
		FORN(i, 0, k){
			int type;
			scanf("%d", &type);
			initial_keys[type]++;
		}

		chest_keys.resize(n);
		chest_lock.resize(n);
		FORN(i, 0, n){
			int num_keys;
			scanf("%d%d", &chest_lock[i], &num_keys);
			chest_keys[i].resize(num_keys);
			FORN(j, 0, num_keys){
				scanf("%d", &chest_keys[i][j]);
			}
		}

		printf("Case #%d:", tc + 1);
		if(can(0)){
			int printed = 0;
			map<int, int> keys = initial_keys;
			FORN(pos, 0, n){
				FORN(i, 0, n){
					if(not((printed >> i) & 1) and keys[chest_lock[i]] > 0 and can(printed | (1 << i))){
						printf(" %d", i + 1);
						printed |= 1 << i;
						keys[chest_lock[i]]--;
						FOREACH(k, chest_keys[i]){
							keys[*k]++;
						}
						break;
					}
				}
			}
		}else{
			printf(" IMPOSSIBLE");
		}
		printf("\n");
		
				
	}
}
