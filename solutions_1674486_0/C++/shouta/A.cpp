#include<iostream>
#include<queue>

using namespace std;

int F[1001];
int G[1001][1001];

int main(){
	
	int T;
	cin>>T;
	for(int tc=1;tc<=T;tc++){
		int N,M;
		cin>>N;
		
		for(int i=0;i<=N;i++)
			for(int j=0;j<=N;j++)
				G[i][j]=0;
		bool flag=false;
		for(int i=1;i<=N;i++){
			cin>>M;
			for(int j=0;j<M;j++){
				int d;
				cin>>d;
				G[i][d]=1;
			}
		}
		
		for(int i=1;i<=N&&!flag;i++){
			for(int j=1;j<=N;j++)
				F[j]=0;
			queue<int> qd;
			qd.push(i);
			//not cycle
			
			F[i]=1;
			
			while(!qd.empty()&&!flag){
				int d=qd.front();
				qd.pop();
				for(int j=1;j<=N;j++){
					if(G[d][j]==1){
						if(F[j]==0){
							qd.push(j);
							F[j]=1;
						}else{
							flag=true;
						}
					}
				}
			}
			
		}
		cout<<"Case #"<<tc<<": ";
		if(flag)cout<<"Yes";
		else cout<<"No";
		cout<<endl;
		
	}
	return 0;
}
