#include<cstdio>
using namespace std;
int main()
{
	int T,n,s,p,score,c,d,ans,tmp,TT;
	scanf("%d",&T);
	TT=T;
	while(T--){
		scanf("%d%d%d",&n,&s,&p);
		c=p*3-2;
		d=p==1?1:p*3-4;
		ans=0;tmp=0;
		for(int i=0;i<n;i++){
			scanf("%d",&score);
			if(score>=c)
				ans++;
			else if(score>=d)
				tmp++;
		}
		ans+=s<tmp?s:tmp;
		printf("Case #%d: %d\n",TT-T,ans);
	}
	return 0;
}