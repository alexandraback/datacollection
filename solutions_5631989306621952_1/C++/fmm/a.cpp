#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>
#define _ << " _ " <<
#define dbg(x) cerr << #x << " == " << x << endl
#define mp(x,y) make_pair((x),(y))
#define pv(x,y) {for(typeof(y) z=(x);z!=(y);z++)cerr<<*z<<" ";cerr<<endl;}
#define rep(x,y) for(int(x)=(0);(x)<int(y);++(x))
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pt;

#if 0
#define GENERATE 1
#endif

char S[1111];
int n;

void read() {
	cin >> S;
}

int cnt[1111];
int sig[1111];

void process() {
	memset(cnt,0,sizeof(cnt));
	
	n = strlen(S);

	rep(i,n) cnt[S[i]]++;

	//string ans="";

	for (int i = n-1; i > 0; i--) {
		int h = 0;
		for(int j=S[i]+1;j<300;j++) if(cnt[j]) h=1;
		if (h) {
			sig[i] = 'f';
			//ans = ans + S[i];
		} else {
			sig[i] = 'b';
			//ans = S[i] + ans;
		}
		cnt[S[i]]--;
	}

	string ans = "";
	ans += S[0];

	for(int i=1;i<n;i++) {
		if(sig[i]=='f') {
			ans = ans + S[i];
		} else {
			ans = S[i] + ans;
		}
	}

	printf(" %s\n",ans.c_str());
}

int main() {
	int T;
#ifdef GENERATE
	unsigned int seed=time(0);
	dbg(seed);
	srand(seed);
	T=50;
	for(int testcase=1;testcase<=T;++testcase) {
		fprintf(stderr,"Case #%d:",testcase);
		// *generate input!
		// BEGIN
		// END
#else
		cin>>T;
		for(int testcase=1;testcase<=T;++testcase) {
			fprintf(stdout,"Case #%d:",testcase);
			read();
#endif
		try {
			process();
		} catch(char const*exception) {
			puts(exception);
		}
	}
	return 0;
}
