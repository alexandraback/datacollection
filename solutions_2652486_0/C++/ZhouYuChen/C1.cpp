#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,vector<int> > > tmp;
int main(){
	cout << "Case #1:"<< endl;
	int T,r,n,m,k;cin>>T;
	cin >> r >> n >> m >> k;
	int a[3];
	for(a[0]=2;a[0]<=m;++a[0])
	for(a[1]=2;a[1]<=m;++a[1])
	for(a[2]=2;a[2]<=m;++a[2]){
		int f[8]={1};
		for(int i=1;i<8;++i){
			int h = i&-i;
			f[i]=f[i^h]*a[__builtin_ctz(h)];
		}
		tmp.push_back(make_pair(a[0]*100+a[1]*10+a[2],vector<int>(f,f+8)));
	}
	random_shuffle(tmp.begin(),tmp.end());
	for(;r--;){
		int g[12];
		for(int i=0;i<k;++i)cin >> g[i];
		bool ok;
		for(auto h:tmp){
			vector<int> const &set=h.second;
			ok =true;
			for(int i=0;i<k && ok;++i)
			if(find(set.begin(),set.end(),g[i])==set.end())ok = false;
			if(ok){
				int a=h.first;
				cout << a/100 << a/10%10 << a%10 << endl;
				break;
			}
		}
		if(!ok)puts("123");
	}
}
