#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ex[10];
int main(int argc, char const *argv[])
{
	int t,n;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++){
		scanf("%d",&n);
		if (n==0){
			printf("Case #%d: INSOMNIA\n",TT);
			continue;
		}
		memset(ex,0,sizeof(ex));
		int cnt=10;
		for (int i=1;;i++){
			int k=n*i;
			while(k){
				if (ex[k%10]==0){
					ex[k%10]=1;
					cnt--;
				}
				k/=10;
			}
			if (cnt==0){
				printf("Case #%d: %d\n",TT,n*i );
				break;
			}
		}
	}
	return 0;
}