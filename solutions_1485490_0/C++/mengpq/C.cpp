#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=300;
const int INF=0x7FFFFFFF;
const double eps=1e-8;
const double pi=acos(-1.0);

struct data{
	long long x,y;
};

int n,m,ca;
data FA[MAXN], FB[MAXN];
long long Bsum[MAXN][MAXN],Asum[MAXN][MAXN],f[MAXN][MAXN];


void init(){
	cin>>n>>m;
	memset(Asum,0,sizeof(Asum));
	int MAX=100;
	for(int i=1; i<=n; i++){
		cin>>FA[i].x>>FA[i].y;
		for (int j=1; j<=MAX; j++) Asum[j][i]=Asum[j][i-1];
		Asum[FA[i].y][i]+=FA[i].x;
	}
	memset(Bsum,0,sizeof(Bsum));
	for(int i=1; i<=m; i++){
		cin>>FB[i].x>>FB[i].y;
		for (int j=1; j<=100; j++)
			Bsum[j][i]=Bsum[j][i - 1];
		Bsum[FB[i].y][i]+=FB[i].x;
	}
}

void solve(){
	memset(f,0,sizeof(f));
	long long ret=0,temp;
	for (int k=1; k<=n+m; k++){
		for (int i=0,j=k; i<=n; i++,j--){
			if (j>m) continue;
			for (int x=0; x<i; x++){
				for (int y=0; y<j; y++){
					temp=Bsum[FA[i].y][j]-Bsum[FA[i].y][y];
					temp=min(temp,Asum[FA[i].y][i]-Asum[FA[i].y][x]);
					f[i][j]=max(f[i][j],f[x][y]+temp);
					ret=max(ret,f[i][j]);
				}
			}
		}
	}
	cout<<ret<<endl;
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>ca;
	for (int i=1; i<=ca; i++){
		cout<<"Case #"<<i<<": ";
		init();
		solve();
	}
	return 0;
}

