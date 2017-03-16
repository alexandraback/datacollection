#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int T,j,p,s,k;
int msk;
int per[15];
int now=0;
int popc(int k)
{
	int ret=0;
	while(k)
	{
		if(k&1) ret++;
		k>>=1;
	}
	return ret;
}
void getn()
{
	memset(per,0,sizeof(per));
	while(true)
	{
		if(popc(now)==msk)
		{
			int t=now,i=0,ele=s;
			while(t)
			{
				if(t&1) {
					per[i++]=ele;
					//printf("ele %d\n",ele);
				}
				t>>=1;
				ele--;
			}
			now++;
			return;
		}
		now++;
	}
}
int main()
{
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++)
	{
		scanf("%d%d%d%d",&j,&p,&s,&k);
		int jp=j*p;
		msk=min(s,k);
		printf("Case #%d: %d\n",cases,msk*jp);
		now=0;
		int sh=0;
		for(int i=0;i<jp;i++)
		{
			//getn();
			int tt1=0,tt2=0;
			int pp=1;
			while((1LL*pp*p)<(1LL*i)) pp*=p,tt1++;
			tt2=i-pp+1;
			for(int j=0;j<msk;j++)
			{
				printf("%d %d %d\n",tt1+1,tt2+1,(j+sh)%s+1);
				//printf("%d %d %d\n",tt1+1,tt2+1,per[j]);
			}
			sh++;
		}
	}
	return 0;
}
