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

int n,s,p,a[111],f[111][111];

int oo(int a,int b,int c){
	if (c<0||c>10)return 0;
	if (abs(a-c)>2||abs(b-c)>2)return 0;
	return 1+(abs(a-b)==2||abs(a-c)==2||abs(c-b)==2);

}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int t=0;
	cin >> t;
	for (int e=1;e<=t;e++){
		cin >> n >> s >> p;
		for (int i=0;i<n;i++)cin >> a[i];
		m0(f);
		for (int i=0;i<n;i++)for (int j=0;j<=s;j++)
		for (int x=0;x<11;x++)for (int y=max(0,x-2);y<min(11,x+3);y++)if (oo(x,y,a[i]-x-y))
		f[i+1][j+oo(x,y,a[i]-x-y)-1]=max(f[i+1][j+oo(x,y,a[i]-x-y)-1],f[i][j]+(max(a[i]-x-y,max(x,y))>=p));
		cout << "Case #" << e << ": " << f[n][s] << endl;
	}
	return 0;
}


