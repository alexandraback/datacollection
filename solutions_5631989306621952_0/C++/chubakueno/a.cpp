#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main(){
	int t;
	cin>>t;
	for(int z=1;z<=t;++z){
		string str;
		cin>>str;
		int n=str.length();
		vector<char> res;
		for(int i=0;i<(1<<n);++i){
			vector<char> vec;
			for(int j=0;j<n;++j){
				if(i&(1<<j))
					vec.push_back(str[j]);
				else
					vec.insert(vec.begin(),str[j]);
			}
			if(res.size()==0||res<vec) res=vec;
		}
		char ans[20];
		memset(ans,0,sizeof ans);
		for(int i=0;i<n;++i)
			ans[i]=res[i];
		printf("Case #%d: %s\n",z,ans);
	}
}