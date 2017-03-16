#include<string>
#include<fstream>
//#include<iostream>
#include<algorithm>
using namespace std;

ifstream cin("B-large.in");
ofstream cout("mik.txt");

int main(){
	int T; cin>>T;
	for(int t=1;t<=T;t++){
		int N,M,G[100][100],R[100]={0},C[100]={0};
		cin>>N>>M;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>G[i][j];
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				R[i]=max(R[i],G[i][j]);
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				C[i]=max(C[i],G[j][i]);

		bool valid=true;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(G[i][j]<R[i])
					for(int k=0;k<N;k++)
						if(G[k][j]>G[i][j]){
							valid=false;
							//cout<<"G["<<k<<"]["<<j<<"] is larger than G["<<i<<"]["<<j<<"]"<<endl;
						}
				if(G[i][j]<C[j]){
					for(int k=0;k<M;k++){
						if(G[i][k]>G[i][j]){
							valid=false;
							//cout<<"G["<<i<<"]["<<k<<"] is larger than G["<<i<<"]["<<j<<"]"<<endl;
						}
					}
				}
			}
		}
		string result=valid?"YES":"NO";
		cout<<"Case #"<<t<<": "<<result<<endl;
	}
}