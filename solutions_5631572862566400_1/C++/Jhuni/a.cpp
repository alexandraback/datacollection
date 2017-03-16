#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const int INF 2147483647;
//const int mod 1000000007;

int root[1111];

int find(int i){
	if(root[i]==i)return i;
	return root[i]=find(root[i]);
}
void uni(int a,int b){
	a=find(a);
	b=find(b);
	root[a]=b;
}
int T;
int main(){
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){
		printf("Case #%d: ",TT);
		
		int n;
		int ans=0;
		int f[1111];
		int d[1111];
		int dd[1111];
		int l[1111];
		int mx=0;
		vector<int> v[1111];
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			
			root[i]=i;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&f[i]);
			uni(i,f[i]);
		}
		
		for(int i=1;i<=n;i++){
			for(int i=1;i<=n;i++){
				d[i]=0;
			}
			int k=i;
			int c=0;
			while(d[f[k]]==0){
				d[k]=1;
				c++;
				k=f[k];
			}
			dd[i]=k;
			l[i]=c+1;
		}
		
		for(int i=1;i<=n;i++){
			v[find(i)].push_back(i);
		}
		int mx2=0;
		for(int i=1;i<=n;i++){
			mx=0;
			int s = v[i].size();
			
			for(int j=0;j<s;j++){
				for(int ii=0;ii<s;ii++){
					int p,q;
					p=v[i][j];
					q=v[i][ii];
					if(p!=q){
						if(f[dd[p]]==dd[q]&&f[dd[q]]==dd[p]){
							mx=max(mx,l[p]+l[q]-2);
							//printf("%d " ,mx);
						}
						if(f[dd[p]]==p){
							mx2=max(mx2,l[p]);
							//printf("%d. ",l[p]);
						}
					}
				}
				int p=v[i][j];
				if(f[dd[p]]==p){
							mx2=max(mx2,l[p]);
							//printf("%d. ",l[p]);
						}
			}
			ans+=mx;
		}
		printf("%d\n",ans<mx2?mx2:ans);
		
	}
}