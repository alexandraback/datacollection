#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<numeric>
using namespace std;
int a[201],dp[201][201];
vector<int>v[201];
void slove(int x,vector<int> &w){
	for(int i=max(0,(x-4)/3);i<=x/3;i++){
		for(int j=i;j-i<=2;j++){
			for(int k=j;k-j<=2&&k<=10;k++){
				if(i+j+k==x&&k-i<=2){
					w.push_back(i+11*j+121*k);
					//if(k-i==2)cout<<"surprising! ";
					//cout<<"i="<<i<<" j="<<j<<" k="<<k<<" x="<<x<<endl;
					}
				}
			}
		}
	}
int main(){
	int T;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int ca=1;ca<=T;ca++){
		int N,S,P;
		cin>>N>>S>>P;
		for(int i=1;i<=N;i++){cin>>a[i];v[i].clear();slove(a[i],v[i]);}
		for(int i=0;i<=N;i++)for(int j=0;j<=S;j++)dp[i][j]=0;
		dp[0][0]=0;
		for(int i=1;i<=N;i++){
			for(int j=S;j>=0;j--){
				for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it){
					int x=*it%11,y=*it/11%11,z=*it/121,sup=0,big=0;
					if(x>=P||y>=P||z>=P)big=1;
					if(z-x==2)sup=1;
					if(j-sup>=0){
						dp[i][j]=max(dp[i][j],dp[i-1][j-sup]+big);
						}
					//cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
					}
				
				}
			}
		cout<<"Case #"<<ca<<": "<<dp[N][S]<<endl;
		}
    return 0;
    }
