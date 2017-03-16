#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define debug(x) cout<<#x<<'='<<x<<endl;
int main(){
	int T,x,y;
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	// EWSN
	scanf("%d",&T);
	int cas=1;
	while(T--){
		scanf("%d %d",&x,&y);
		printf("Case #%d: ",cas++);
		for(int i=0;i<abs(x);i++)printf(x>0?"WE":"EW");
		for(int i=0;i<abs(y);i++)printf(y>0?"SN":"NS");
		printf("\n");
	}
}
