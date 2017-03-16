#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;++z){
		int n;
		cin>>n;
		vector<int> vec;
		int cnt[2505];
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<2*n-1;++i){
			for(int j=0;j<n;++j){
				int x;
				cin>>x;
				++cnt[x];
			}
		}
		for(int i=0;i<2505;++i){
			if(cnt[i]%2==1){
				vec.push_back(i);
			}
		}
		printf("Case #%d:",z);
		for(int i=0;i<vec.size();++i)
			printf(" %d",vec[i]);
		printf("\n");
		if(n!=vec.size()){
			printf("NOOOOOOOOO\n\n");
		}
	}
}