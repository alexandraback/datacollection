#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("answer.out", "w", stdout);
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++){
		int r,c,w;
		cin>>r>>c>>w;
		int res = (c/w) * r + w;
		if(c % w == 0)
			res--;
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}
