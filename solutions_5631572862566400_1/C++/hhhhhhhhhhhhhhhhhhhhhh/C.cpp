#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

const int N=1010;
int ring[N],idx_of_ring;
int f[N];
bool vis[N];
vector<int> mx;
int tot_node[N];
int realmx[N];

void init(){
	memset(ring,0,sizeof(ring));
	idx_of_ring=0;
	
	mx.clear();
	memset(tot_node,0,sizeof(tot_node));
	memset(realmx,0,sizeof(realmx));
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		int n;
		scanf("%d",&n);
		init();
		
		for(int i=0;i<n;i++){
			scanf("%d",&f[i]);
			f[i]--;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(ring[i])continue;
			memset(vis,0,sizeof(vis));
			int j=i;
			int tot=0;
			for(;!vis[j];j=f[j]){
				vis[j]=true;
				tot++;
			}
			if(j==i){
				ans=max(ans,tot);
				memset(vis,0,sizeof(vis));
				j=f[i];
				idx_of_ring++;
				for(;!vis[j];j=f[j]){
					vis[j]=true;
					ring[j]=idx_of_ring;
				}
				tot_node[idx_of_ring]=tot;
			}
		}
		
		for(int i=0;i<n;i++){
			memset(vis,0,sizeof(vis));
			if(ring[i])continue;
			int j=i;
			int tot=0;
			for(;!vis[j]&&!ring[j];j=f[j]){
				vis[j]=true;
				tot++;
			}
			if(ring[j]){
				realmx[j]=max(realmx[j],tot);
			}
		}
		for(int i=0;i<n;i++){
			if(ring[i]&&2==tot_node[ring[i]]){
				mx.push_back(realmx[i]);
			}
		}
		sort(mx.begin(),mx.end());
		//for(int i=0;i<mx.size();i++){
		//	printf("%d ",mx[i]);
		//}
		//puts("");
		
		int sum=0;
		for(int i=0;i<mx.size();i++){
			sum+=mx[i];
		}
		for(int i=1;i<=idx_of_ring;i++){
			if(tot_node[i]!=2)continue;
			sum+=tot_node[i];
		}
		ans=max(ans,sum);
		printf("Case #%d: %d\n",_,ans);
	}
	return 0;
}