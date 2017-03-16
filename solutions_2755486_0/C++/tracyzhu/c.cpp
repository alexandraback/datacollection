#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int OFFSET = 500;
struct Node{
	int w,e,s;
	Node(int _l,int _r,int _s){
		w=_l;e=_r;s=_s;
	}
};
int h[1000+5];
vector<Node>Day[676060+5];
int main(){
	int T,cas=0;
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int Maxd = 0;
		memset(h,0,sizeof(h));
		for(int i = 0;i < n;i++) {
			int di,ni,w,e,s,d_di,d_pi,d_s;
			scanf("%d%d%d%d%d%d%d%d",&di,&ni,&w,&e,&s,&d_di,&d_pi,&d_s);
			for(int j = 0;j < ni;j++){
				Day[di].push_back(Node(w,e,s));
			//	printf("w:%d e:%d s:%d\n",w,e,s);
				Maxd = max(Maxd,di);
				di = di + d_di;
				
				w += d_pi;e += d_pi;
				s += d_s;
			}
		}
		int ans = 0;
		//printf("%d\n",Maxd);
		for(int i = 0;i <= Maxd;i++) {
			/*if(i == 5){
				printf("fuck\n");
				for(int j = 1;j <= 10;j++){
					printf("%d ",h[j+OFFSET]);
				}
				printf("\n");
				}*/
			if(Day[i].size() == 0) continue;
			else{
				for(int j = 0;j < Day[i].size();j++) {
					int w = Day[i][j].w,e = Day[i][j].e;
					int f = 0;
					for(int k = w;k < e;k++) {
						if(h[k+OFFSET] < Day[i][j].s){
							f = 1;break;
						}
					}
					ans += f;
				}
				// ipdate height
				for(int j = 0;j < Day[i].size();j++) {
					int w = Day[i][j].w,e = Day[i][j].e;
					int f = 0;
					for(int k = w;k < e;k++) {
						h[k+OFFSET] = max(h[k+OFFSET],Day[i][j].s);
					}
				}
				Day[i].clear();
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}