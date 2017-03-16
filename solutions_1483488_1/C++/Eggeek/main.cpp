#include<stdio.h>
#include<string.h>
#define maxn 2000010
int a,b,cnt;
int vis[maxn];
int get_rec(int num)
{
	int bit=0,res=0;
	int tmp=num,p=1;
	while(tmp)
		bit++,tmp/=10,p*=10;
	tmp=num;p/=10;
	while(bit--)
	{
		if (tmp>=a && tmp<=b && !vis[tmp])
			vis[tmp]=1,res++;
		tmp=(tmp%p)*10+(tmp/p);
	}
	return res;
}
int c(int big)
{
	if (big<=1)return 0;
	return big*(big-1)/2;
}
void statis()
{
	int i,t;
	for(i=a;i<=b;i++)
	{
		t=get_rec(i);
		cnt+=c(t);
	}
}
int main()
{
	int cases,i;
	freopen("test.txt","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&cases);
	for(i=1;i<=cases;i++)
	{
		printf("Case #%d: ",i);
		scanf("%d%d",&a,&b);
		cnt=0;
		statis();
		printf("%d\n",cnt);
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
