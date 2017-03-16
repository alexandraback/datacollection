#include<stdio.h>
#include<algorithm>

using namespace std;

class level_t{
public:
	int os, ts;
};
level_t lv[1000];
class cmp{
public:
	bool operator()(const level_t l1, const level_t l2){
		if(l1.os < l2.os){
			return true;
		} else if(l1.os == l2.os && l1.ts > l2.ts){
			return true;
		} else{
			return false;
		}
	}
};

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,T,n;
	scanf("%d\n",&T);
	for(t=0;t<T;t++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d",&lv[i].os, &lv[i].ts);
		}
		//sort(lv, lv+n, cmp());
		int cs = 0;
		int ans = 0;
		int flag = 0;
		int chk = -1;
		while(cs != 2*n){
			flag = 0;
			chk = -1;
			for(int j=0;j<n;j++){
				if(lv[j].ts == -1 && lv[j].os == -1) continue;
				if(lv[j].ts <= cs && lv[j].os != -1){
					flag = 3;
					chk = j;
					break;
				}
				if(flag < 3 && lv[j].os == -1 && lv[j].ts <= cs){
					flag = 2;
					chk = j;
				}
				if(flag < 2 && lv[j].os <= cs && lv[j].os != -1){
					if(chk == -1){
						flag = 1;
						chk = j;
					}
					else if(lv[j].ts > lv[chk].ts){
						flag = 1;
						chk = j;
					}
				}
			}
			if(flag == 0){
				cs = -1;
				break;
			}
			if(flag == 3){
				cs = cs + 2;
				lv[chk].ts = -1;
				lv[chk].os = -1;
			} else if(flag == 2 || flag == 1){
				cs = cs + 1;
				lv[chk].os = -1;
				if(flag == 2){
					lv[chk].ts = -1;
				}
			}
			ans = ans + 1;
		}
		if(cs == -1){
			printf("Case #%d: Too Bad\n",t+1);
		} else{
			printf("Case #%d: %d\n",t+1,ans);
		}
	}
	return 0;
}