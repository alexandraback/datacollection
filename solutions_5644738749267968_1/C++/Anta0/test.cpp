#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

double a[1000], b[1000];
int main() {
	int T;
	scanf("%d", &T);
	rep(ii, T) {
		int N;
		scanf("%d", &N);
		rep(i, N) scanf("%lf", &a[i]);
		rep(i, N) scanf("%lf", &b[i]);
		sort(a, a + N);
		sort(b, b + N);
		//相手より重いブロックが存在する場合、その中で最小のものを言う。
		//	わざと負けると、その後負け確定が続いた場合に損。
		//	より重いブロックを使ってしまうと、その後ぎりぎり勝てた列が来た場合に損。
		//相手より重いブロックが存在しない場合、最小のものを言う。
		//	より重いブロックを使ってしまうと、その後ぎりぎり勝てた列が来た場合に損。
		int z = N;
		{	int left = 0;
			rep(i, N) {
				while(left < N && b[left] <= a[i]) left ++;
				if(left == N) break;
				z --; left ++;
			}
		}
		//相手に自分より重いブロックが存在する場合、
		//	本当の値以上で相手の最大未満の値を言えば、
		//		ポイントは入らないけど、本当の値以上の相手のブロックを捨てさせることができる。
		//	その値が相手の最小の値より大きい場合、相手の最大より大きい値を言えば、
		//		ポイントが入って、相手は最小の値を捨てる。
		//相手に自分より重いブロックが存在しない場合、
		//	相手の最大のブロックより小さい値を言うとばれてしまうので、どうしようもない。
		//	ポイントが入る。
		//相手に捨てさせるのは最大か最小のほうがよさそう。(たぶん)
		//相手の最小未満: 任意のブロックを捨てさせる
		//中間:           これ以上のブロックを捨てさせる or ポイント+最小を捨てさせる
		//相手の最大以上: ポイント+最小を捨てさせる
		//ポイントを得るには最小を捨てさせる必要がある。また、相手の最小より大きければそれができる。
		int y = 0;
		{	int left = 0;
			rep(i, N) {
				if(b[left] < a[i]) {
					left ++;
					y ++;
				}
			}
		}
		printf("Case #%d: %d %d\n", ii+1, y, z);
	}
	return 0;
}
