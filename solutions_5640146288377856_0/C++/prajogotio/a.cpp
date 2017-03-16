#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;






int main(){

	int TC;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;++tc){
		printf("Case #%d:", tc);

		int R,C,W;
		scanf("%d%d%d",&R,&C,&W);
		int ans = (C-W)/W;
		printf(" %d\n",ans+W+( C%W> 0 ? 1 : 0));

	}
	return 0;
}