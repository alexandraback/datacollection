#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

bool solve(int x, int r, int c) {
	switch (x) {
	case 1: return true;
	case 2: return (r*c%2==0);
	case 3: return (r==2 && c==3)||(r==3 && c==3) || (r==3 && c==4);
	case 4: return (r==3 && c==4) || (r==4 && c==4);
	default: break;
	}
	return false;
}
//solve small scale first
int main(void) {
	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		int x,r,c;
		cin>>x>>r>>c;
		if (r>c) swap(r,c);
		bool G_win= solve(x, r, c);
		if (G_win) {
			cout<<"Case #"<<t<<": GABRIEL"<<endl;
		} else {
			cout<<"Case #"<<t<<": RICHARD"<<endl;
		}
	}
	return 0;
}
