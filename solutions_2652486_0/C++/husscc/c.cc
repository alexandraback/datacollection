#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unordered_map<int, unordered_map<int, int> >::iterator MMITR;
typedef unordered_map<int, int>::iterator MITR;

int T, R, N, M, K;
unordered_map<int, int> subset[100];
unordered_map<int, unordered_map<int, int> > list;

unordered_map<int, int> make(vector<int> &v){
	unordered_map<int, int> ret;
	ret[1]++;
	ret[v[0]]++; ret[v[1]]++; ret[v[2]]++;
	ret[v[0]*v[1]]++; ret[v[0]*v[2]]++;
	ret[v[1]*v[2]]++;
	ret[v[0]*v[1]*v[2]]++;
	return ret;
}

void proprecess(){
	vector<int> v(3, 0);
	for(int i = 2; i <= 5; i++){
		for(int j = 2; j <= 5; j++){
			for(int k = 2; k <= 5; k++){
				v[0] = i, v[1] = j, v[2] = k;
				sort(v.begin(), v.end());
				int num = v[0]*100+v[1]*10+v[2];
				//cout<<num<<endl;
				if(list.count(num)) continue;
				list[num] = make(v);
			}
		}
	}
}

void work(){
	/*
	for(MMITR itr = list.begin(); itr != list.end(); itr++){
		cout<<itr->first<<" : "<<endl;
		for(MITR itr1 = itr->second.begin(); itr1 != itr->second.end(); itr1++)
			cout<<itr1->first<<" : "<<itr1->second<<"; ";
		cout<<endl;
	}*/

	for(int i = 0; i < R; i++){
		int match = 0, idx = 222, tmp;
		for(MMITR itr = list.begin(); itr != list.end(); itr++){
			tmp = 0;
			for(MITR itr1 = subset[i].begin(); itr1 != subset[i].end(); itr1++){
				if((itr->second).count(itr1->first) == 0)
					continue;
				int num = itr1->first;
				tmp += min(subset[i][num], (itr->second)[num]);
			}
			if(tmp > match){
				match = tmp; idx = itr->first;
			}
		}
		cout<<idx<<endl;
	}
}

int main(){
	cin>>T>>R>>N>>M>>K;
	int t;
	proprecess();
	cout<<"Case #1:"<<endl;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < K ; j++){
			cin>>t;
			subset[i][t]++;
		}
	}
	work();
}