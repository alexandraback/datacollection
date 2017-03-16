#include <iostream>
#include <cmath>
using namespace std;
int main()
{
//	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,t,n,s,p,ans,score[101];
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d%d%d",&n,&s,&p);
		ans = 0;
		for(j=0;j<n;j++){
			scanf("%d",&score[j]);
			if(score[j]>=p*3-2)ans++;
			else if((p>1&&score[j]>=p*3-4)&&s){
				ans++;s--;
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}