#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;
int times;
long long n,m,ty1[200],ty2[200],num1[200],num2[200],tnum[200];
int lis[5];
void mem()
{
	memset(lis,0,sizeof(lis));
}
long long search(int x,int y)
{
	long long now=0;
	long long t=0;
	if (x<n-1)
	{
		for (int b=y;b<=m;++b)
		{
			lis[x+1]=b;
			t=search(x+1,b);
			if (t>now)
			{
				now=t;
			}
		}
	}else
	{
		long long re=0;
		for (int a=1;a<=m;++a) tnum[a]=num2[a];
		for (int a=1;a<=n;++a)
		{
			long long all=num1[a];
		//	printf("%d,",lis[a]);
			for (int b=lis[a-1];b<=lis[a];++b)
			{
				
				if (ty1[a]==ty2[b])
				{
					if (tnum[b]<all)
					{
						all-=tnum[b];
						re+=tnum[b];
						tnum[b]=0;
					}else
					{
						tnum[b]-=all;
						re+=all;
						all=0;
						break;
					}
					
				}
			//	printf("<%d,%d:%d,%d = %d>",a,b,ty1[a],ty2[b],re);
			}
		}
	//	printf(":= %d\n",re);
		return re;
	}
	return now;
}
int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
//	scanf("%d",&times);
	cin>>times;
	for (int z=1;z<=times;++z)
	{
		cin>>n>>m;
//		scanf("%d%d",&n,&m);
		for (int a=1;a<=n;++a)
		{
			cin>>num1[a]>>ty1[a];
//			scanf("%d%d",&ty1[a],&num1[a]);
		}
		for (int a=1;a<=m;++a)
		{
			cin>>num2[a]>>ty2[a];
			//scanf("%d%d",&ty2[a],&num2[a])
		}
		printf("Case #%d: ",z);
		mem();
		lis[0]=1;
		lis[n]=m;
		cout<<search(0,0)<<endl;
//		printf("%d\n",search(0,0));
	}
}
