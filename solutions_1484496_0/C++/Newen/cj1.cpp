// cj1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t ; i++){
		int n = 0;
		cin >> n;
		int sum = 0;
		vector<long long int> ints;
		for(int j = 0; j< n;j++){
			int tmp = 0;
			cin >> tmp;
			ints.push_back(tmp);
		}
		cout << "Case #" << i+1 << ":" << endl;
		auto map = hash_map<long long int,vector<long long int> >();
		bool suc = false;
		for (int q = 0; q< 1 << 20;q++){
			long long int sum = 0;
			vector<long long int> set;
			for (int k = 0; k < ints.size();k ++){
				if(q & (1<<k)){
					sum += ints[k];
					set.push_back(ints[k]);
				}
				
			}
			if(map.find(sum) != map.end()){
				for (int e = 0;e < map[sum].size();e ++){
					cout << map[sum][e] << " ";
				}
				cout << endl;
				for (int e = 0;e < set.size();e ++){
					cout << set[e] << " ";
				}
				cout << endl;
				suc = true;
				break;
			}
			else{
				map[sum] = set;
			}
		}
		
		if(!suc)
			cout << "Impossible" << endl;
	}
	return 0;
}

