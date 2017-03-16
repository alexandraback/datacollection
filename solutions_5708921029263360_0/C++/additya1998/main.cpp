#include "bits/stdc++.h"
using namespace std;
const int N = 50;
int t;
int j , p , s , k;
int tc = 0;
vector < pair < int , pair < int , int > > > v;
int main(){
	cin >> t;
	while(t--){
		cin >> j >> p >> s >> k;
		v.clear();
		for(int x = 1 ; x <= j ; ++x){
			for(int y = 1 ; y <= p ; ++y){
				for(int z = 1 ; z <= s ; ++z){
					v.emplace_back(make_pair(x , make_pair(y , z)));
				}
			}
		}
		vector < int > ans;
		ans.clear();
		srand(time(NULL));
		int p = 1 << (v.size());
		int cnt = 0;
		while(cnt <= 1000000){
			++cnt;
			int x = rand() % p;
			if(__builtin_popcount(x) <= ans.size()){
				continue;
			}
			vector < int > tmp;
			map < pair < int , int > , int > mp1;
			map < pair < int , int > , int > mp2;
			map < pair < int , int > , int > mp3;
			mp1.clear();
			mp2.clear();
			mp3.clear();
			for(int i = 0 ; i < v.size() ; ++i){
				if(x & (1 << i)){
					tmp.emplace_back(i);
					++mp1[make_pair(v[i].first , v[i].second.first)];
					++mp2[make_pair(v[i].first , v[i].second.second)];
					++mp3[v[i].second];
				}
			}
			bool rekt = 0;
			for(auto it : mp1){
				if(it.second > k){
					rekt = 1;
				}
			}
			for(auto it : mp2){
				if(it.second > k){
					rekt = 1;
				}
			}
			for(auto it : mp3){
				if(it.second > k){
					rekt = 1;
				}
			}
			if(!rekt){
				if(tmp.size() > ans.size()){
					ans = tmp;
				}
			}
		}
		printf("Case #%d: " , ++tc);
		printf("%d\n" , int(ans.size()));
		for(int it : ans){
			printf("%d %d %d\n" , v[it].first , v[it].second.first , v[it].second.second);
		}
	}
}