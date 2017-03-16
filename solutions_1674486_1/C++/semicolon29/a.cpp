#include<cstring>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1010][15],m[1010],f;
bool vis[1010];
vector<int> v;
map<pair<int,int> , int>mp;
void explore(int i){
//	cout<<i<<endl;
	vis[i]=true;
	int j,k;
	for(j=0;j<m[i];j++){
//		cout<<"  "<<a[i][j]<<endl;
		for(k=0;k<v.size();k++){
			mp[make_pair(v[k],a[i][j])]++;
			if(mp[make_pair(v[k],a[i][j])]==2)
				f=1;
		}
		if(!vis[a[i][j]]){
//			cout<<i<<" "<<a[i][j]<<endl;
			v.push_back(a[i][j]);
			explore(a[i][j]);
		}
	}
}
int main(){
	int t,cs;
	cin>>t;
	for(cs=1;cs<=t;cs++){
		int n,i,j;
		cin>>n;
		f=0;
		memset(a,0,sizeof a);
		memset(vis,false,sizeof vis);
		memset(m,0,sizeof m);
		mp.clear();
//		for(i=1;i<=n;i++){
//			for(j=1;j<=n;j++)
//				cout<<a[i][j]<<" ";
//			cout<<endl;
//		}
		for(i=1;i<=n;i++){
			cin>>m[i];
			for(j=0;j<m[i];j++){
				cin>>a[i][j];
			}
		}
		printf("Case #%d: ",cs);
		for(i=1;i<=n;i++){
			if(!vis[i]){
				v.push_back(i);
				explore(i);
//				for(j=0;j<v.size();j++)
//					cout<<v[j]<<" ";
//				cout<<endl;
				memset(vis,false,sizeof vis);
				mp.clear();
				if(f==1){
					cout<<"Yes\n";
					break;
				}
				v.clear();
			}
		}
		if(f==0)
			cout<<"No\n";
	}
	return 0;
}
