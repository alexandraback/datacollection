#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#include <sstream>

using namespace std;
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int t;cin >> t;
	for (int rt=1;rt<=t;rt++){
		int n,k,p;
		printf("Case #%d: ",rt);
		cin >> n >> k >> p;
		int x=p+p-1+p-1;
		int y=p+p-2+p-2;
		x=max(x,p);
		y=max(y,p);
		int a=0,b=0,c=0;
		for (int i=0;i<n;i++){
			int v;
			scanf("%d",&v);
			if (v>=x) a++;
			else if (v>=y) b++;
		}
		printf("%d\n",a+min(b,k));
	}
	return 0;
}
