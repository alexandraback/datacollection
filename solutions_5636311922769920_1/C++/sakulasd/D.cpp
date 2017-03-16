#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,k,c,s;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++){
		scanf("%d%d%d",&k,&c,&s);
		if (c*s<k){
			printf("Case #%d: IMPOSSIBLE\n",TT );
			continue;
		}
		printf("Case #%d:",TT );
		int now=0;
		for (int i=0;i<s;i++){
			long long p=now+1;
			now++;
			for (int j=0;j<c-1;j++){
				now++;
				p=(p-1)*s+min(now,k);
			}
			printf(" %I64d", p );
			if (now>=k) break;
		}
		printf("\n");
	}
	return 0;
}