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

int n,v[55],p[55],k,s,f[6333][131],u;
double ans,o[6333];
char c[55];

bool per(double x,double y,double xx,double yy){
	return max(x,xx)+1e-9<min(y,yy);
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int t=0;
	cin >> t;
	for (int e=1;e<=t;e++){
		cin >> n;
		for (int i=0;i<n;i++){
			cin >> c[i] >> v[i] >> p[i];
		}
		k=0;
		ans=0;
		o[k++]=0;
		o[k++]=1e9+1;
		for (int i=0;i<n;i++)for (int j=0;j<n;j++)if (v[i]>v[j]&&p[i]+5<=p[j])o[k++]=(p[j]-p[i]-5)/1./(v[i]-v[j]);
		sort(o,o+k);
		s=0;
		for (int i=0;i<n;i++)if (c[i]=='R')s+=pw(i);
		m0(f);
		f[0][s]=1;
		for (int i=0;i<k;i++){
			for (int j=0;j<pw(n);j++)if (f[i][j]){
				ans=o[i];
				for (int l=0;l<pw(n);l++){
					int gg=0;
					for (int h=0;h<n;h++)for (int hh=0;hh<n;hh++)
					if (h!=hh&&(l&pw(h))&&per(p[h],p[h]+5,p[hh],p[hh]+5))gg=1;
					u=j^l;
					for (int h=0;h<n;h++)for (int hh=0;hh<n;hh++)
					if (h!=hh&&((u&pw(h))>0)==((u&pw(hh))>0)&&v[h]>v[hh]&&fabs(p[h]+5-p[hh])<1e-9)gg=1;
					if (gg)continue;
					f[i+1][u]=1;
				}
			}
			for (int j=0;j<n;j++)p[j]+=v[j]*(o[i+1]-o[i]);

		}
		cout << "Case #" << e << ": ";
		if (ans>1e9)puts("Possible");else printf("%.5lf\n",ans);
	}
	return 0;
}


