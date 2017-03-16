#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int main(){
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int t;
	cin >> t;
	int cas = 1;
	int k, c, s;
	while (t--){
		v.clear();
		cin >> k >> c >> s;
		printf("Case #%d:",cas++);
		if (c == 1){
			if (s < k){
				printf(" IMPOSSIBLE\n");
			}
			else{
				for (int j = 0; j < k; j++)
				{
					printf(" %d",j+1);
				}
				printf("\n");
			}
		}
		else{
			int num = k / 2;
			int tmp = k;
			for (int i = 0; i < num; i++){
				v.push_back(tmp-i);
				tmp += k;
			}
			if (k & 1){
				v.push_back((k+1)/2);
			}
			if (v.size() > s){
				printf(" IMPOSSIBLE\n");
			}
			else{
				for (int j = 0; j < v.size(); j++)
					printf(" %d",v[j]);
				printf("\n");
			}
		}
	}
	return 0;
}