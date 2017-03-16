//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include <time.h>
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

bool f(LL X , LL r , LL t){
	double d = 1.0 * X * (2 * X + 2 * r - 1);
	if (d > 4E18) return 0;
	if (X * (2 * X + 2 * r - 1) <= t) return 1;
	return 0;
}

LL v[10007];
LL down[10007] , up[10007];

int main()
{
	srand(time(0));
	submit();

	int t;
	cin >> t;
	cout << "Case #1:\n";
	int R , n , m , k;
	cin >> R >> n >> m >> k;
	FOR(i,0,R){
		vector<int> a(k);
		FOR(i,0,k)
			cin >> a[i];
		int b[3];
		vector<string> res;
		FOR(i1 , 2 , m + 1)
			FOR(i2 , 2 , m + 1)
			 FOR(i3 , 2 , m + 1){
				set<int> s;
				s.insert(1);
				s.insert(i1);
				s.insert(i2);
				s.insert(i3);
				s.insert(i1*i2);
				s.insert(i2*i3);
				s.insert(i3*i1);
				s.insert(i3*i1*i2);
				bool q = 1;
				FOR(i,0,k)
					if (s.find(a[i]) == s.end())
						q = 0;

				if (q){
					string r = "";
					r += i1 + '0';
					r += i2 + '0';
					r += i3 + '0';
					res.PB(r);
				}

		}
		
		cout << res[rand() % res.size()] << endl;

	}

    return 0;
};