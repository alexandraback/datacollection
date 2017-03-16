
#include <cstdio>
#include <algorithm>
using namespace std;

char buf [1<<20];

int main()
{
	int cs = 0, T=0;
	scanf("%d",&T);
	while(++cs <= T){
	
		int n, sum = 0, ct = 0, res = 0;
		scanf("%d%s",&n,buf);
		for(int i=0;i<=n;++i){
			if(buf[i]!='0') {
				res = max(res, i - sum);
			}
			sum += buf[i]-'0';
		}
	
		printf("Case #%d: %d\n", cs, res);
	}

	return 0;
}
