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

int main() {
	int ntc,a,b,x,jum,pjg;
	char kal[105];
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++) {
		scanf("%d %d",&a,&b);
		jum=0;
		sprintf(kal,"%d",a);
		pjg=strlen(kal);
		for (int i=a;i<=b;i++) {
			sprintf(kal,"%d",i);
			map <int, int> mp;
			for (int j=1;j<pjg;j++) {
				int pos=j;
				x=0;
				for (int k=0;k<pjg;k++) {
					x=x*10+(kal[pos]-'0');
					if (pos+1==pjg) pos=0; else pos++;
				}

				if (x>=a && x<=b && x!=i) {
					if (mp.count(x)==0) {jum++; mp[x]=1;}
				}
			}
		}
		
		printf("Case #%d: %d\n",tc,jum/2);
	}
    return 0;
}
