#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long Long;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1; tc <= TC; ++tc){
		int N;
		cin >> N;
		set<int> S;
		for(int i = 0; i < 2*N*N-N; ++i){
			int n;
			cin >> n;
			if(S.count(n))
				S.erase(n);
			else
				S.insert(n);
		}
		vector<int> V(S.begin(),S.end());
		cout << "Case #" << tc << ": ";
		for(int i = 0; i < V.size(); ++i){
			cout << V[i] << " ";
		}
		cout << endl;
	}
}


/*
 ######
 ######
 ######
 ######
*/
