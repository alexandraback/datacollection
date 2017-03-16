#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
pair<int,int> lev[1012];
bool f[1012];
int main(){
	//freopen("bs.in","r",stdin);
	//freopen("bs.out","w",stdout);
	int T,tt;
	int N;
	int i,j;
	scanf("%d",&T);
	for(tt=1;tt<=T;++tt){
		int res=0;
		int star=0;
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d%d",&(lev[i].second),&(lev[i].first));
			f[i]=false;
		}
		sort(lev,lev+N);
		for(i=0;i<N;i++){
			if(star>=lev[i].first){
				star+=f[i]?1:2;
				res++;
			}else if(star+1>=lev[i].first){
				for(j=N-1;j>i;j--){
					if(!f[j]&&star>=lev[j].second){
						f[j]=true;
						star+=3;
						res+=2;
						break;
					}
				}
				if(j==i&&star>=lev[i].second){
					star+=2;
					res+=2;
				}else if(j==i&&star<lev[i].second){
					break;
				}
			}else{
				break;
			}
		}
		if(i==N)
			printf("Case #%d: %d\n",tt,res);
		else
			printf("Case #%d: Too Bad\n",tt);
	}
	return 0;
}