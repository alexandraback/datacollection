#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define ii pair<int, int>

using namespace std;

int flag[10000005];

int main() {
	int ntc,a,b,x,jum,pjg;
	char kal[105];
	scanf("%d",&ntc);
	memset(flag,0,sizeof(flag));
	for (int tc=1;tc<=ntc;tc++) {
		scanf("%d %d",&a,&b);
		jum=0;
		sprintf(kal,"%d",a);
		pjg=strlen(kal);
		int mod=1;
		for (int i=0;i<pjg-1;i++) mod*=10;
		for (int i=a;i<=b;i++) {
			sprintf(kal,"%d",i);
			x=i;
			map <int, int> mp;
			for (int k=0;k<pjg;k++) {
				x=(x%mod)*10+(kal[k]-'0');
				
				if (x>=a && x<=b && x!=i) {
					if (flag[x]==0) {jum++;flag[x]=1;}
				}
			}
			//reset flag
			x=i;
			for (int k=0;k<pjg;k++) {
				x=(x%mod)*10+(kal[k]-'0');
				if (x>=a && x<=b && x!=i) {
					flag[x]=0;
				}
			}	
		}
		
		printf("Case #%d: %d\n",tc,jum/2);
	}
	
    return 0;
}
