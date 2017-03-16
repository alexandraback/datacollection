#include <iostream>
#include <map>
#include <set>

using namespace std;

int testcase = 0;
int n;

void solve(){
	testcase++;
	cin>>n;
	map <int,int> mp;
	set <int> ms;
	int z;
	for(int i = 0; i<2*n-1; i++){
		for(int j = 0; j<n; j++){
			cin>>z;
			mp[z]++;
		}
	}
	map <int, int> :: iterator it;
	for(it = mp.begin(); it != mp.end(); it++){
		if(it->second%2) ms.insert(it->first);
	}
	cout<<"Case #"<<testcase<<": ";
	set <int> :: iterator ij;
	for(ij = ms.begin(); ij != ms.end(); ij++){
		cout<<*ij<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}