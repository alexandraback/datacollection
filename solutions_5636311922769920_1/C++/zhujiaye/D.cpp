#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

typedef long long LL;
int Q,K,C,S;
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cout<<"Case #"<<testcase<<": ";
		cin>>K>>C>>S;
		vector<LL>res;
		vector<bool>used(K+1,false);
		for (int i=1;i<=K;i++){
			if (used[i]) continue;
			int now=i;
			LL pos=i;
			for (int j=1;j<=C;j++,now=min(now+1,K),pos=(pos-1)*K+now){
			//	cout<<"pos:"<<pos<<"now:"<<now<<endl;
				used[now]=true;
				if (j==C)
					res.push_back(pos);
			}
		}
		if (res.size()>S)
			cout<<"IMPOSSIBLE"<<endl;
		else{
			for (int i=0;i<res.size();i++){
				if (i>0)
					cout<<" ";
				cout<<res[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
