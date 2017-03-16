#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) int((a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int n,a[1100][2];
II t[4000];
bool vi[1100];

bool cmp(II p, II q){ return a[p.fi][p.se]<a[q.fi][q.se]; }

int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
		
	int T; cin>>T;
	Rep(tt,1,T){
		scanf("%d",&n); int m=0;
		Rep(i,1,n) Rep(o,0,1) scanf("%d",&a[i][o]), t[++m]=mk(i,o);
		
		sort(t+1,t+m+1,cmp);
		
		int ans=n, now=0;
		memset(vi,0,sizeof(vi));
		
		Rep(i,1,m){
			if (t[i].se==0)				
				continue;
			
			while (now<a[t[i].fi][t[i].se]){
				int ret=-1;
				Rep(j,1,i-1)
					if (t[j].se==0 && !vi[t[j].fi] && now>=a[t[j].fi][0])
						if (ret==-1 || a[t[j].fi][1]>a[t[ret].fi][1])
							ret=j;
				if (ret==-1)
					break;
				now++;
				ans++;
				vi[t[ret].fi]=1;
			}
			if (now<a[t[i].fi][t[i].se]){
				ans=-1;
				break;
			}
			
			if (vi[t[i].fi])
				now++; else now+=2;
			vi[t[i].fi]=1;
		}
		
		printf("Case #%d: ",tt);
		if (ans==-1)
			puts("Too Bad");
		else
			printf("%d\n",ans);
	}

    return 0;
}
