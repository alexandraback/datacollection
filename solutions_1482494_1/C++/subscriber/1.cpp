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

int n,a[2222],b[2222],f[2222],o,ans,t,oo;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int T=0;
	cin >> T;
	for (int e=1;e<=T;e++){
		cin >> n;
		for (int i=0;i<n;i++)cin >> a[i] >> b[i];
		m0(f);
		o=0;
		ans=0;
		while (o<n+n){
			t=-1;
			for (int i=0;i<n;i++)if (f[i]<2&&b[i]<=o)t=i;
			if (t!=-1){
				ans++;
				o+=2-f[t];
				f[t]=2;
				continue;
			}
			oo=-1;
			for (int i=0;i<n;i++)if (f[i]==0&&a[i]<=o&&b[i]>oo)oo=b[i],t=i;
			if (t!=-1){
				ans++;
				o++;
				f[t]=1;
				continue;
			}
			ans=-1;
			break;
		}
		cout << "Case #" << e << ": ";
		if (ans==-1)puts("Too Bad");else CC(ans);
	}
	return 0;
}


