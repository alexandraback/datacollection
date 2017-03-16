#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<utility>
#include<fstream>
using namespace std;
string getBinary(long long val){
	string ret;
	while(val != 0){
		ret += ('0' + (val&1));
		val /= 2;
	}
	return ret;
}
int main()
{
	int t;
	cin >> t;
	for(int z = 1; z <= t; ++ z){
		cout << "Case #" << z << ": ";
		int b;
		long long m;
		cin >> b >> m;
		long long mx = 0, mult = 1;
		for(int i = 0; i < b - 2; ++ i){
			mx += mult;
			mult *= 2;
		}
		mult /= 2;
		mx ++;
		if(mx < m){
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		cout << "POSSIBLE" << endl;
		string bin = getBinary(m);
		vector<vector<int>> ret(b, vector<int>(b, 0));
		long long greatestPower = 1;
		for(int i = 0; i < b - 2; ++ i){
			if(m >= mult){
				ret[0][i+1] = 1;
				//cout << i << ' ' 
				for(int j = i; j < b - 1; ++ j){
					for(int k = j + 1; k < b-1; ++ k)
						ret[j+1][k+1] = 1;
				}
				m -= mult;
			}
			mult/= 2;
		}
		if(m == 1)
			ret[0][b-1] = 1;
		for(int i = 0; i < b; ++ i){
			for(int j = 0; j < b; ++ j)
				cout << ret[i][j];
			cout << endl;
		}
	}
	return 0;
}