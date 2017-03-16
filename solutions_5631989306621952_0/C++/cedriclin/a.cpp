#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
#include <complex>

using namespace std;
typedef long long ll;
typedef double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

char deq[1<<12];

bool go_first(int start, int end, char c){
	for (int curr = start; curr < end; curr++){
		if (deq[curr] < c) return true;
		if (deq[curr] > c) return false;
	}
	return false;
}

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		string s; cin >> s;
		memset(deq,0,sizeof(deq));
		int start = s.length();
		for (int i = 0; i < s.length(); i++){
			char c = s[i];
			bool first = go_first(start,start+i,c);
			if (first){
				start--;
				deq[start] = c;
			}
			else{
				deq[start+i] = c;
			}
		}
		cout << "Case #" << zz << ": ";
		for (int i = start; i < start + s.length(); i++)
			cout << deq[i];
		cout << endl;
	}
	
	return 0;
}
