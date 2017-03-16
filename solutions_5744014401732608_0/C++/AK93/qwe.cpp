#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

void gen(){
	freopen("testcase.txt", "w", stdout);
	exit(0);
}

int main(){

#ifdef _CONSOLE
	freopen("B-small-attempt0.in", "r", stdin);
	//freopen("testcase.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int countTest;
	cin>>countTest;	
	for(int test = 1; test <= countTest; test++){
		ll n, m;
		cin>>n>>m;

		ll k = n - 2;
		k = 1LL << k;

		if(k < m){
			printf("Case #%d: IMPOSSIBLE\n", test);
			continue;
		}

		vector<vector<int> > res(n, vector<int> (n, 0));

		for(int i=1; i<n; i++){
			for(int j=i+1; j<n; j++){
				res[i][j] = 1;
			}
		}
		m--;
		res[0][n-1] = 1;
		int ptr = n-2;
		while(m){
			if(m % 2 == 1){
				res[0][ptr] = 1;
			}
			m /= 2;
			ptr--;
		}

		printf("Case #%d: POSSIBLE\n", test);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<res[i][j];
			}
			cout<<"\n";
		}
	}
	
	return 0;
}

