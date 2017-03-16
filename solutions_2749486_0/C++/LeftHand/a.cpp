#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=1<<29;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,x,y,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",ri++);
		for(int i=0;i<abs(x);i++){
			if(x>0){
				printf("WE");
			}else printf("EW");
		}
		for (int i = 0; i < abs(y); i++) {
			if (y > 0) {
				printf("SN");
			} else
				printf("NS");
		}
		puts("");
	}
}
