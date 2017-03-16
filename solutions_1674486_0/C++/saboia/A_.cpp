//...
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <list>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n;
vector<int> v[55];
int ok[1010], c;
bool rec(int x){
	if(!ok[x]){
		ok[x]=c;
		// printf("%d %d\n", x, c);
		bool z=1;
		for(int i=0;i<v[x].size()&&z;++i){
			int y=v[x][i];
			if(i)++c;
			z=rec(y);
		}
		return z;
	}
	else {
		// printf("%d %d %d\n", x, c, ok[x]);
		return ok[x]==c;
	}
	
}
int main (){
	int t;
	scanf("%d", &t);
	for(int caso=1;caso<=t;++caso){
		scanf("%d", &n);
		for(int a=1;a<=n;++a){
			v[a].clear();
			int k, b;
			scanf("%d", &k);
			for(int i=0;i<k;++i){
				scanf("%d", &b);
				v[a].push_back(b);
			}
		}
		bool ans=1;
		for(int e=1;e<=n&&ans;++e){
			memset(ok,0,sizeof(ok));
			c=1;
			ans=rec(e);
		}
		
		if(ans)printf("Case #%d: No\n", caso);
		else printf("Case #%d: Yes\n", caso);
		
		
	}
	return 0;
}
