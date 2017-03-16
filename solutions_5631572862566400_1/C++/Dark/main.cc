#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
int like[1555];
int back[1555];
int ans;
int len2pairs;
void dfs(int start){
	int mark[1555]={};
	int cur = start;
	int len = 0;
	int last;
	while(!mark[cur]){
		last = cur;
		mark[cur] = 1;
		cur = like[cur];
		len++;
	}
	if(cur == start){
		//circle
		ans = max(ans, len);
		if(len == 2){
			back[last] = max(back[last], len);
			len2pairs++;
			// cout << "Pair: " << last << " " << start << endl;
		}
	}
	else if(like[like[last]] == last){
		back[last] = max(back[last], len);
		//cout << "back " << last << " len " << len << endl;
	}
}
int main(){
	int T;
	cin >> T;
	for(int _=1;_<=T;_++){
		printf("Case #%d: ",_);
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> like[i];
			like[i]--;
			back[i] = 0;
		}
		ans = 0;
		int chain = 0;
		len2pairs = 0;
		for(int i=0;i<n;i++){
			dfs(i);
		}
		for(int i=0;i<n;i++){
			if(back[i]){
				int j = like[i];
				chain += back[i] + back[j] - 2 - 2;
			}
		}
		chain /= 2;
		chain += len2pairs;
		ans = max(ans, chain);
		cout << ans << endl;
	}
	return 0;
}