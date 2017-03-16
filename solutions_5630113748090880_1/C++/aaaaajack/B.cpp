#include<bits/stdc++.h>
#define N 60
using namespace std;
int l[N*2][N];
int main(){
	int T;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++){
		int n,mx[2],ans[N];
		bool del[N*2]={};
		scanf("%d",&n);
		for(int i=0;i<n*2-1;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&l[i][j]);
			}
		}
		for(int i=0;i<n;i++){
			multiset<int> fst;
			mx[0]=-1;
			mx[1]=-1;
			for(int j=0;j<n*2-1;j++){
				if(del[j]) continue;
				if(mx[0]<0||l[j][i]<l[mx[0]][i]){
					mx[0]=j;
					mx[1]=-1;
				}
				else if(l[j][i]==l[mx[0]][i]){
					mx[1]=j;
				}
				fst.insert(l[j][i]);
			}
			if(mx[1]<0){
				for(int j=i+1;j<n;j++){
					fst.erase(fst.find(l[mx[0]][j]));
				}
				for(int j=i;j<n;j++){
					ans[j]=*fst.begin();
					fst.erase(fst.begin());
				}
				break;
			}
			else{
				for(int j=i;j<n;j++){
					auto it=fst.find(l[mx[0]][j]);
					if(it==fst.end()){
						ans[i]=l[mx[0]][j];
						break;
					}
					else fst.erase(it);
					it=fst.find(l[mx[1]][j]);
					if(it==fst.end()){
						ans[i]=l[mx[1]][j];
						break;
					}
					else fst.erase(it);
				}
				del[mx[0]]=del[mx[1]]=true;
			}
		}
		printf("Case #%d:",cs);
		for(int i=0;i<n;i++){
			printf(" %d",ans[i]);
		}
		puts("");
	}
	return 0;
}