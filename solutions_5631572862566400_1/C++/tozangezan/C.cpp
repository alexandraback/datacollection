#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int p[1100];
vector<int>rev[1100];
int dfs(int a,int b){
	int m1=0;
	int m2=-99999999;
	for(int i=0;i<rev[a].size();i++){
		if(rev[a][i]==b)continue;
		int tmp=dfs(rev[a][i],b);
		if(a==b&&p[a]==rev[a][i]){
			m2=tmp;
		}else if(tmp>m1){
			m1=tmp;
		}
	}
	if(a==b){
	//	printf("%d %d: %d\n",a,b,1+m1+m2);
		return 1+m1+m2;
	}
	//printf("%d %d: %d\n",a,b,m1+1);
	return m1+1;
}
int main(){
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a;scanf("%d",&a);
		for(int i=0;i<a;i++)rev[i].clear();
		for(int i=0;i<a;i++)scanf("%d",p+i);
		for(int i=0;i<a;i++)p[i]--;
		for(int i=0;i<a;i++)rev[p[i]].push_back(i);
		int ret=0;
		for(int i=0;i<a;i++){
			int at=i;
			int last=-1;
			for(int j=0;j<a;j++){
				last=at;
				at=p[at];
				if(at==i){
					ret=max(ret,j+1);
					break;
				}
			}
		}
		int val=0;
		for(int i=0;i<a;i++){
			if(p[i]>i&&p[p[i]]==i){
				val+=dfs(i,p[i])+dfs(p[i],i);
			}
		}
		ret=max(ret,val);
		printf("Case #%d: %d\n",t,ret);
	}
}