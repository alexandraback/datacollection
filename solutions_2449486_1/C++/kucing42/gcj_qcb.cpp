#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm> 
#include <iostream>
#include <cmath>
using namespace std;
int n,m,t,a[200][200];
int mr[200],mc[200];
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&t);
	int tc = 0;
	while (tc < t){
		printf("Case #%d: ",++tc);
		scanf("%d %d",&n,&m);
		memset(mr,0,sizeof(mr));
		memset(mc,0,sizeof(mc));
		for (int i= 0; i <n; ++i)
			for (int j = 0; j < m; ++j){
				scanf("%d",&a[i][j]);
				mr[i] = max(mr[i],a[i][j]);
				mc[j] = max(mc[j],a[i][j]);
			}
		bool lol = 1;
		for (int i = 0; i <n; ++i)
			for (int  j = 0; j <m; ++j){
				if (mr[i] > a[i][j] && mc[j] > a[i][j])
					lol = 0;
			}
		if (lol) puts("YES");
		else puts("NO");
	}
}