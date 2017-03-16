#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};
ld start_time,end_time;

string solve() {
	int n;
	vector <ld> naom, kem;
	cin >> n;
	ld tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp; naom.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
		cin>>tmp;kem.push_back(tmp);
	}
	sort(all(naom));sort(all(kem));
	int scoresa = 0,scoresb=0;
	bool vis[1024];
	memset(vis,0,sizeof(vis));
	for (int i = 0; i < n; ++i) {
		bool done = false;
		for (int j = 0; j < n; ++j) {
			if (!done && !vis[j]) {
				if (naom[j]-epsylon > kem[i]) {
					vis[j]=1;
					done=true;
					scoresa++;
				}
			}
		}
		if (!done) {
			for (int j = 0; j < n; ++j) {
				if (!done&&!vis[j]) {
					vis[j]=1;
					done=true;
				}
			}
		}
	}
	 memset(vis,0,sizeof(vis));
	for (int i = 0; i < n; ++i) {
		bool done = false;
		for (int j = 0; j < n; ++j) {
			if (!done&&!vis[j]) {
				if (kem[j]-epsylon > naom[i]) {
					vis[j]=1;
					done =true;
				}
			}
		}
		if (!done) {
			for (int j = 0; j < n; ++j) {
				if (!done&&!vis[j]) {
					vis[j]=1;
					done=true;
					scoresb++;
				}
			}
		}
	}
	stringstream ss;
	ss << scoresa <<" "<<scoresb;
	return ss.str();
}



int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//start_time = get_time();
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test ,solve().c_str()); 
	}


	//end program
	//end_time=get_time()-start_time;
	return 0;
}




