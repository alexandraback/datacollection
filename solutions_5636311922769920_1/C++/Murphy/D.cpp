#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main() {
	int casen; cin>>casen;
	REP(casei, casen) {
		cout<<"Case #" << (casei + 1)<<":";
		int c, k, s; cin>>k>>c>>s;
		if (c * s < k) {
			cout<<" IMPOSSIBLE"<<endl;
		} else {
			int x = 0;
			REP(i, s) {
				LL r = 0;
				REP(j, c) {
					r *= k;
					r += (x % k);
					x++;
				}
				cout<<' '<<r + 1;
				if (x >= k) {
					break;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}