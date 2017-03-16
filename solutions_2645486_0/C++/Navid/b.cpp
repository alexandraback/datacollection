#include<iostream>
#include<string>
using namespace std;

const int maxe = 10;
const int maxn = 20;

int ans[maxn][maxe];
int in[maxn];

int main() {
	int t;
	cin>>t;
	for(int tn=0;tn<t;tn++) {
		memset(ans,0,sizeof ans);
		int e,r,n;
		cin>>e>>r>>n;
		for(int i=0;i<n;i++)
			cin>>in[i];
		for(int i=n-1;i>=0;i--)
			for(int j=0;j<=e;j++) {
				ans[i][j] = ans[i+1][min(e,j+r)];
				for(int h=0;h<=j;h++)
					ans[i][j] = max(ans[i][j], h*in[i] + ans[i+1][min(e,j-h+r)]);
			}
		cout<<"Case #"<<tn+1<<": "<<ans[0][e]<<endl;
	}
}

