#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0;i < t;++i){
		int n;
		cin >> n;
		int inherit[n][n];

		for(int a = 0;a < n;++a)
			for(int b = 0;b < n;++b)
				inherit[a][b] = 0;
		
		for(int j = 0;j < n;++j){
			int a;
			cin >> a;
			for(int k = 0;k < a;++k){
				int b;
				cin >> b;
				inherit[j][b-1] = 1;
			}
		}
		for(int c = 0;c < n;++c)
			for(int a = 0;a < n;++a)
				for(int b = 0;b < n;++b){
					inherit[a][b] += inherit[a][c] * inherit[c][b];
				}
		
		bool diamond = false;
		bool end = false;
		for(int a = 0;a < n && !end;++a)
			for(int b = 0;b < n;++b){
				if(inherit[a][b] >= 2){
					diamond = true;
					end = true;
					break;
				}
			}		
			
		cout << "Case #" << (i+1) << ": ";
		if(diamond) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
