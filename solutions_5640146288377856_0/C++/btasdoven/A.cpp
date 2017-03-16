#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

int tc;
#define printg tc++, printf("Case #%d: ",tc), printf
#define gout tc++, printf("Case #%d: ",tc), cout
#define INF (1<<29)
	
void solve() {
	int R, C, W;
	scanf("%d %d %d", &R, &C, &W);
	
	gout << R*(C/W + W - 1 + ((C % W) > 0 ? 1 : 0)) << endl;
}
	
int main(void){
	int T;
	
	scanf("%d", &T);
	
	REP(i, T)
		solve();
	return 0;
}