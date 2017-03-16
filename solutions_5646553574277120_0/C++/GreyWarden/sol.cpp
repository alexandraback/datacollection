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

vector <int> d;
int c;

bool cal(int cur, int at, int v){
	if(cur == v)
		return true;
	if(cur > v)
		return false;
	if(at >= d.size())
		return false;
	for(int i = 0; i <= c; i++){
		if(cal(cur, at+1, v))
			return true;
		cur += d[at];
	}
	return false;
}

int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("answer.out", "w", stdout);
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++){
		int C,D,V;
		cin>>C>>D>>V;
		c = C;
		d.clear();
		for(int i = 0; i < D; i++){
			int num;
			cin>>num;
			d.push_back(num);
		}
		int res = 0;
		sort(d.begin(), d.end());
		for(int i = 1; i <= V; i++)
			if(!cal(0,0,i)){
				d.push_back(i);
				sort(d.begin(), d.end());
				res++;
			}
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}
