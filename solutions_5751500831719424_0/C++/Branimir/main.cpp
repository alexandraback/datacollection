#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
	int t;
	cin >> t;
	for(int caso = 1; caso <= t; caso++){
		int n;
		cin >> n;
		vector<string> v, v2;
		vector<vector<int> > v3;
		bool haysol = true;
		for(int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			v.push_back(tmp);
			string tmp2;
			tmp2.push_back(tmp[0]);
			for(int j = 1; j < tmp.size(); j++){
				if(tmp[j] != tmp2[tmp2.size() - 1])
					tmp2.push_back(tmp[j]);
			}
			v2.push_back(tmp2);

			int k = 0;
			vector<int> cont;
			while(k < tmp.size()){
				int l = k;
				while(l < tmp.size() && tmp[l] == tmp[k])
					l++;
				cont.push_back(l - k);
				k = l;
			}
			v3.push_back(cont);

			if(i && haysol)
				haysol = (v2[i] == v2[i - 1]);
		}
		if(haysol){
			int ans = 0;
			for(int j = 0; j < v3[0].size(); j++){
				int minimo = INT_MAX;
				for(int obj = 1; obj <= 100; obj++){
					int sum = 0;
					for(int i = 0; i < n; i++)
						sum += abs(v3[i][j] - obj);
					minimo = min(minimo, sum);
				}
				ans += minimo;
			}
			printf("Case #%d: %d\n", caso, ans);
		}else{
			printf("Case #%d: Fegla Won\n", caso);
		}
	}
	return 0;
}
