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
		deque<char> res;
		res.push_front(str[0]);
		for(int i=1;i<n;++i){
			deque<char> tmp=res;
			tmp.push_front(str[i]);
			if(res<tmp) res.push_front(str[i]); 
			else res.push_back(str[i]);
		}
		char ans[1005];
		memset(ans,0,sizeof ans);
		for(int i=0;i<res.size();++i)
			ans[i]=res[i];
		printf("Case #%d: %s\n",z,ans);
	}
}