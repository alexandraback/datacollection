#include<bits/stdc++.h>
using namespace std;
void eval(){
	int n,x;
	cin>>n;
	map<int,int> mp;
	for(int i=0;i<2*n-1;i++){
		for(int j=0;j<n;j++){
			cin>>x;
			mp[x]++;
		}
	}
	for(map<int,int>::iterator it = mp.begin();it!=mp.end();it++){
		if(it->second%2==1)
			cout<<it->first<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(int te=1;te<=t;te++){
		cout<<"Case #"<<te<<": ";
		eval();
	}
}
