#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
set<int>ss;
int s[4];
int T,R,N,M,K;
vector<int> hash[1010];
void init(){
	for(int i=0;i<(4*4*4);i++){
		int n=i;
		int num=0;
		hash[i].push_back(s[n%4]);n/=4;
		hash[i].push_back(s[n%4]);n/=4;
		hash[i].push_back(s[n%4]);n/=4;
	}
}
bool check(int kk){
	set<int>cao;
	for(int i=0;i<(1<<3);i++){
		int num=1;
		for(int j=0;j<3;j++)
			if(i&(1<<j))num*=hash[kk][j];
		if(ss.count(num))cao.insert(num);
	}
	return cao.size()==ss.size();
}
int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	s[0]=2,s[1]=3,s[2]=4,s[3]=5;
	init();
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		scanf("%d%d%d%d",&R,&N,&M,&K);
		printf("Case #%d:\n",cas);
		for(int i=1;i<=R;i++){
			ss.clear();
			for(int j=1;j<=K;j++){
				int x;
				scanf("%d",&x);
				if(x!=1)ss.insert(x);
			}
			bool flag=0;
			for(int j=0;j<4*4*4&&!flag;j++){
				if(check(j)){
					flag=1;
					for(int k=0;k<3;k++){
						printf("%d",hash[j][k]);
					}
					puts("");
				}
			}
//			if(flag)puts("find");
			if(!flag){
				int mm=rand()%(4*4*4);
				for(int j=0;j<3;j++)
					printf("%d",hash[mm][j]);
				puts("");
			}
		}
	}
	return 0;
}
