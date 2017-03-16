#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int testcase = 0;
int BFF[11];
int ans = 0;
int n;
int zz = 0;

void check(vector <int> v){
	bool iscorrect = true;
	int len = v.size();
	bool satisfied[10] = {};
	for(int i = 0; i<len; i++){
		if(BFF[v[i]]==v[(i+1)%len] || BFF[v[i]] == v[(i-1+len)%len]){
			satisfied[v[i]] = true;
		}else{
			iscorrect = false;
			break;
		}
	}
	if(iscorrect) ans = max(ans,len);
}

void solve(){
	testcase++;
	ans = 0;
	cin>>n;
	int z;
	for(int i = 0; i<n; i++){
		cin>>z;
		z--;
		BFF[i] = z;
	}
	for(int i = 1; i<(1<<n); i++){
		vector <int> v;
		for(int j = 0; j<n; j++) if(i & (1<<j)) v.push_back(j);
		sort(v.begin(),v.end());
		do{
			check(v);
		}while(next_permutation(v.begin(),v.end()));
		if(ans==n) break;
	}
	cout<<"Case #"<<testcase<<": "<<ans<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}