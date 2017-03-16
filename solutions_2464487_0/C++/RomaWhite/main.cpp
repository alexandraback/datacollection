//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ULL;
typedef long long               LL;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000)
#define FILL                    CLEAR

const int MOD = 1000000007;

void submit(){
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
}

int main()
{
	submit();

	int t;
	cin >> t;
	FOR(ttt,0,t){
		LL r , t;
		cin >> r >> t;
		r = 2 * r + 1;
		LL res = 0;
		while (1){
			if (t >= r){
				++res;
				t -= r;
				r += 4;
			}
			else break;
		}
		cout << "Case #" << ttt + 1 << ": "<< res << endl;
	}

    return 0;
};