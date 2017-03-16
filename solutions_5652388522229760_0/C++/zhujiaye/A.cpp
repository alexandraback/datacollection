#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int Q,N;
bool vis[15];
int main(){
	freopen("i.txt","r",stdin);
	cin>>Q;
	for (int testcase=1;Q--;testcase++){
		cin>>N;
		cout<<"Case #"<<testcase<<": ";
		if (!N){
			cout<<"INSOMNIA"<<endl;
			continue;
		}
		memset(vis,0,sizeof(vis));
		int cnt=0;
		int tmp=N;
		for (;;){
			for (int x=tmp;x;x/=10){
				int v=x%10;
				if (!vis[v]){
					vis[v]=true;
					cnt++;
				}
			}
			if (cnt==10)
				break;
			tmp+=N;
		}
		cout<<tmp<<endl;
	}
	return 0;
}
