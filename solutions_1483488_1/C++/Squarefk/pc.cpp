#include <cstdio>

using namespace std;

int times,l,r,ans,top,cut[10],list[10];

void work(int k)
{
	top=1;list[1]=k;
	cut[0]=0;
	while (k)
	{
		cut[++cut[0]]=k%10;
		k=k/10;
	}
	for (int i=cut[0]-1;i>=1;--i)
	{
		int temp=0;
		for (int j=1;j<=cut[0];++j)
			if (i-j+1>=1) temp=temp*10+cut[i-j+1];
			else temp=temp*10+cut[i-j+1+cut[0]];
		bool can=true;
		if ((temp<l)||(r<temp)) can=false;
		if (list[1]>=temp) can=false;
		for (int i=1;i<=top;++i)
			if (list[i]==temp) can=false;
		if (can) list[++top]=temp;
	}
	ans+=top-1;
}

int main()
{
	scanf("%d",&times);
	for (int t=1;t<=times;++t)
	{
		scanf("%d%d",&l,&r);
        ans=0;
		for (int i=l;i<=r;++i) work(i);
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
