#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n,a[1005];
vector<int> v[1005];
int have[1005],huan[1005],lian[1005];
int ans,get;

void dealhuan(int x){
	int now=x;
	int l=1;
	while(a[now]!=x){
		now=a[now];
		l++;
	}
	now=x;
	ans=max(ans,l);
	while(a[now]!=x){
		huan[now]=l;
		now=a[now];
	}
}
void deal(int x){
	int now=x;
	int l=0;
	cout<<x<<endl;
	while(have[now]==0){
		cout<<now<<endl;
		have[now]=x;
		now=a[now];
	}
	if(have[now]==x) dealhuan(now);
}
int  deallian(int x){
	int ret=0;
	for (int i=0;i<v[x].size();i++){
		int tmp=v[x][i];
		if(huan[tmp]<=2&&a[a[x]]!=tmp){
			if(lian[tmp]==0){
				lian[tmp]=deallian(tmp);
			}
			ret=max(ret,lian[tmp]);
		}
	}
	return ret+1;
}
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) v[i].clear();
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			v[a[i]].push_back(i);
		}
		ans=0;
		memset(have,0,sizeof(have));
		memset(huan,0,sizeof(huan));
		for (int i=1;i<=n;i++){
			if(have[i]==0){
				deal(i);
			}
		}
		
		for (int i=1;i<=n;i++){
			cout<<i<<' '<<huan[i]<<endl;
			if(huan[i]<=2&&lian[i]==0){
				lian[i]=deallian(i);
			}
		}
		get=0;
		for (int i=1;i<=n;i++){
			cout<<i<<' '<<lian[i]<<endl;
			if(a[a[i]]==i){
				get+=lian[i]+lian[a[i]];
			}
		}
		get/=2;
		ans=max(ans,get);
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}
