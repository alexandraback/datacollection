/**************************************************
 * Author	 : xiaohao Z
 * Blog	 : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2015-05-02 23:59
 * Filename	 : A.cpp
 * Description	 : 
 * ************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;

ll ten[20];
ll Cnt[20];

void init() {
	ten[0] = 1;
	for(int i=1; i<20; i++) {
		ten[i] = ten[i - 1] * 10;
	}
	Cnt[0] = 1; Cnt[1] = 9;
	for(int i=2; i<20; i++) {
		int half = i / 2;
		Cnt[i] = ten[half] + ten[i - half] - 1;
//		cout << i << ": " << Cnt[i] << endl;
	}
}

ll solve(char str[]) {
	int len = strlen(str);
	ll Na = 0, Nb = 0;
	for(int i=len/2-1; i>=0; i--) {
		Na *= 10; Na += str[i] - '0';
	}
	for(int i=len/2; i<len; i++) {
		Nb *= 10; Nb += str[i] - '0';
	}
	if(Na <= 1)  Na --;
//	cout << Na << ' ' << Nb << endl;
	return Na + Nb;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("outA.txt", "w", stdout);

	int T, kase = 1;
	ll n;
	cin >> T;
	init();
	while(T--) {
		cin >> n;
		int pos = 0;
		ll ret = 0;
		for(int i=0; i<n; i++) if(ten[i] <= n) {
			pos = i;
			ret += Cnt[i];
		}else break;
//		cout << "ret : " << ret << endl;
		char str[20];
		if(n % ten[pos/2] == 0) {
			n--; ret++;
		}
		sprintf(str, "%d", n);
		ret += min(n - ten[pos], solve(str));
		cout << "Case #" << kase++ << ": " << ret << endl;
	}
	return 0;
}

