#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define y1 y1_
#define ran() (rand()<<15|rand())

const int mo=(int)1e9+7,inf=(int)1e9;
const ll linf=(ll)1e18;

int C,D,V;
int d[115];
int f[105][40];

int Main(){
	scanf("%d%d%d",&C,&D,&V);
	for(int i=0;i<D;i++) scanf("%d",&d[i]);
	sort(d,d+D);
	reverse(d,d+D);
	for(int i=0;i<=D;i++)
		for(int j=0;j<40;j++)
			f[i][j]=V;
	for(int i=0;i<D;i++){
		for(int j=0;j<40;j++){
		//	if(j<5) printf("f[%d][%d]=%d\n",i,j,f[i][j]);
			int now=f[i][j];
			for(int k=0;j+k<40;k++){
				f[i+1][j+k]=min(1LL*f[i+1][j+k],max(d[i]-1LL,now-1LL*d[i]*C));
				now=(now+1)/(C+1)+bool((now+1)%(C+1))-1;
			}
		}
	}
	int ans=1000;
	for(int j=0;j<40;j++){
		int now=f[D][j],cnt=j;
		while(now){
			now=(now+1)/(C+1)+bool((now+1)%(C+1))-1,cnt++;
		//	printf("j=%d now=%d\n",j,now);
		}
		ans=min(ans,cnt);
	}
	return ans;
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("C.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++)
		printf("Case #%d: %d\n",Case,Main());
	scanf("\n");
}
