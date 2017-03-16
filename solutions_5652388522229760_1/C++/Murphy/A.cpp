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
		int n; cin>>n;
		cout<<"Case #" << (casei + 1)<<": ";
		if (n == 0) {
			cout<<"INSOMNIA"<<endl;
		} else {
			LL x = n;
			int c = 0;
			if (x < 0) cerr<<"error";
			while (1) {
				LL y = x;
				while (y) {
					c |= 1<<(y % 10);
					y /= 10;
				}
				if (c == 1023) {
					cout<<x<<endl;
					break;
				}
				x += n;
			}
		}
	} 
	return 0;
}