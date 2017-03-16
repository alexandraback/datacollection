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

int a,b,f[11222222],e[11];
long long ans=0;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	int t=0;
	cin >> t;
	for (int ee=1;ee<=t;ee++){
		cin >> a >> b;
		m0(f);
		ans=0;
		for (int i=a;i<=b;i++)if (!f[i]){
			int o=0,l=i,k=0,g;
			while (l){
				e[k++]=l%10;
				l/=10;				
			}
			for (int j=0;j<k;j++){
				g=0;
				for (int l=0;l<k;l++)g=g*10+e[(j-l+k)%k];
				if (!f[g]&&g>=a&&g<=b)o++;
				f[g]=1;				
			}
			ans+=o*1ll*(o-1)/2;
		}

		cout << "Case #" << ee << ": " << ans << endl;
	}
	return 0;
}


