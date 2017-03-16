#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

void runCase()
{
	int K,L,S;
	cin >> K >> L >> S;
	string ks,ws,ss;
	cin >> ks >> ws;
	ks += "1111111";
	ss = "1111111";
	vector<int> cnt(100,0);
	rep(i0,K)rep(i1,K)rep(i2,K)rep(i3,K)rep(i4,K)rep(i5,K)rep(i6,K) {
		ss[0] = ks[i0];
		ss[1] = ks[i1];
		ss[2] = ks[i2];
		ss[3] = ks[i3];
		ss[4] = ks[i4];
		ss[5] = ks[i5];
		ss[6] = ks[i6];
		int c = 0;
		rep(i,S)  if(i+L<=S) {
			int f = 1;
			for(int j = 0; j < L; j++) {
				if(ss[i+j]!=ws[j]) f = 0;
			}
			c += f;
		}
		// if(c) {
			// cout << ss << endl;
		// }
		cnt[c]++;
	}
	int mv = 0;
	double ev = 0,en = 0;
	rep(i,100) if(cnt[i]) {
		ev += cnt[i] * i;
		en += cnt[i];
		mv = max(mv,i);
	}
	double rv;
	rv = mv - ev / en;
	printf("%.8lf\n",rv);
	// cout << rv << endl;
}

void runSample() {
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
