#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

pair<int, int> data[2000];
bool flag[10000];
std::priority_queue<int, std::vector<int>, greater<int> > Q;

int main(){
//	freopen("in.txt" , "r" , stdin);
//	freopen("out.txt" , "w" , stdout);
	int t;
	scanf("%d" , &t);
	for(int ii = 1;ii <= t;ii++){
		int ret = 0;
		int n;
		memset(flag, false, sizeof(flag));
		scanf("%d" , &n);
		int i;
		for(i = 0;i < n;i++){
			scanf("%d%d" , &data[i].first, &data[i].second);
		}
		while(!Q.empty()) Q.pop();
		sort(data, data + n);
		int p = 0;
		while(ret < 2 * n){
			int k1 = -1;
			int k2 = -1;
			for(i = 0;i < n;i++){
				if(flag[i]) continue;
				if(data[i].first <= ret){
					if(k1 == -1) k1 = i;
					else if(data[i].second > data[k1].second) k1 = i;
					if(data[i].second <= ret){
						k2 = i;
					}
				}
			}
			if(k2 != -1){
				flag[k2] = true;
				ret += 2;
				p++;
			}else if(k1 != -1){
				flag[k1] = true;
				ret += 1;
				p++;
				Q.push(data[k1].second);
			}else{
				break;
			}

			while(!Q.empty()){
				if(Q.top() <= ret){
					ret++;
					p++;
					Q.pop();
				}else{
					break;
				}
			}
		}
		if(ret < 2 * n){
			printf("Case #%d: Too Bad\n", ii);
		}else{
			printf("Case #%d: %d\n", ii, p);
		}
	}
	return 0;
}