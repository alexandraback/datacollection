#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <ctime>

using namespace std;

template<class T> inline T sqr(T x) { return x*x; }

typedef long long ll;

#define REP(i,n) for (int i=0;i<(n);i++)

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())
//コンテナのみ
#define CLR(a) memset((a), 0 ,sizeof(a))
//aはアドレス

const double PI = acos(-1.0);
/*
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
*/
// SORT(v); sort(array,array+N);
// vector<int>::iterator ite == find(ALL(v),number); *ite
//#define EACH(ite,c) for(typeof((c).begin()) ite=(c).begin(); ite!=(c).end(); ++ite)
// next_permutation(begin, end) イテレータが示す範囲の次の順列を生成する

int main() {
	/*テストケース変数*/
	int Test;
	scanf("%d", &Test);
	/*繰り返す時の変数初期化忘れに気を付ける*/
	for (int Ca = 1; Ca <= Test; Ca++){
		int r, c, w;
		scanf("%d %d %d", &r, &c, &w);
		int b = c / w;
		b = b * r + w;
		if (c % w == 0) b--;
		printf("Case #%d: %d\n", Ca, b);
	}
	return 0;
}

/* printf("Case #%d:",Ca); */