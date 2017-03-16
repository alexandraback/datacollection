#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <map>
#define MOD 1000000007
using namespace std;

int main() {
	int T,n,res,x;
	bool cek,used[35];
	vector<string> cars;
	set<string> counter;
	map<string,int> check;
	char cur;
	string s;
	scanf("%d",&T);
	for(int z=1;z<=T;z++) {
		cars.clear();
		scanf("%d",&n);
		check.clear();
		counter.clear();
		for(int a=0;a<n;a++) {
			cin >> s;
			check[s]++;
			cars.push_back(s);
		}
		res = 0;
		memset(used,false,sizeof(used));
		cur = cars[0][0];
		cek = true;
		for(int a=0;a<n;a++) {
			for(int b=0;b<cars[a].size();b++) {
				if(cur!=cars[a][b]) {
					used[cur-'a'] = true;
					if(used[cars[a][b]-'a']) {
						cek = false;
						break;
					}
					cur = cars[a][b];
				}
			}
			if(!cek) break;
		}
		if(cek) res++;
		while(next_permutation(cars.begin(),cars.end())) {
			memset(used,false,sizeof(used));
			cur = cars[0][0];
			cek = true;
			for(int a=0;a<n;a++) {
				for(int b=0;b<cars[a].size();b++) {
					if(cur!=cars[a][b]) {
						used[cur-'a'] = true;
						if(used[cars[a][b]-'a']) {
							cek = false;
							break;
						}
						cur = cars[a][b];
					}
				}
				if(!cek) break;
			}
			if(cek) res++;
		}
		res %= MOD;
		for(int a=0;a<n;a++) {
			if(counter.count(cars[a])==0) {
				x = check[cars[a]];
				for(int b=2;b<=x;b++) res = (res*b)%MOD;
				counter.insert(cars[a]);
			}
		}
		printf("Case #%d: %d\n",z,res);
	}
	return 0;
}
