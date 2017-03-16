#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
#define Author "DemoVersion"
int dx[]={0,0,-1,1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,1,-1,-1};
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
int mp[10][10];
int visited[10][10];
int ym,xm,counter;
void dfs(int j,int i){
	int k;
	counter++;
	visited[j][i]=1;
	if(mp[j][i]>0)return;
	for(k=0;k<8;k++){
		if(i+dx[k]<0||i+dx[k]>=xm)continue;
		if(j+dy[k]<0||j+dy[k]>=ym)continue;
		if(visited[j+dy[k]][i+dx[k]])continue;
		dfs(j+dy[k],i+dx[k]);
	}
}

int main(){
        ios_base::sync_with_stdio(0);
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
	double A[1047],B[1047];
	int n,t,z,i,p1,p2,L,W;
	cin>>t;
	for(z=1;z<=t;z++){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>A[i];
		}
		for(i=0;i<n;i++){
			cin>>B[i];
		}
		sort(A,A+n);
		sort(B,B+n);
		p1=p2=n-1;
		L=0;
		while(p2>=0){
			if(A[p1]>B[p2]){
				p1--;
				p2--;
			}else{
				p2--;
				L++;
			}
		}
		W=0;
		p1=p2=n-1;
		while(p1>=0){
			if(B[p2]>A[p1]){
				p2--;
				p1--;
			}else{
				p1--;
				W++;
			}

		}

		cout<<"Case #"<<z<<": "<<n-L<<" "<<W<<endl;
	}
	return 0;
}
