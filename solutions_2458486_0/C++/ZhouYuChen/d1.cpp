#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sol[1<<20];
int main(){
	int tc =1,T;
	for(cin >> T;tc<=T;++tc){
		vector<int> v[20],k;
		int k0,n,o[20];
		cin >>k0>> n;
		for(int x;k0--;k.push_back(x))cin >> x;
		for(int i=0,c;i<n;++i){
			cin >>o[i] >> c;
			for(int x;c--;v[i].push_back(x))
				cin >> x;
		}
		bitset<1<<20> r;
		r.set(0);
		for(int i=0;i<1<<n;++i)sol[i].clear();
		for(int z=0;z<1<<n;++z)
		if(r[z]){
			vector<int> x(k);
			for(int i=0;i<n;++i)
			if(z>>i&1)x.insert(x.end(),v[i].begin(),v[i].end());
			for(int i=0;i<n;++i)
			if(z>>i&1)(*find(x.begin(),x.end(),o[i]))=0;
			for(int i=0;i<n;++i)
			if(!(z>>i&1)&&(find(x.begin(),x.end(),o[i])!=x.end())){
				r.set(z|1<<i);
				sol[z].push_back(i);
				if(sol[z|1<<i].size()==0 || sol[z]<sol[z|1<<i])
					sol[z|1<<i]=sol[z];
				sol[z].pop_back();
			}
		}
		cout << "Case #"<<tc<<":";
		if(!r[(1<<n)-1]){
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		vector<int> &ans=sol[(1<<n)-1];
		for(int i=0;i<n;++i)cout <<" "<<1+ans[i];
		cout << endl;
	}
}
