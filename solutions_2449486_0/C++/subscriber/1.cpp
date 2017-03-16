#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int a[111][111],b[111][111],n,m;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int E=1;E<=T;E++){
		cin >> n>> m;
		for (int i=0;i<n;i++)for (int j=0;j<m;j++)scanf("%d",&a[i][j]);
		string ans="YES";
		for (int g=1;g<100;g++){
			for (int i=0;i<n;i++)for (int j=0;j<m;j++)b[i][j]=0;
			for (int i=0;i<n;i++){
				int t=0;
				for (int j=0;j<m;j++)if (a[i][j]>g)t=1;
				if (t==0)for (int j=0;j<m;j++)a[i][j]=-1;
			}
			for (int i=0;i<m;i++){
				int t=0;
				for (int j=0;j<n;j++)if (a[j][i]>g)t=1;
				if (t==0)for (int j=0;j<n;j++)a[j][i]=-1;
			}
			for (int i=0;i<n;i++)for (int j=0;j<m;j++)if (a[i][j]==g)ans="NO";
		}
		cout << "Case #" << E << ": " << ans << endl;
	}
	return 0;
}


