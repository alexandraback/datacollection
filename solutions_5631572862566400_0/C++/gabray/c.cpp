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

vector<int> z;
int maxi = 0;
int n;

bool dasa(vector<int> m){
	set<int> s;
	for(auto x: m) s.insert(x);
	vector<bool> vid((int)m.size(), false);
	vector<int> res;
//	cout << "msize = " << m.size() << endl;
	for(int i = 0; i < m.size(); i++){
		if(vid[m[i]]) continue;

		int k = m[i];
	//	cout << "k = " << k << endl;
		while(s.find(k) != s.end() && !vid[k]){
	//		cout << "ide\n";
			vid[k] = true;
			res.push_back(k);
			k = z[k];
	//		cout << "k = " << k << endl;
		}
	}
	res.push_back(m[0]); 
	//cout << "res: "; 	for(auto x: res) cout << x << " "; cout << endl;

	if(res[1] != z[res[0]] && res[res.size() - 2] != z[res[0]]) return false;
	for(int i = 1; i < res.size() - 1; i++){
		if(res[i-1] != z[res[i]] && res[i+1] != z[res[i]]){
	//		cout << "neni " << res[i] << endl;
			return false;
		}
	}
//	cout << "dasa\n";
	return true;
}

void go(int k, vector<int> m){
	//test
//	cout << "m = "; for(auto x: m) cout << x << " "; cout << endl;
	if((int)m.size() > maxi && dasa(m)){
		maxi = m.size();
//		cout << "nove maxi = " << maxi << endl;
	} 

	if(k < n){
		vector<int> f;
		f = m;
		f.push_back(k);
		go(k+1, f);
		go(k+1, m);
	}
}

void solve(int T){
	cin >> n;
	z.resize(n);
	maxi = 0;
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		z[i] = x-1;
	}

//	cout << "z: "; for(auto ff: z) cout << ff << " "; cout << endl;

	vector<int> r;
	go(0, r);	

	cout << "Case #" << T << ": ";
	cout << maxi << endl;
}

int main(){
	int T;
	cin >> T;
	For(t, T) solve(t+1);
	return 0;
}
