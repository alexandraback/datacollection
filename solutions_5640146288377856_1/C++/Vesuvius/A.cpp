#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		int R,C,W;
		scanf("%d %d %d",&R,&C,&W);
		int count=(C/W)*R;
		if (C%W!=0) ++count;
		printf("Case #%d: %d\n",z,count+W-1);
	}
}
