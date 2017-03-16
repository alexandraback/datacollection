#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <string.h>
#include <set>
using namespace std;
typedef __int64 LL;
vector<LL>E;
int main(){
	int n,t,cas=0;
	LL a;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);	
	while(t--){
		scanf("%I64d %d",&a,&n);
		E.clear();
		for(int i = 0;i < n;i++) {
			LL tmp;
			scanf("%I64d",&tmp);
			E.push_back(tmp);
		}
		sort(E.begin(),E.end());
		int ans = E.size(),cur = 0;
		for(int i = 0;i < E.size();i++) {
			int tmp = cur + E.size() - i;
			ans = min(ans,tmp);
			if(E[i] < a) {
				a = a + E[i];	
			}else{
				int cnt = 0;
				if(a == 1) {
					cur += E.size() - i;
					ans = min(ans,cur);
					break;
				}
				while(1){
					if(a>E[i])break;
					else{
						a = a + a - 1;
						cnt++;
					}
				}
				if(E.size() - i < cnt) {
					cur += E.size()-i;
					ans = min(ans,cur);
					break;
				}else{
					cur += cnt;
					a = a + E[i];
				}
			}
		}
		ans = min(ans,cur);
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}