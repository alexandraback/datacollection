#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>

using namespace std;

#define For(i, po) for(int (i) = 0; (i) < (po); i++)
#define MAXI 1000000009
typedef long long ll;
typedef pair<int,int> pii;

void solve(int T){
	int n, x;
	cin >> n;
	vector<int> v(3000, 0);
	For(i, n*2 - 1)
		For(j, n){
			cin >> x;
			v[x] ++;
		}

	vector<int> res;
	for(int i = 0; i < v.size(); i++){
		if(v[i] % 2 == 1) res.push_back(i);
	}	
	sort(v.begin(), v.end());

	cout << "Case 	#" << T << ":";
	for(auto y: res) cout << " " << y; cout << endl;
}

int main(){
	int T;
	cin >> T;
	For(t, T) solve(t+1);
	return 0;
}
