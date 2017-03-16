#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> in;

int gao(int a,int n){
	int res=0;
	for(int i=0; i<n; ++i){
		while(a<=in[i]){
			if(a==1) return 1000000;
			a+=(a-1); ++res;
		}
		a+=in[i];
	}
	return res;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,a,n,tmp;
	scanf("%d",&T);
	for(int cas=1; cas<=T; ++cas){
		in.clear();
		scanf("%d%d",&a,&n);
		for(int i=0; i<n; ++i){
			scanf("%d",&tmp);
			in.push_back(tmp);
		}
		sort(in.begin(),in.end());
		int ans=100000;
		for(int i=0; i<=n; ++i){
			int tmp=i+gao(a,n-i);
			ans=min(ans,tmp);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
}